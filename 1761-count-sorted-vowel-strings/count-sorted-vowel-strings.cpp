class Solution {
public:
      int solve(int n,int count,int start)
      {
              if(count==n)
              return 1;

              int ans=0;

                      for(int j=start;j<5;j++)
                      {
                            ans+=solve(n,count+1,j);
                      }

               return ans;
      }
    int countVowelStrings(int n) {
           return solve(n,0,0);
    }
};