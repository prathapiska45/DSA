class Solution {
public:
    string resultingString(string s) {
           int n=s.length();

           stack<char>st;

           for(int i=0;i<n;i++)
           {
                  char ch=s[i];

                 if(!st.empty() && (st.top()==ch-1 || st.top()==ch+1 || (st.top()=='z' && ch=='a') || (st.top()=='a' && ch=='z')))
                 {
                        st.pop();
                 }
                 else
                 {
                      st.push(ch);
                 }
           }

           string ans="";

            while(!st.empty())
            {
                  ans+=st.top();
                  st.pop();
            }

            reverse(ans.begin(),ans.end());

            return ans;
    }
};