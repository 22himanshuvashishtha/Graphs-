class Solution {
    private:
    void dfs(int r,int c,vector<vector<int>>& visited,vector<vector<char>>& board,int delrow[],int delcol[]){
        int n=board.size();
        int m=board[0].size();
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,visited,board,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

 
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !visited[0][i]) dfs(0,i,visited,board,delrow,delcol);
            if(board[n-1][i]=='O' && !visited[n-1][i]) dfs(n-1,i,visited,board,delrow,delcol);
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visited[i][0]) dfs(i,0,visited,board,delrow,delcol);
            if(board[i][m-1]=='O' && !visited[i][m-1]) dfs(i,m-1,visited,board,delrow,delcol);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
