class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
            int n=arr.size();

             int sum=0;

              for(int i=0;i<n;i++)
              {
                  sum+=arr[i];
              }

              if(sum%3!=0)
              return false;

              int new_sum=sum/3;

              int count=0;
              int s=0;

              for(int i=0;i<n;i++)
              {
                   s+=arr[i];

                    if(s==new_sum)
                    {
                          count++;
                          s=0;
                    }
              }


              return count>=3;
    }
};