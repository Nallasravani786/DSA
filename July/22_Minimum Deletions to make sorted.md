###### C O D E
```cpp
 int minDeletions(vector<int>& arr) {
       vector<int>lis;
       
       for(int x:arr){
           auto pos = std::lower_bound(lis.begin(),lis.end(),x);
           
           if(pos == lis.end()) lis.push_back(x); // to find LIS without DP because Dp with O(n^2) T.C
           
           else *pos = x;
           
       }
       return arr.size() - lis.size(); // total_length -  length of Longest incresing subsequence 
    }

```
