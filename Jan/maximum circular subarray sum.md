## I N T U T I O N ##


A max subarray in a circular array is either normal or wraps around.

Use Kadane’s algorithm to find the maximum subarray sum.

At the same time, find the minimum subarray sum.

Circular sum = total array sum − minimum subarray sum.

Answer is the maximum of normal sum and circular sum
(if all numbers are negative, take only the normal sum).

```cpp
int maxCircularSum(vector<int> &arr) {
      int n = arr.size();
      int totsum  =0;
      int cmaxsum =0; 
      int cminsum =0;
      int omaxsum = arr[0];
      int ominsum = arr[0];
      
      for(int i=0;i<n;i++){
         
         cmaxsum = max(cmaxsum+arr[i],arr[i]);
         omaxsum = max(cmaxsum,omaxsum);
         
         cminsum = min(cminsum+arr[i] , arr[i]);
         ominsum = min(ominsum,cminsum);
         
         totsum +=  arr[i];
          
      }
      
      int normalsum = omaxsum ;
      int circularsum = totsum - ominsum;
      
      if(ominsum == totsum) return normalsum;
      
      return max(normalsum, circularsum);
        
    }
```
