class Solution {
public:
      static bool cmp(vector<int>&a,vector<int>&b)
      {
           return a[1]<b[1];
      }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
           vector<int>ans(queries.size());

          sort(logs.begin(),logs.end(),cmp);

           vector<vector<int>>query;

           for(int i=0;i<queries.size();i++)
           {
                query.push_back({queries[i],i});
           }

           sort(query.begin(),query.end());
           unordered_map<int,int>mp;
           int l=0,r=0;

           for(int i=0;i<query.size();i++)
           {
                  int val=query[i][0];
                  int idx=query[i][1];

                  
                   while(r<logs.size() && logs[r][1]<=val)
                   {
                        mp[logs[r][0]]++;
                        r++;
                   }

                   while(l<logs.size() && logs[l][1]<val-x)
                   {
                        mp[logs[l][0]]--;
                        if(mp[logs[l][0]]==0)
                        {
                              mp.erase(logs[l][0]);
                        }
                        l++;
                   }

                   ans[idx]=n-mp.size();              
           }

           return ans;
    }
};