class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
          int n=nums1.size();

             vector<int>count(100001,0);
             int maxi=0;

             for(int i=0;i<n;i++)
             {
                   int x=abs(nums1[i]-nums2[i]);

                    count[x]++;

                    maxi=max(maxi,x);
             }

             int k=k1+k2;
             
             for(int i=maxi;i>=0;i--)
             {
                   int no_of_times=count[i];

                    int num_ops=min(k,no_of_times);

                      count[i]-=num_ops;
                      k-=num_ops;
                      if(i>0)
                      count[i-1]+=num_ops;

                       if(k==0)
                       break;
             }

             long long result=0;

             for(int i=0;i<=maxi;i++)
             {
                  int no_of_times=count[i];
                   result+=(long long)no_of_times*i*i;
             }

             return result;
    }
};