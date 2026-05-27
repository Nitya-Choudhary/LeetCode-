int findmin(vector<int>&arr, int n){
  int mini= nums[0];
  for(int i=0;i<n;i++){
    mini= min(mini, arr[i]);
  }
  return mini;
}
