#### I M A G E
<img width="2878" height="1450" alt="image" src="https://github.com/user-attachments/assets/556f8524-5aec-43d8-93f8-2399c9bbe25d" />

#### I N T U I T I O N
Not all 'O' cells should be flipped, only the ones fully surrounded by 'X'

Any 'O' connected to the boundary cannot be surrounded

So instead of finding surrounded regions, we find safe regions first

Start BFS/DFS from all border 'O's

Mark all connected 'O's as safe (temporary mark like '#')

Finally: Convert remaining 'O' → 'X' (surrounded)  ,  Convert '#' → 'O' (restore safe ones)

###### C O D E(BFS)

```cpp
 void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(i == 0 || j == 0 || i == m-1 || j == n-1){

                    if(board[i][j] == 'O') {
                        q.push({i,j});
                        board[i][j] = '#';
                    }
                }
            }
        }

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

         while(!q.empty()){
            auto [r , c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr,nc});
                }
            }
         }

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
         }
    }


```
