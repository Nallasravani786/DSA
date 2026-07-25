###### C O D E
```cpp
 int maxProduct(int n) {  
        int l = 0,sl = 0;
        while(n!=0){
          int res = n%10;
         
          n /= 10;

          if(res>l){
            sl = l;
            l = res;
          }
          else if(l>=res && res >=sl) sl = res;
        }
        return l*sl;
    }

```
