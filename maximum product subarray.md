
Simple intuition:

The maximum product subarray can break when we hit a zero or when negative numbers flip the sign.

We do a left-to-right pass to get the best product ending at each position.

When the product becomes zero, we reset because any subarray beyond zero must start fresh.

We repeat the same logic right-to-left to handle cases where the maximum product starts after a negative number.

Taking the maximum from both passes ensures we capture the largest possible product subarray.

```cpp
int maxProduct(vector<int>& nums) {\
        int n = nums.size();
        int prod=1;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            maxi = max(prod,maxi);
           if(prod == 0) prod =1; 
        }
        prod = 1;

        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            maxi = max(prod,maxi);
            if(prod==0) prod =1;
        }
     return maxi;
    }
```
