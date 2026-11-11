class Solution {
public:
    long long minimumCost(int cost1, int cost2, int cost_both, int need1, int need2) {
          long long ans=0;

           long long common=min(need1,need2);

            ans+=(long long)common*min(cost_both,cost1+cost2);

            if(need1>need2)
            {
                  ans+=(long long) (need1-need2)*min(cost1,cost_both);
            }
            else
            ans+=(long long) (need2-need1)*min(cost_both,cost2);

            return ans;
    }
};