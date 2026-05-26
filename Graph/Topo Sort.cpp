vector<int>toposort(int n, vector<int>adj[]){
  stack<int>st;
  vector<int>vis(n,0);
  for(int i=0;i<n;i++){
    if(vis[i]==0){
      find(i,vis,adj,st);
    }
    
  }
  vector<int>topo;
  while(!st.empty()){
    topo.push_back(st.top());
    st.pop();
  }
  return topo;
  
}

void find(int node, vector<int>&vis, vector<int>&adj,stack<int>st){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it]){
      find(it, vis,adj,st);
    }
  }
  st.push(node);
}
