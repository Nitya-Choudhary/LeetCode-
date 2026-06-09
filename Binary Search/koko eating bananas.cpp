int speed(vector<int>&piles, int h){
  int left=1;
  int ans= right;
  int right= *max_element(piles.begin(), piles.end());
  while(left<=right){
    int mid= left+ (right-left)/2;
    long long hours=0;
    for(int p:piles){
      hours+=(p+mid-1)/mid;
    }
    if(hours<=h){
      ans= mid;
      right= mid-1;
    }
    else{
      left= mid+1;
    }
  }
  return ans;
}
