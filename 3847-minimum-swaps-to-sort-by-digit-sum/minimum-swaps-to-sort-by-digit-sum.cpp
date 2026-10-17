class Solution {
public:
    int minSwaps(vector<int>& nums) {
          int n=nums.size();

             vector<vector<int>>arr;
             unordered_map<int,int>mp;

              for(int i=0;i<n;i++)
              {
                     int x=nums[i];
                     int sum=0;
                     mp[x]=i;

                      while(x>0)
                      {
                             sum+=x%10;
                             x/=10;
                      }

                     arr.push_back({sum,nums[i]});
              }

              sort(arr.begin(),arr.end());
              int swappings=0;

              for(int i=0;i<n;i++)
              {
                     int new_val=arr[i][1];
                     int old_val=nums[i];

                     if(old_val==new_val)
                     continue;

                      int old_idx=mp[old_val];
                      int new_idx=mp[new_val];

                      nums[old_idx]=new_val;
                      nums[new_idx]=old_val;

                      mp[old_val]=new_idx;
                      mp[new_val]=old_idx;

                      swappings++;
              }

              return swappings;
    }
};