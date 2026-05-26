vector<int>permute(vector<int>&nums){
  vector<vector<int>>ans;
  vector<int>current;
  vector<bool>used(nums.size(),false);
  backtrack();
  return ans;
}
void backtrack(vector<vector<int>>&ans, vector<int>current,vector<int>&nums, vector<bool>used){
  if(current.size()==ans.size()){
    ans.push_back(current);
    return;
  }
  for(int i=0;i<nums.size();i++){
    if(used[i])continue;
    used[i]=true;
    current.push_back(nums[i]);
    backtrack(ans,currentnums,used);
    current.pop_back();
    used[i]=false;
    
  }
}
