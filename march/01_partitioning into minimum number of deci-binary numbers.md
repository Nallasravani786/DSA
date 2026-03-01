### I N T U I T I O N
Any number can be written as a sum of deci-binary numbers (numbers containing only 0 and 1).

To form a digit like d, we need at least d deci-binary numbers stacked together.

So the maximum digit in the string determines the minimum number of deci-binary numbers required.

The code simply finds the largest digit in the string and returns its integer value.

If it finds '9', it stops early since 9 is the maximum possible digit.

###### C O D E
```cpp
int minPartitions(string n) {
        char maxdigit = '0';

        for( char &c : n){
          if(maxdigit < c) maxdigit = c;
          if(maxdigit == '9') break;
        }
        return maxdigit-'0';
        
    }

```
