Simple intuition:

The algorithm tries to cancel out different elements from the array.

When the counter is zero, we pick a new candidate for majority.

If the current element matches the candidate, we increase the count; otherwise, we decrease it, canceling one occurrence.

If a true majority element (> n/2 times) exists, it cannot be fully canceled, so it remains as the candidate at the end.

The final function g() is used to verify that this candidate is actually the majority element.

```cpp
 bool g(vector<int>&nums,int val){
      int n = nums.size();
      int cnt =0;
      for(int i=0;i<n;i++){
          if(val == nums[i]) cnt++;
      }
      return cnt >n/2;
  }
  
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int cnt1=0;
        int val1=0;
        for(int i =0 ; i<n;i++){
            if(val1 == arr[i]) cnt1++;
            
            else {
                if(cnt1 ==0){
                    val1 = arr[i];
                    cnt1 =1;
                }
                else{
                    cnt1--;
                }
            }
        }
        
      if(g(arr,val1)==true) return val1;
      return -1;
        
    }
```
