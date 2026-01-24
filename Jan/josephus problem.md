## I N T U I T I O N ##

Start with 1 person → the safe position is 0 (using 0-based index).

Add people one by one to the circle.

Every time a new person is added:

The safe position shifts by k steps because every k-th person is removed.

Use modulo (% i) to wrap around the circle and stay within bounds.

After processing all n people, convert to 1-based index by adding 1.
```cpp
int josephus(int n, int k) {
      int ans =0;
      for(int i=2;i<=n;i++){
          ans = (ans + k) %i;
      }
      return ans+1;
    
    }
```
