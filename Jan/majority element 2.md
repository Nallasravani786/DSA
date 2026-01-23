Simple intuition:

If an element appears more than n/3 times, there can be at most two such elements.

We keep two candidates (val1, val2) and their counts to track possible majority elements.

When the current number matches a candidate, we increase its count.

If it matches neither and one count is zero, we replace that candidate.

Otherwise, we decrease both counts, canceling out different elements.

In the end, we verify the remaining candidates to ensure they actually appear more than n/3 times.


```cpp
bool g(vector<int>&nums,int val){
      int n = nums.size();
      int cnt =0;
      for(int i=0;i<n;i++){
          if(val == nums[i]) cnt++;
      }
      return cnt > n/3;
  }
  
    vector<int>  majorityElement(vector<int>& arr) {
        int val1 = arr[0];
        int val2 = arr[0];
        int n = arr.size();
        int cnt1 =0,cnt2 =0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(val1 == arr[i]) cnt1++;
            else if(val2 == arr[i]) cnt2++;
            else {
                if(cnt1 ==0){
                    val1 = arr[i];
                    cnt1 =1;
                }
                else if(cnt2 ==0){
                    val2 = arr[i];
                    cnt2 =1;
                }
                else {
                    cnt1--;
                    cnt2--;
                }
            }
        }
        
        if(g(arr,val1)!=0) ans.push_back(val1);
        if(val1!=val2 && g(arr,val2)!=0) ans.push_back(val2);
        return ans;
    }

```
