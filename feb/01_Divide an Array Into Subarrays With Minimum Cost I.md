## I N T U T I O N 

Always include nums[0] in the cost (it’s mandatory).

Put all remaining elements into a temporary array.

Sort the remaining elements to find the smallest values.

Add the two minimum elements from the sorted array.

Return the sum of these three chosen elements, which gives the minimum cost.


```cpp
  int minimumCost(vector<int>& nums) {
    int n = nums.size();
    vector<int>temp;
    int total = nums[0];
    for(int i=1;i<n;i++){
        temp.push_back(nums[i]);
    }
    sort(temp.begin(),temp.end());
    total+=temp[0];
    total+=temp[1];
    return total;
    }

```
