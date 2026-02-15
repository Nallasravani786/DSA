###### C O D E
```cpp
 static bool comp ( const vector<int>&val1, const vector<int>&val2){
       return val1[1] < val2[1] ;
    }
  
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size();
        if(n==0 || n==1) return true;
       sort(arr.begin(),arr.end(),comp);
       int endtime = arr[0][1];
       for(int i=1;i<n;i++){
         if(endtime <= arr[i][0]){
             endtime = arr[i][1];
         } 
         else return false;
       }
       return true; 
    }

```
