class Solution {
public:
      int mod=1e9+7;
      long long power(int x,int p)
      {
            long long ans=1;
            long long res=x;

             while(p>0)
             {
                   if(p%2==1)
                   {
                        ans=(ans*res)%mod;
                   }

                   res=(res*res)%mod;
                   p=p/2;
             }

             return ans;
      }
     bool solve(vector<int>&nums,int size)
     {
            int n=nums.size();
            int p=*max_element(nums.begin(),nums.end());

             unordered_map<int,int>mp;

             long long hash=0;

             for(int i=0;i<size;i++)
             {
                  hash=(hash*p+nums[i])%mod;
             }

             mp[hash]++;

             for(int i=size;i<n;i++)
             {
                    hash=(hash-(nums[i-size]*power(p,size-1))%mod+mod)%mod;

                    hash=(hash*p+nums[i])%mod;

                    mp[hash]++;
             }

              for(auto x : mp)
              {
                   if(x.second==1)
                   return true;
              }

              return false;
     }
    int smallestUniqueSubarray(vector<int>& nums) {
         int n=nums.size();
         
          int ans=INT_MAX;

          int l=1,r=n;

          while(l<=r)
          {
               int mid=l+(r-l)/2;

                if(solve(nums,mid))
                {
                      r=mid-1;
                      ans=mid;
                }
                else
                {
                      l=mid+1;
                }
          }

          return ans;
    }
};