class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();

            int ans=0;

             for(int i=0;i<m;i++)
             {
                  for(int j=0;j<n;j++)
                  {
                       if(grid[i][j]==1)
                       {
                            bool take=true;
                              for(int x=0;x<n;x++)
                              {
                                   if(x!=j && grid[i][x])
                                   {
                                         ans++;
                                         take=false;
                                         break;
                                   }
                              }
                              
                               if(take)
                               {
                                    for(int x=0;x<m;x++)
                                    {
                                         if(x!=i && grid[x][j])
                                         {
                                              ans++;
                                              break;
                                         }
                                    }
                               }
                       }
                  }
             }

             return ans;
    }
};