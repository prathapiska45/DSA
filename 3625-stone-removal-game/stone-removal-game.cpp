class Solution {
public:
    bool canAliceWin(int n) {
           int count=0;

            for(int i=10;i>0;i--)
            {
                  n-=i;
                  count++;
                  if(n<0)
                  {
                        if(count%2==1)
                        {
                             return false;
                        }
                        else
                        return true;
                  }
            }
            return true;
    }
};