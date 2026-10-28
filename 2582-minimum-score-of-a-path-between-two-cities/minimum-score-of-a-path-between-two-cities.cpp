class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int,int>>>graph(n+1);

            for(int i=0;i<roads.size();i++)
            {
                   int u=roads[i][0];
                   int v=roads[i][1];
                   int w=roads[i][2];

                    graph[u].push_back({v,w});
                    graph[v].push_back({u,w});
            }

             vector<int>visited(n+1,0);
             int ans=INT_MAX;

              queue<int>q;
              q.push(1);

              while(!q.empty())
              {
                     int node=q.front();
                     q.pop();

                      for(auto x : graph[node])
                      {
                            int v=x.first;
                            int w=x.second;

                            ans=min(ans,w);

                             if(!visited[v])
                             {
                                   visited[v]=1;
                                   q.push(v);
                             }
                      }
              }

              return ans;
    }
};