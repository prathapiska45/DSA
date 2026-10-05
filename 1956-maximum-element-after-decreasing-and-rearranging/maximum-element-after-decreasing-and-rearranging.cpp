class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
           int n=arr.size();
           sort(arr.begin(),arr.end());

             arr[0]=1;
             int maxi=1;

              for(int i=1;i<n;i++)
              {
                     if(abs(arr[i]-arr[i-1])>1)
                     {
                           arr[i]=1+arr[i-1];
                     }
                     maxi=max(arr[i],maxi);
              }

              return maxi;
    }
};