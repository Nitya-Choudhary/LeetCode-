vector<int>solve(vector<int>&arr, int target){
  int n= arr.size();
  int st=0, end= n-1, mid= st+(end-st)/2;
  while(st<=end){
    if(nums[mid]<target)st= mid+1;
    else if(nums[mid]>target) end= mid-1;
    
  }
  return ans;
}
