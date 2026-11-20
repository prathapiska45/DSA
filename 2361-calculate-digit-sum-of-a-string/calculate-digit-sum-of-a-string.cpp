class Solution {
public:
    string digitSum(string s, int k) {
          int n=s.length();
          string temp="";
          if(s.length()<=k)
          return s;

            do
            {
                 temp="";

                 for(int i=0;i<s.length();i+=k)
                 {
                      int sum=0;
                      for(int j=i;j<min(i+k,(int)s.length());j++)
                      {
                           sum+=s[j]-'0';
                      }
                      temp+=to_string(sum);
                 }

                  s=temp;
            }while(temp.length()>k);

            return s;
    }
};