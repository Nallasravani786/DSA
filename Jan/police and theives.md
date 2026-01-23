Intuition:

Store positions of police and thieves separately.

Use two pointers to try pairing the nearest police and thief.

If their distance is ≤ k, one catch is made and both move forward.

Otherwise, move the pointer of the one that is behind to find a closer match.

```cpp
int catchThieves(vector<char> &arr, int k) {
       int n = arr.size();
       vector<int>police,theif; 
       for(int i=0;i<n;i++){
           if(arr[i]=='P') police.push_back(i);
           else theif.push_back(i);
       }
      int p=0,t=0;
      int ans =0;
      while(p<police.size() && t<theif.size()){
         if(abs(police[p]-theif[t]) <=k ){
             p++;
             t++;
             ans++;
         }
         else if(police[p]<theif[t]){
             p++;
         }
         else t++;
      }
      return ans;  
    }

```
