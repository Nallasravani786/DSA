#### I M A G E 

<img width="2847" height="1383" alt="image" src="https://github.com/user-attachments/assets/5535da7f-64a7-4351-8932-7a1a5710f14a" />

#### I N T U I T I O N
💡 Intuition (simple)
When object is created → constructor stores the array
sumRange(left, right) → loops from left to right
Adds all elements in that range
Returns the sum

``` cpp 
class NumArray {
public:
    vector<int> arr;   // store the array

    NumArray(vector<int>& nums) {
        arr = nums;    // save input
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++){
            sum += arr[i];   // use stored array
        }
        return sum;
    }
};
```
