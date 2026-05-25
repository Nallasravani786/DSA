#### I M A G E
<img width="2826" height="1405" alt="image" src="https://github.com/user-attachments/assets/da0fd4c4-bad4-441d-9db0-3002ef531725" />

###### I N T U I T I O N
Each day has 3 activity choices and we need to maximize total points.

The same activity cannot be done on two consecutive days.

So, the current day’s decision depends on the previous day’s activity.

For the current day, try all activities except the last chosen activity.

Add current day points with the best answer from previous days.

Same (day, last) states repeat many times, so use DP memoization

###### m e m o i z a t i o n _ c o d e
```cpp
int f(int day ,int last,vector<vector<int>>&mat,vector<vector<int>>&dp){
      
      if(day == 0){
          int maxi = 0;
          for(int task = 0;task<3;task++){
              
               if(task !=last) maxi = max(maxi,mat[0][task]);
          }
          return maxi;
      }
      
      if(dp[day][last]!=-1) return dp[day][last];
      
      int maxi = 0;
      
      for(int task =0;task<3;task++){
       
          if(task !=last){
              int points = mat[day][task]+f(day-1,task,mat,dp);
              maxi = max(maxi,points);
          }
      }
      return dp[day][last] = maxi;
  
  }
  
    int maximumPoints(vector<vector<int>>& mat) {
       
       int n = mat.size();
       vector<vector<int>>dp(n,vector<int>(4,-1));
       return f(n-1,3,mat,dp);
        
    }
```

###### t a b u l a t i o n _ c o d e
```cpp
 int maximumPoints(vector<vector<int>>&mat){
     
     int n = mat.size();
     vector<vector<int>>dp(n,vector<int>(4,0));
     
     dp[0][0] = max(mat[0][1],mat[0][2]);
     dp[0][1] = max(mat[0][0],mat[0][2]);
     dp[0][2] = max(mat[0][0],mat[0][1]);
     dp[0][3] = max({mat[0][0],mat[0][1],mat[0][2]});
     
     
    for(int day =1;day<n;day++){
         
         for(int last =0;last<4;last++){
             
             dp[day][last] = 0;
             
            
           for(int task =0;task<3;task++){
       
           if(task !=last)
              { int  points = mat[day][task]+dp[day-1][task];
             
              dp[day][last] = max(points,dp[day][last]);
                  
               } 
               
             } 
         }
  
     }
     return dp[n-1][3]; 
 }

```

