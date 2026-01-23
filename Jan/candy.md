Intuition:          
                    Every child must get at least one candy, so we start by assigning 1 candy to everyone.
          
                    In the left-to-right pass, if a child has a higher rating than the previous one, they must get more candies than the previous child.
                    
                    In the right-to-left pass, we handle the opposite case: if a child has a higher rating than the next one, we ensure they get more candies than the next child, without breaking the earlier assignment.
                    
                    Taking the maximum in the second pass guarantees both left and right constraints are satisfied while keeping the total candies minimum.

```cpp
int minCandy(vector<int> &arr) {
        int n = arr.size();
        vector<int>candies(n,1);
        
        for(int i =1;i<n;i++){
            if(arr[i]>arr[i-1]){
                candies[i] = 1+ candies[i-1];
            }
        }
        int total =candies[n-1];
        for(int i = n-1;i>0;i--){
            if(arr[i-1]>arr[i]){
                candies[i-1]= max(1+candies[i],candies[i-1]);
            }
            total+=candies[i-1];
        }
        return total;
    }
```
