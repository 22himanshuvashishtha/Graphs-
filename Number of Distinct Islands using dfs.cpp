
class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid,vector<pair<int,int>>& vec,int row0,int col0){
        visited[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                dfs(nrow,ncol,visited,grid,vec,row0,col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<pair<int,int>>vec;
                if(grid[i][j]==1 && !visited[i][j]){
                    dfs(i,j,visited,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
