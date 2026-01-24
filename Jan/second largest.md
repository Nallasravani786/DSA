## I N T U T I O N ##
ntuition in a few simple points:

Keep track of two values while scanning the array:
largest and second largest.

When you find a number bigger than the largest:
→ the old largest becomes second largest.

When a number is smaller than largest but bigger than second largest:
→ update second largest.

Ignore all other numbers (they can’t affect the top two).

Do this in one pass, so it’s fast and efficient (O(n)).

👉 Final idea: Always maintain the best and second-best seen so far.

```cpp
 int getSecondLargest(vector<int> &arr) {
        int large =-1;
        int secondlarge = -1;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            
            if(arr[i] > large) 
             {
                 secondlarge = large;
                 large = arr[i];
             }
            else if( arr[i] < large && arr[i] > secondlarge){
                secondlarge = arr[i];
            }
        }
        return secondlarge;
        
    }
```

