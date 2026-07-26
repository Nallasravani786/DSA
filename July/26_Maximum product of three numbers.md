###### C O D E ( brute -> O(nlogn) )

```cpp
 int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int case1 = nums[0]*nums[1]*nums[n-1];
        int case2 = nums[n-1]*nums[n-2]*nums[n-3];

        return max(case1,case2);


```
###### C O D E ( optimal -> O(n) )

```cpp
 int maximumProduct(vector<int>&nums){
        int n = nums.size();
        int min1 = INT_MAX,min2 = INT_MAX,max1 = INT_MIN,max2 = INT_MIN,max3 = INT_MIN;

        for(int x:nums){
            if(x>max1){
                max = max2;
                max2 = max1;
                max1 = x;
            }
            else if(x <= max1 && x > max2){
                max3 = max2;
                max2 = x;
            }
            else if ( x<= max2 && x > max3){
                max3 = x;
            }
            
            if(x<min1){
                min2 = min1;
                min1 = x;
            }
            else if(x>= min1 && x< min2) {
                min2 = x;
            }
        }

        return max(min1*min2*max1,max1*max2*max3);
    }

```
