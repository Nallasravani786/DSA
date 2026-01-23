Intuition:
This simulates giving change at a counter where each item costs 5.

Keep track of how many 5, 10, and 20 bills you have.

For a 10, give back one 5; for a 20, prefer 10 + 5, otherwise use three 5s.

If at any point exact change isn’t possible, return false; otherwise true.

```cpp
bool canServe(vector<int> &arr) {
       int n= arr.size();
       int five=0,ten=0,twenty=0;
       
       for(int i=0;i<n;i++){
           if(arr[i] == 5){
               five+=1;
           }
           else if(arr[i] == 10){
               ten+=1;
               if(five>0) five-=1;
               else return false;
           }
           else {
               twenty+=1;
             if( five >0 && ten >0 ){
                 five-=1;
                 ten-=1;
             }
             else if(five >=3 && ten==0){
                 five-=3;
             }
             else return false;
           }
       }
       return true;
        
    }
```
