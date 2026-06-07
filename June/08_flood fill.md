#### I M A G E
<img width="2842" height="1354" alt="image" src="https://github.com/user-attachments/assets/6353bc5a-4018-4e73-9781-6f9ce3451abe" />

#### I N T U I T I O N

Start from cell (sr, sc) and note its original color

If original color == new color → return (no change needed)

Change current cell to new color

Recursively visit 4 directions (up, down, left, right)

Only continue DFS if neighbor has the same original color

Repeat until all connected same-color cells are filled


###### C O D E (DFS)
```cpp
void dfs(vector<vector<int>>&image,int r,int c,int originalcolor,int color) {
     
       int m = image.size();
        int n = image[0].size();

    if( r<0  || c<0 || r>=m || c>=n)  return ;

     if(image[r][c] != originalcolor) return ;

     image[r][c] = color;

     dfs(image,r+1,c,originalcolor,color);
     dfs(image,r-1,c,originalcolor,color);
     dfs(image,r,c+1,originalcolor,color);
     dfs(image,r,c-1,originalcolor,color);

  }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int originalcolor = image[sr][sc];

        if(originalcolor == color) return image;

        dfs(image,sr,sc,originalcolor,color); 
        return image;
    }

```

###### C O D E (BFS)

```cpp
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int originalColor = image[sr][sc];

        // if already same color
        if (originalColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n 
                   && image[nr][nc] == originalColor) {

                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
```
