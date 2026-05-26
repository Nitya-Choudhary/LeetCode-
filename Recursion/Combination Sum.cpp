vector<vector<int>>combinationsum(vector<int>&candidates, int target){
  sort(candidates.begin(), candidates.end());
  vector<vector<int>>ans;
  vector<int>ds;
  findcombination(0,target,candidates,ans,ds);
  return ans;
}

void findcombination(int ind,int target, vector<vector<int>>ans, vector<int>arr, vector<int>ans){
  if(target==0) return;
  for(int i=ind;i<arr.size();i++){
    if(i>ind && arr[i]==arr[i-1]){continue;}
    if(arr[i]>target) break;
    ds.push_back(arr[i]);
    findcombination(i+1,target-arr[i],arr,ans);
    ds.pop_back();
  }
}
