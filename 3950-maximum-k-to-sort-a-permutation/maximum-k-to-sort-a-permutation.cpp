class Solution {
public:
    int sortPermutation(vector<int>& nums) {
          int n=nums.size();

           vector<int>temp=nums;
           sort(temp.begin(),temp.end());

           if(nums==temp)
           return 0;

            int val=-1;

             for(int i=0;i<n;i++)
             {
                     if(nums[i]!=temp[i])
                     {
                           if(val==-1)
                           val=nums[i];
                           else
                           val=nums[i] & val;
                     }
             }

             return val;
    }
};