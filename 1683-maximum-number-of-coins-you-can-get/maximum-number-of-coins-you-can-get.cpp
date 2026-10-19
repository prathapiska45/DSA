class Solution {
public:
    int maxCoins(vector<int>& piles) {
          int n=piles.size();

           sort(piles.begin(),piles.end());

            int result=0;
            int loops=n/3;

             int i=n-2;

              while(i>=0 && loops>0)
              {
                    result+=piles[i];
                    i=i-2;
                    loops--;
              }

              return result;
    }
};