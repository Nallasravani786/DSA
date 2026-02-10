## I N T U I T I O N 
Our goal is to find the slowest speed Koko can eat so she finishes all piles exactly on time or just before her limit $k$.

Here is the intuition of how we reach that goal:

Define the Search Space: We know the answer is somewhere between 1 (minimum speed) and the size of the largest pile (maximum speed needed).

Binary Search: Instead of guessing every number, we pick a middle speed and check if Koko can finish all bananas at that rate.

Adjusting the Speed:

If she can finish, she might be eating too fast; we save this speed as a possible answer and try even slower speeds to find the true minimum.

If she cannot finish, she is too slow; we must increase the speed.

The Result: By repeatedly cutting the options in half, we narrow down the exact point where she transitions from being too slow to being just fast enough.

```cpp
bool canfinish(vector<int>&arr,int k, int s){
    long long tothrs = 0;
    for(int &p : arr) {
        tothrs += (long long) (p+s-1)/s;
    }
    return tothrs<=k;
      
  }
  
    int kokoEat(vector<int>& arr, int k) {
    int low =1;
    int high = *std::max_element(arr.begin(),arr.end());
    int ans = high;
    while(low<=high){
    int mid = low + (high-low)/2;
        if(canfinish(arr,k,mid)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
      return ans;  
    }


```
