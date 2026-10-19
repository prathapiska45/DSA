class Solution {
public:
     int solve(vector<int>&count)
     {
            int ans=0;
            int cons=0;

            for(auto x : count)
            {
                  if(x==1)
                  cons++;
                  else
                  cons=0;

                  ans+=cons;
            }

            return ans;
     }
    int numSubmat(vector<vector<int>>& mat) {
             int m=mat.size();
             int n=mat[0].size();

            int result=0;

            for(int start_row=0;start_row<m;start_row++)
            {
                   vector<int>count(n,1);
                   for(int end_row=start_row;end_row<m;end_row++)
                   {
                         for(int j=0;j<n;j++)
                         {
                              count[j]=count[j] & mat[end_row][j];
                         }

                         result+=solve(count);
                   }
            }

            return result;
    }
};