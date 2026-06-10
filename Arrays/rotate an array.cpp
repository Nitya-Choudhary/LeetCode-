vector<int>rotate(vector<int>&nums, int k){
  int n= nums.size();
  k= k%n;
  rotate(nums.begin(),nums.end());
  rotate(nums.begin(),nums.end()+k);
  rotate(nums.begin()+k,nums.end());
}
