class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph))
                return false;
            }
        }
        return true;
    }

    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph){
        color[node]=col;
        for(auto x: graph[node]){
            if(color[x]==-1){
                if(!dfs(x,1-col,color,graph))
                return false;
            }
            else if(color[x]==col) return false;
        }
        return true;

    }
};
