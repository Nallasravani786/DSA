### I N T U I T I O N 
This code finds the maximum XOR of any subarray of size k using a sliding window.

First, it computes XOR of the first k-1 elements.

Then for every new element, it adds it to the window using XOR (^).

It updates the maximum XOR value.

Then it removes the leftmost element of the window using XOR again (since a ^ a = 0, XOR automatically cancels it).

So it maintains a running XOR of a fixed-size window in O(n) time instead of recomputing every subarray

###### C O D E 
```cpp
int maxSubarrayXOR(vector<int>& arr, int k) {
        int n =arr.size();
        int ans =0;
        int xorr =0;
        for(int i=0;i<k-1;i++){
            xorr^=arr[i];
        }
        for(int i=k-1;i<n;i++){
            xorr^=arr[i];
            ans = max(ans,xorr);
            xorr^=arr[i-k+1];
        }
        return ans;
        
    }
```
