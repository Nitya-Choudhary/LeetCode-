vector<int> meetings(vector<int>&start, vector<int>&end){
  vector<tuple<int,int,int>>meetings;
  for(int i=0;i<start.size();i++){
    meetings.push_back({end[i],start[i],i+1});
    
  }
  sort(meetings.begin(), meetings.end());
  vector<int>result;
  int lastend=-1;
  for(auto m:meetings){
    int e= get<0>(m);
    int s= get<1>(m);
    int idx= get<2>(m);
    if(s>lastend){
      result.push_back(idx);
      lastend=e;
    }
  }
  return result;
}
