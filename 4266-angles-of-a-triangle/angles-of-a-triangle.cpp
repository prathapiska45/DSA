class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
              int a=sides[0];
              int b=sides[1];
              int c=sides[2];

              if(a+b<=c || b+c<=a || a+c<=b)
               return {};

               vector<double>ans;
               double pi=acos(-1.0);

               double x=acos((double)(a*a+b*b-c*c)/(2.0*a*b))*180.0/pi;
               double y=acos((double)(b*b+c*c-a*a)/(2.0*b*c))*180.0/pi;
               double z=acos((double)(c*c+a*a-b*b)/(2.0*a*c))*180.0/pi;

               ans.push_back(x);
               ans.push_back(y);
               ans.push_back(z);

               sort(ans.begin(),ans.end());
               return ans;
    }
};