class Solution {
public:
      void solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&visited)
      {
             int m=grid.size(); 
             int n=grid[0].size();


             visited[i][j]=1;

              int dx[]={-1,1,0,0};
              int dy[]={0,0,-1,1};

              for(int k=0;k<4;k++)
              {
                     int x=i+dx[k];
                     int y=j+dy[k];
                    
                     if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && grid[x][y]==0)
                     solve(grid,x,y,visited);
              }
      }

    int closedIsland(vector<vector<int>>& grid) {
            int m=grid.size(); 
             int n=grid[0].size();

             vector<vector<int>>visited(m,vector<int>(n,0));

              for(int i=0;i<m;i++)
              {
                    for(int j=0;j<n;j++)
                    {
                          if(i==0 || i==m-1 || j==0 || j==n-1)
                          {
                                if(grid[i][j]==0 && !visited[i][j])
                                {
                                       solve(grid,i,j,visited);
                                }
                          }
                    }
              }

              int ans=0;

              for(int i=0;i<m;i++)
              {
                   for(int j=0;j<n;j++)
                   {
                         if(!visited[i][j] && grid[i][j]==0)
                         {
                               solve(grid,i,j,visited);
                               ans++;
                         }
                   }
              } 
              return ans;
    }
};