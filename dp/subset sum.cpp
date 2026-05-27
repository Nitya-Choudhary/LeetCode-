vector <int> subsetsum(vector<int>&arr){
  int n= arr.size();
  vector<int> sums;
  find();
  sort(sums.begin(), sums.end());
  return sums;
}

void find(int ind, vector<int>&arr, int currsum, vector<int>&sums){
  if(arr.size()==sums.size()){
    sums.push_back(currsum);
    return;
  }
  find(ind+1,arr, currsum+arr[ind],sums);
  find(ind+1, arr, currsum, sums);
  
}
