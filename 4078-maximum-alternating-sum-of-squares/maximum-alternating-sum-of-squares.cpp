class Solution {
public:

     static bool cmp(int a,int b)
     {
           return abs(a)<abs(b);
     }

    long long maxAlternatingSum(vector<int>& nums) {
             int n=nums.size();

              vector<int>arr=nums;

              sort(arr.begin(),arr.end(),cmp);

               int size=n/2;

               long long odd=0;
               for(int i=0;i<n/2;i++)
               {
                    odd+=arr[i]*arr[i];
               }

               long long even=0;
               for(int i=n-1;i>=n/2;i--)
               {
                    even+=arr[i]*arr[i];
               }

               return even-odd;
    }
};