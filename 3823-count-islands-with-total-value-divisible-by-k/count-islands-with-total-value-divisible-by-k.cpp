class Solution {
public:
       long long solve(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j)
       {
              int m=grid.size();
              int n=grid[0].size();

               visited[i][j]=1;

                long long ans=0;

                 int dx[]={-1,1,0,0};
                 int dy[]={0,0,-1,1};

                 for(int k=0;k<4;k++)
                 {
                        int x=i+dx[k];
                        int y=j+dy[k];

                         if(x>=0 && y>=0 && x<m && y<n)
                         {
                               if(!visited[x][y] && grid[x][y]!=0)
                               {
                                    ans+=grid[x][y]+solve(grid,visited,x,y);
                               }
                         }
                 }

                 return ans;
       }
    int countIslands(vector<vector<int>>& grid, int k) {
            int m=grid.size();
            int n=grid[0].size();

             int ans=0;
             vector<vector<int>>visited(m,vector<int>(n,0));

              for(int i=0;i<m;i++)
              {
                     for(int j=0;j<n;j++)
                     {
                           if(grid[i][j]!=0 && !visited[i][j])
                           {
                                    long long res=solve(grid,visited,i,j);
                                    res+=grid[i][j];
                                    if(res%k==0)
                                    ans++;
                           }
                     }
              }
              return ans;
    }
};