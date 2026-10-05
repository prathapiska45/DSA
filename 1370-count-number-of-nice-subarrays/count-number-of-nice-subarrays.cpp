class Solution {
public:
      int solve(vector<int>&nums,int k)
      {
             int n=nums.size();

               unordered_map<int,int>mp;
               int ans=0;
               int l=0;

                for(int r=0;r<n;r++)
                {
                      mp[nums[r]]++;

                        while(mp[1]>k)
                        {
                              mp[nums[l]]--;
                              l++;
                        }
                        
                        ans+=r-l+1;
                } 

                return ans;
      }
    int numberOfSubarrays(vector<int>& nums, int k) {
            int n=nums.size();
          
            for(int i=0;i<n;i++)
            {
                  nums[i]=nums[i]%2;
            }  

            return solve(nums,k)-solve(nums,k-1);
    }
};