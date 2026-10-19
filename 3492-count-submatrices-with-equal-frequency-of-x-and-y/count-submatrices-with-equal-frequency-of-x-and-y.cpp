class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
          int m=grid.size();
          int n=grid[0].size();

            vector<int>count_x(n,0);
            vector<int>count_y(n,0);

            int result=0;

            for(int end_row=0;end_row<m;end_row++)
            {
                   int total_x=0;
                   int total_y=0;

                     for(int j=0;j<n;j++)
                     {
                          if(grid[end_row][j]=='X')
                          count_x[j]++;
                          else if(grid[end_row][j]=='Y')
                          count_y[j]++;

                           total_x+=count_x[j];
                           total_y+=count_y[j];

                           if(total_x>0 && total_x==total_y)
                           result++;
                     }
            }

            return result;
    }
};