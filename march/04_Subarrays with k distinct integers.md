### I N T U I T I O N 

This code counts the number of subarrays with exactly k distinct elements.

Function f(arr, k) counts subarrays with at most k distinct elements using a sliding window.

For each right index r, all subarrays ending at r and starting from l to r are valid, so we add r − l + 1.

If distinct elements exceed k, the window is shrunk from the left.

Subarrays with exactly k distinct elements = (at most k) − (at most k−1).

This turns a hard “exactly” problem into two easy sliding-window problems in O(n) time.




###### C O D E 
```cpp
int f(vector<int> &arr, int k) {
       int n = arr.size();
       int l=0,r=0,cnt=0;
       unordered_map<int,int>hash;
       for(int r=0;r<n;r++){
           hash[arr[r]]++;
           
           while(hash.size()>k){
               hash[arr[l]]--;
               if(hash[arr[l]]==0) hash.erase(arr[l]);
              l++;
           }
           cnt += r-l+1;
       }
       return cnt;
    }
    int exactlyK(vector<int> &arr, int k){
        int n = arr.size();
        return f(arr,k)-f(arr,k-1);
    }
```
