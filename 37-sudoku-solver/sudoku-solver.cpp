class Solution {
public:
      bool valid(vector<vector<char>>&board,int i,int j,char d)
      {
             for(int k=0;k<9;k++)
             {
                  if(board[i][k]==d)
                  return false;
             }

              for(int k=0;k<9;k++)
              {
                  if(board[k][j]==d)
                  return false;
              }
            
             int row=(i/3)*3;
             int col=(j/3)*3;
            
               for(int a=row;a<row+3;a++)
               {
                      for(int b=col;b<col+3;b++)
                      {
                            if(board[a][b]==d)
                            return false;
                      }
               }
               return true;
               
      }
     bool solve(vector<vector<char>>&board)
     {
            for(int i=0;i<9;i++)
            {
                  for(int j=0;j<9;j++)
                  {
                         if(board[i][j]!='.')
                         continue;

                         for(char d='1';d<='9';d++)
                         {
                                 if(valid(board,i,j,d))
                                 {
                                  board[i][j]=d;

                                  if(solve(board))
                                 return true;

                                 board[i][j]='.';
                                 }
                         }
                        return false;
                  }
            }

            return true;
     }
    void solveSudoku(vector<vector<char>>& board) {
           solve(board);
    }
};