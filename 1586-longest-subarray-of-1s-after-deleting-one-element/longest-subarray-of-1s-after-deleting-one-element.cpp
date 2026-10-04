class Solution {
public:
    int longestSubarray(vector<int>& nums) {
             int n=nums.size();
             
             unordered_map<int,int>mp;
             int l=0,ans=0;

             for(int r=0;r<n;r++)
             {
                    mp[nums[r]]++;

                    if(mp[0]>1)
                    {
                          mp[nums[l]]--;
                          l++;
                    }

                    ans=max(ans,mp[1]);
             }
              
              return ans==n ? n-1 : ans;
    }
};