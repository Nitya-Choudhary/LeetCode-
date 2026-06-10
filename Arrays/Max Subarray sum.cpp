int maxsum(vector<int>&arr){
  int n= arr.size();
  int sum=0;
  int maxi=INT_MIN;
  for(auto x:nums){
    sum= sum+x;
    maxi= max(maxi, sum);
    if(sum<0){
      return 0;
    }
  }
  return maxi;
}
