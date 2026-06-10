vector<int>next_smaller(vector<int>&nums){
  int n= nums.size();
  vector<int>ans(n,-1);
  stack<int>st;
  for(int i=0;i<n;i++){
    while(!st.empty() && st.top() >= nums[i]){
      st.pop();
      if(!st.empty()){
        st.top()=nums[i];
        st.push(nums[i]);
      }
    }
  }
  return ans;
}
