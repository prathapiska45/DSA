class Solution {
public:
      string ans;
      string res="";

     void solve(int n,int k,int idx,int &count)
     {
           if(idx==n)
           {
                count++;
                if(count==k)
                {
                     ans=res;
                }
                return;
           }

            for(char c='a';c<='c';c++)
            {
                  if(res.length()>=1)
                   {
                        if(res.back()==c)
                        continue;
                   }

                  res.push_back(c);

                   solve(n,k,idx+1,count);

                   res.pop_back();
            }
     }

    string getHappyString(int n, int k) {
          int count=0;
           solve(n,k,0,count);

        return ans;
    }
};