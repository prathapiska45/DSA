class Solution {
public:
    typedef long long ll;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
            int n=servers.size();
            int m=tasks.size();

             vector<vector<int>>server(n);

             for(int i=0;i<n;i++)
             {
                   server[i]={servers[i],i};
             }

             sort(server.begin(),server.end());
             priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>free;
             priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>busy;

             for(auto x : server)
             {
                  free.push({x[0],x[1]});
             }

              vector<int>ans;
              long long time=0;

              for(int i=0;i<tasks.size();i++)
              {
                    time=max(time,(long long)i);

                     while(!busy.empty() && busy.top()[0]<=time)
                     {
                          vector<ll>temp=busy.top();
                          busy.pop();
                          free.push({temp[1],temp[2]});
                     }

                     if(free.empty())
                     {
                          time=busy.top()[0];
                           while(!busy.empty() && busy.top()[0]<=time)
                           {
                                vector<ll>temp=busy.top();
                                busy.pop();
                                 
                                  free.push({temp[1],temp[2]});
                           }
                     }

                     vector<ll>temp=free.top();
                     free.pop();

                      ans.push_back(temp[1]);
                    
                     busy.push({(ll)(tasks[i]+time),temp[0],temp[1]});
              }

              return ans;
    }
};