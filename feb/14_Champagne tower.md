## I N T U I T I O N 
You simulate the tower row by row.

prev_row stores how much champagne each glass in the previous row currently has.

For each glass, if it has more than 1 cup, the extra (prev_row[i] - 1) overflows.

That extra is split equally (0.5 each) to the two glasses just below it in the next row.

You keep repeating this process until you reach query_row.

Finally, you return min(1.0, prev_row[query_glass]) because a glass can hold at most 1 cup.

👉 So basically:
You simulate overflow level by level, always carrying only the previous row (space optimized DP).



```cpp
double champagneTower(int poured, int query_row, int query_glass) {

       vector<double>prev_row = { (double) poured};
      
      for(int r =1; r<= query_row; r++){

        vector<double>curr_row(r+1,0.0);

        for(int i=0;i<r;i++){

            double extra = prev_row[i] -1;

            if(extra>0){
                curr_row[i] += 0.5*extra;
                curr_row[i+1] += 0.5*extra;

            }
        }
            prev_row = curr_row;
      }
        return min(1.0,prev_row[query_glass]);
      

    }
```
