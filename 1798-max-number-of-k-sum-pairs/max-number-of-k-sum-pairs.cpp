class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
           int n=nums.size();

            sort(nums.begin(),nums.end());

             int i=0,j=n-1;

              int ops=0;

              while(i<j)
              {
                    int x=nums[i]+nums[j];

                     if(x>k)
                     j--;
                     else if(x<k)
                     i++;
                     
                     else
                     {
                          ops++;
                          i++;
                          j--;
                     }
              }
              return ops;
    }
};