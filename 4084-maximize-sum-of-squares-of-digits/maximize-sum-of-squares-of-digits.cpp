class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
               
            string ans="";
            if(num*9<sum)
            return "";

             for(int i=0;i<num;i++)
             {
                    for(int j=9;j>=0;j--)
                    {
                          if(sum>=j)
                          {
                              ans+='0'+j;
                              sum-=j;
                              break;
                          }
                    }
             }

             return ans;
    }
};