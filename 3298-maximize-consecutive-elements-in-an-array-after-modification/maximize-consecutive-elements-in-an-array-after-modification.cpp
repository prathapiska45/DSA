class Solution {
public:
      int find(int i,vector<int>&nums,int val)
      {
              int n=nums.size();

            int j=lower_bound(nums.begin()+i,nums.end(),val)-nums.begin();

            if(j<n && nums[j]==val)
            {
                 return j;
            }

            return -1;
      }
    int solve(vector<int>&nums,int idx,int add,vector<vector<int>>&dp)
    {
          int n=nums.size();

           if(idx>=n)
           return 0;

           if(dp[idx][add]!=-1)
           return dp[idx][add];

           int curr_val=nums[idx]+add;

            int j=find(idx+1,nums,curr_val);
            int take=1;

            if(j!=-1)
           take=max(take,1+solve(nums,j,1,dp));

           int x=find(idx+1,nums,curr_val+1);

            if(x!=-1)
            take=max(take,1+solve(nums,x,0,dp));

            return dp[idx][add]=take;
    }
    int maxSelectedElements(vector<int>& nums) {
          int n=nums.size();

          sort(nums.begin(),nums.end());

           int result=1;
           vector<vector<int>>dp(n,vector<int>(2,-1));

           for(int i=0;i<n;i++)
           {
                result=max({result,solve(nums,i,0,dp),solve(nums,i,1,dp)});
           }

           return result;
    }
};