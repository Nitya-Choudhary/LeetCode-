class Solution{
    public:
    void solve(vector<vector<int>>& board){
        if(board.empty() ||board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            dfs(board,i,0,m,n);
        }
        for(int j=0;j<n;j++){
            dfs(board,0,j,m,n);
            dfs(board,m-1,j,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
    private:
    void dfs(vector<vector<int>>& board,int x,int y,int m,int n){
        if(x<0||y<0||x>=m||y>=n||board[x][y]!='O') return;
        board[x][y]='#';
        dfs(board,x+1,y,m,n);
        dfs(board,x-1,y,m,n);
        dfs(board,x,y+1,m,n);
        dfs(board,x,y-1,m,n);
  }
};
