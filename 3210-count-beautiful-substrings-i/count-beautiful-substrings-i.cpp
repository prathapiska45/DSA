class Solution {
public:
    int beautifulSubstrings(string s, int k) {
             int n=s.length();
             int result=0;

             for(int i=0;i<n;i++)
             {
                    int cons=0;
                    int vow=0;
                     for(int j=i;j<n;j++)
                     {
                            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
                            {
                                  vow++;
                            }
                            else
                            cons++;

                             if(vow==cons)
                             {
                                  if((vow*cons)%k==0)
                                  result++;
                             }
                     }
             }
             return result;
    }
};