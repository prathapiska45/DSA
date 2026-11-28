class Solution {
public:
      unordered_map<int,vector<int>>mp;
      vector<int>last;
      vector<int>result_size;
      unordered_map<int,vector<int>>adj;

     void dfs(int i,string& s)
     {
            int n=s.length();

             char ch=s[i];

             int last_seen=last[ch-'a'];   
             
             last[ch-'a']=i;

             for(auto x : mp[i])
             {
                   int new_parent=i;

                   if(last[s[x]-'a']!=-1)
                   {
                       new_parent=last[s[x]-'a'];
                   }
              
                  adj[new_parent].push_back(x);  

                  dfs(x,s);  
             }
             
             last[ch-'a']=last_seen;
     }

    int dfs2(int i)
    {
           int size=1;

           for(auto x : adj[i])
           {
                 size+=dfs2(x);
           }

           result_size[i]=size;

           return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
           int n=parent.size();

            last.assign(26,-1);
            result_size.assign(n,1);

            for(int i=1;i<n;i++)
            {
                  int u=parent[i];
                  int v=i;
                  mp[u].push_back(v);
            }

           dfs(0,s);

           dfs2(0);

           return result_size;
    }
};