class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
             int n=values.size();

              vector<int>visited(n,0);

               long long score=0;
               int idx=0;

                  while(idx>=0 && idx<n)
               {
                      string temp=instructions[idx];

                       if(visited[idx])
                        break;

                        visited[idx]=1;

                       if(temp=="add")
                       {
                             score+=values[idx];
                             idx++;
                       }
                       else
                       {
                            idx=(idx+values[idx]);
                       }
               }
               return score;
    }
};