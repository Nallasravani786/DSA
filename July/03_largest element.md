###### C O D E
```cpp
int largest(vector<int> &arr) {
        int maxi = arr[0];
        
        for(int i=1;i<arr.size();i++){
            if(arr[i] > maxi) maxi = arr[i];
        }
        return maxi;
    }
```
