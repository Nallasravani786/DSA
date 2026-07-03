###### C O D E

  for any integer array ( not only positive )
```cpp
 int getSecondLargest(vector<int> &arr) {
       int n = arr.size();
       int large = INT_MIN;
       int seclarge = INT_MIN;
       
       for(int i=0;i<n;i++){
           if(arr[i]>large){
               seclarge = large;
               large = arr[i];
           }
           
         else  if(arr[i]<large && arr[i] > seclarge) seclarge = arr[i];
           
       }
       return (seclarge == INT_MIN && large == INT_MIN) ? -1 : seclarge;
       
    }

```
