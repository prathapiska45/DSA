class Solution {
public:
     int solve(vector<vector<int>>&items,vector<int>&temp,int budget,int idx,vector<vector<int>>&dp,int mini)
     {
             int n=items.size();

            if(idx>=n)
            return budget/mini;

            if(dp[idx][budget]!=-1)
            return dp[idx][budget];

            int take=0;
            if(items[idx][1]<=budget)
            {
                 
                take=1+temp[idx]+solve(items,temp,budget-items[idx][1],idx+1,dp,mini);
            }

            int not_take=solve(items,temp,budget,idx+1,dp,mini);

            return dp[idx][budget]=max(take,not_take);
     }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
           int n=items.size();

           vector<int>temp;

           for(int i=0;i<n;i++)
           {
                   int count=0;
                 for(int j=0;j<n;j++)
                 {
                       if(j!=i && items[j][0]%items[i][0]==0)
                       {
                            count++;
                       }
                 }
                 temp.push_back(count);
           }

           int mini=INT_MAX;

           for(int i=0;i<n;i++)
           {
                mini=min(mini,items[i][1]);
           }

           vector<vector<int>>dp(n,vector<int>(budget+1,-1));

          return solve(items,temp,budget,0,dp,mini);
    }
};