vector<int>subsetsum(vector<int>arr){
  vector<int>sums;
  findsums();
  sort(sums.begin(), sums.end());
  return sums;
}

void findsums(int ind, int currsum, vector<int>&arr, vector<int>&sums){
  if(ind==arr.size()){
    sums.push_back(currsum);
    return;
  }
  findsums(ind+1,currsum+arr[ind],arr,sums);
  findsums(ind+1,currsum,arr,sums);
}
