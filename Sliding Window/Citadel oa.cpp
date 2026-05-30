int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  unordered_map<int,int>freq;
  for(int i=0;i<n;i++){
    freq[a[i]]++;
  }
  int minfreq= INT_MAX;
  for(auto &it:freq){
    minfreq= min(minfreq,it.second);
    unordered_map<int,int>cnt;
    int l=0, r=0,maxfreq=0, ans=0;
    for(int r=0;r<n;r++){
      maxfreq= max(maxfreq,cnt[a[r]]++);
      while(maxfreq>minfreq){
        cnt[a[r]]--;
        l++;
        maxfreq=0;
        for(auto it:cnt){
          maxfreq= max(maxfreq, it.second);
        }
        if(maxfreq= minfreq){
          ans= max(ans,r-l+1);
        }
      }
      return ans;
    }
    
  }
}
