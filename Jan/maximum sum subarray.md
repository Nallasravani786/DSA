Simple intuition:

csum keeps the current subarray sum ending at the current index.

If the current sum is positive, adding the next element can only help, so we extend the subarray.

If the current sum becomes negative, it will only reduce future sums, so we start a new subarray from the current element.

osum always stores the maximum sum seen so far.

By doing this in one pass, we get the maximum subarray sum efficiently (Kadane’s Algorithm).



```cpp
 int maxSubarraySum(vector<int> &arr) {
       int n = arr.size();
       int csum = arr[0];
       int osum = arr[0];
       
       for(int i=1;i<n;i++){
           if(csum>=0) {csum+=arr[i];
           osum = max(csum,osum);
       }
       
      else {    csum = arr[i];
         osum = max(csum,osum);
      }
      
           } 
         return osum;
        
    }
```
