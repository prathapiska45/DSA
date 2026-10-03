class Solution {
public:
     bool solve(string &s,int open,int close,int i,vector<vector<vector<int>>>&dp)
     {
            int n=s.length();

            if(close>open)
            return false;

            if(i>=n)
            return open==close;

            if(dp[i][open][close]!=-1)
            return dp[i][open][close];

             if(s[i]=='(')
             return dp[i][open][close]=solve(s,open+1,close,i+1,dp);
             else if(s[i]==')')
             return dp[i][open][close]=solve(s,open,close+1,i+1,dp);

              else
              return dp[i][open][close]=solve(s,open,close,i+1,dp) || solve(s,open+1,close,i+1,dp) || solve(s,open,close+1,i+1,dp);
     }
    bool checkValidString(string s) {
              int n=s.length();

              vector<vector<vector<int>>>dp(n,vector<vector<int>>(101,vector<int>(101,-1)));

              return solve(s,0,0,0,dp);
    }
};