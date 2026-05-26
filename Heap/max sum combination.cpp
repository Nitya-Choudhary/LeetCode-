vector<int>maxsum(vector<int>&arr1, vector<int>&arr2, int k){
  vector<int>allsum;
  for(int i=0;i<arr1.size();i++){
    for(int j=0;j<arr2.size();i++){
      allsum.push_back(arr1[i]+arr2[j]);
    }
  }
  sort(allsum.end(), allsum.begin());
  vector<int>result(allsum.begin(), allsum.begin()+k);
  return result;
  
}
