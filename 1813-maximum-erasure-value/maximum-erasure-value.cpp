class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
              int n=nums.size();
              int ans=0;

               int l=0;
               unordered_map<int,int>mp;
               int sum=0;

                for(int r=0;r<n;r++)
                {
                       mp[nums[r]]++;
                       sum+=nums[r];

                        while(mp[nums[r]]>1)
                        {
                              mp[nums[l]]--;
                              if(mp[nums[l]]==0)
                              mp.erase(nums[l]);

                              sum-=nums[l];
                              l++;
                        }
                        ans=max(ans,sum);      
                }

                return ans;
    }
};