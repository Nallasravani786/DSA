#### I M A G E 
<img width="2840" height="1294" alt="image" src="https://github.com/user-attachments/assets/69c28dff-ca41-4f24-8517-9673792b3d10" />

#### I N T U I T I O N 
dp[i] represents the length of the Longest Increasing Subsequence ending at index i.

We treat every element as the possible ending element of an increasing subsequence.

For each current element, we check all previous elements.

If arr[prev] < arr[ind], the current element can be attached to the previous increasing subsequence.

If 1 + dp[prev] > dp[ind], we found a better/longer subsequence, so we update dp[ind].

dp[] only stores the length, but the problem asks for the actual sequence too.

So we use hash[] to store the previous index used to build the subsequence.

We keep track of the maximum LIS length and the index where that LIS ends using maxi and lastIndex.

After finding the longest subsequence, we start from lastIndex and follow hash[] to reconstruct the sequence.

Since we collect elements from back to front, we reverse the result at the end to get the correct LIS order.


###### C O D E

```cpp
 vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
       
       vector<int>dp(n,1);
       
       vector<int>hash(n);
       
       for(int i=0;i<n;i++) hash[i] = i;
       
       int maxi = 0;
       int lastindex = 0;
       
       for(int ind=0;ind<n;ind++){
           
            for(int prev = 0;prev<ind;prev++){
                
                if(arr[prev] <arr[ind] && 1+dp[prev] > dp[ind]) {
                    dp[ind] = 1+dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind] > maxi){
                maxi = dp[ind];
                lastindex = ind;
              }
            }
            
       vector<int>ans;
       
       ans.push_back(arr[lastindex]);
       
       while(hash[lastindex] != lastindex){
           lastindex = hash[lastindex];
           ans.push_back(arr[lastindex]);
           
       }
       reverse(ans.begin(),ans.end());
       
       return ans;
        
    }

```
