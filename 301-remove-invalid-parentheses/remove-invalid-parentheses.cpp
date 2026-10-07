class Solution {
public:
       unordered_set<string>ans;
       int max_length=0;

      void solve(string &s,string &temp,int count,int idx)
      {
              int n=s.length();

              if(count<0)
              return;

               if(idx>=n)
               {
                     if(count==0 && temp.length()>max_length)
                     {
                            max_length=temp.length();
                            ans.clear();
                     }

                    if(count==0 && temp.length()==max_length)
                    {
                           ans.insert(temp);
                    }

                     return;
               }

               temp.push_back(s[idx]);
                int new_count=count;
            
                if(s[idx]=='(')
                new_count++;
                else if(s[idx]==')')
                new_count--;

                 solve(s,temp,new_count,idx+1);

                 temp.pop_back();

                 solve(s,temp,count,idx+1);
      }

    vector<string> removeInvalidParentheses(string s) {
               int n=s.length();
               string temp="";

               solve(s,temp,0,0);

               vector<string>result;

               for(auto x : ans)
               {
                     result.push_back(x);
               }

               return result;
    }
};