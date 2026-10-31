class Solution {
public:
    int minMoves(vector<int>& nums) {
          int n=nums.size();

           int ans=0;
           int count=0;

           sort(nums.begin(),nums.end());

            for(int i=1;i<n;i++)
            {
                  int diff=nums[i]-nums[i-1]+count;

                   count+=nums[i]-nums[i-1];

                   ans+=diff;
            }

            return ans;
    }
};