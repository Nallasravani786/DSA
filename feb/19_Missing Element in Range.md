## I N T U I T I O N

      First, store all elements of arr in a set (or unordered_set).
      
      So checking whether a number exists becomes O(1).
      
      Then, simply:
      
      Loop from low to high
      
      If the number is NOT in the set
      → add it to answer
      
##### C O D E

```cpp
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
      unordered_set<int>st(arr.begin(),arr.end());
      vector<int>ans;
      for(int num = low ; num <= high; num++){
          if(st.find(num) == st.end()){ // If num is NOT present in the set
              ans.push_back(num);
          }
      }
      return ans;
       
    }
};
//gfg
```
###### TIME :: O(N + (high − low + 1))
######  SPACE ::O(N)
