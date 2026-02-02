## I N T U T I O N 
f_max (Kadane’s for max subarray):
It keeps a running sum (csum). If the current sum is helping (≥ 0), extend it; otherwise, start fresh from the current element. osum always stores the best max subarray sum seen so far.

f_min (Kadane’s for min subarray):
Same idea but reversed. If the current sum is hurting (≤ 0), extend it to get a smaller sum; otherwise, restart. This finds the minimum subarray sum.

totsum:
Just computes the total sum of the array elements.

Circular subarray idea:
A circular max subarray is equivalent to total sum − minimum subarray sum (we remove the worst middle part and take the rest in a circular way).

Edge case:
If all elements are negative, then totsum == f_min, and circular sum becomes 0 (invalid). So we return the normal max subarray sum.

Final answer:
Take the maximum of normal max subarray sum and circular max subarray sum

```cpp
int f_max(vector<int>&arr){
      int csum = arr[0];
      int osum = arr[0];
      
      for(int i=1;i<arr.size();i++){
          if(csum >=0) {
              csum+=arr[i];
              osum = max(osum,csum);
             }
          else {
          csum = arr[i];
          osum = max(osum,csum);
          }
        }
        return osum;
  }
  
  int f_min(vector<int>&arr){
      int csum = arr[0];
       int osum =arr[0];
       
       for(int i=1;i<arr.size();i++){
           if(csum<=0){
               csum+=arr[i];
               osum = min(csum,osum);
           }
           else {
               csum = arr[i];
               osum = min(csum,osum);
           }
       }
       return osum;
       
  }
  
  int totsum(vector<int>&arr){
      int sum=0;
      for(int i=0;i<arr.size();i++){
          sum+=arr[i];
      }
      return sum;
  }
 
    int maxCircularSum(vector<int> &arr) {
      int normalsum = f_max(arr);
      int circular_sum = totsum(arr)-f_min(arr);
      if(totsum(arr) == f_min(arr)) return normalsum;
      return max(normalsum,circular_sum);
        
    }

```
