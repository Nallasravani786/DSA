###### C O D E
```cpp
int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        sort(a.begin(),a.end());
        int mini = INT_MAX;
        int i=0,j=m-1;
        while( i<=j && j<n){
             mini = min(a[j]-a[i],mini);
            i++;
            j++;
        }
       return mini; 
    }
    //GFG

```
