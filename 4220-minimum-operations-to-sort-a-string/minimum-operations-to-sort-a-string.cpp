class Solution {
public:
    int minOperations(string s) {
           int n=s.length();

           string temp=s;
           sort(temp.begin(),temp.end());

            if(s==temp)
            return 0;
            
            if(n==2)
            return -1;

             char min_char='z';
             char max_char='a';

             for(int i=0;i<n;i++)
             {
                    if(s[i]>max_char)
                     max_char=s[i];

                     if(s[i]<min_char)
                     min_char=s[i];
             }

             if(s[0]==min_char)
             return 1;
             if(s[n-1]==max_char)
             return 1;
             


            char mid_mini=*min_element(s.begin()+1,s.begin()+n-1);
            char mid_maxi=*max_element(s.begin()+1,s.begin()+n-1);
           
              if(s[0]>mid_maxi && s[n-1]<mid_mini)
              return 3;

              return 2;
    }
};