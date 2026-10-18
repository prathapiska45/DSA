class Solution {
public:
      int mod=1e9+7;
      typedef long long ll;
      vector<vector<int>>pt;

      int solve(vector<int>&nums)
      {
            int n=nums.size();

            if(n<3)
            return 1;

             vector<int>left;
             vector<int>right;

             for(int i=1;i<n;i++)
             {
                   if(nums[i]<nums[0])
                   left.push_back(nums[i]);
                   else
                   right.push_back(nums[i]);
             }

              int x=(solve(left))%mod;
              int y=(solve(right))%mod;
              int z=(pt[n-1][left.size()])%mod;

              return ((1LL*x*y)%mod*z)%mod;
      }

    int numOfWays(vector<int>& nums) {
           int n=nums.size();

           if(n<3)
           return 0;

           pt.resize(n+1);

            for(int i=0;i<n;i++)
            {
                   pt[i]=vector<int>(i+1,1);

                    for(int j=1;j<i;j++)
                    {
                          pt[i][j]=(pt[i-1][j]+pt[i-1][j-1])%mod;
                    }
            }

           return (solve(nums)-1+mod)%mod;
    }
};