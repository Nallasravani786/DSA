## I N T U T I O N ## 
Minimum difference will always be between nearby numbers, not far apart ones.

So first we sort the array to bring close numbers together.

Then we check only adjacent elements to find the smallest difference.

After knowing the minimum difference, we again check adjacent pairs.

Every pair having that minimum difference is added to the answer.

👉 Sorting helps reduce O(n²) checking to O(n) after sort.
```cpp
 vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int n =arr.size();
        vector<vector<int>>ans;
        vector<int>temp;
        int mini = INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
         mini = min(mini,arr[i+1]-arr[i]);
        }
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])== mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
       
        return ans;
    }
```
