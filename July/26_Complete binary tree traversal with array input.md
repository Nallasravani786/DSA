###### C O D E
```cpp
vector<vector<int>> levelSort(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>ans;
        int i = 0;
        int levelsize = 1;
        
        while(i<n){
            
            vector<int>curr;  
            for(int cnt = 0;cnt<levelsize && i<n; cnt++){
                curr.push_back(arr[i]);
                i++;
            }    
            sort(curr.begin(),curr.end());
            ans.push_back(curr);
            levelsize*=2;
        }
        return ans;
    }

```
