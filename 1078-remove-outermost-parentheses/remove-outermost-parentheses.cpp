class Solution {
public:
    string removeOuterParentheses(string s) {
           int n=s.length();

            int open=0,close=0;
            string ans="";

            for(int i=0;i<n;i++)
            {
                    if(s[i]=='(' && open==0 && close==0)
                    {
                           i++;
                           open=1;
                           close=0;
                           while(open!=close)
                           {
                                  if(s[i]=='(')
                                  open++;
                                  else
                                  close++;

                                  if(close!=open)
                                   ans+=s[i];
                                 i++;
                           }
                           i--;
                           open=0;
                           close=0;
                    }
            }
            return ans;
    }
};