int lengthoflongestsubstring(string s){
  int n= s.size();
  unordered_map<int,int>mpp;
  int l=0, r=0;
  for(int l=0;l<n;l++){
    mpp[s[l]]++;
  }
  int ans=0;
  while(n<(l-r+1)){
    mpp[s[l]]--;
    if(mp[s[l]]==0){
      mp.erase(s[l]);
      l++;
    }
    if(mp.size()==(r-l+1)){
      ans= max(ans,r-l+1);
    }
  }
  return ans;
  
}
