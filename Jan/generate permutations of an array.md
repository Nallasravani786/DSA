## I N T U T I O N ##
We build the permutation one element at a time using recursion.

map keeps track of which elements are already used.

At each step, we pick an unused element, add it to ds, and go deeper.

When ds has all elements, it becomes one complete permutation.

After that, we backtrack by removing the last element and try other choices.
```cpp
void func(vector<int>&arr,vector<int>&map,vector<int>&ds , vector<vector<int>>&ans)
  {
      if(ds.size() == arr.size()) {
          ans.push_back(ds);
          return;
      } 
      
      for(int i=0;i<arr.size();i++){
          if(!map[i]){
              ds.push_back(arr[i]);
              map[i]=1;
              func(arr,map,ds,ans);
              map[i]=0;
              ds.pop_back();
          }
      }
  }
  
    vector<vector<int>> permuteDist(vector<int>& arr) {
        int n = arr.size();
       vector<vector<int>>ans;
       vector<int>map(n,0);
       vector<int>ds;
       func(arr,map,ds,ans);
       return ans;
    }

```
