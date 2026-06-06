vector<vector<int>>insert(vector<vector<int>>& interval, vector<vector<int>>& newinterval){
  vetcor<vector<int>>result;
  for (auto it: intervals){
    if(it[1]<newinterval[0]){
      result.push_back(it);
    }
    else if(it[0]>newinterval[1]){
      result.push_back(newinterval);
      newinterval= it;
    }
    else{
      newinterval[0]= min(newinterval[0],it[0]);
      newinterval[1]= max(newinterval[1],it[1]);
    }
  }
  result.push_back(newinterval);
  return result;
}
