class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxprod= nums[0];
        for(int i=0;i<n;i++){
            int prod=1;
            for(int j=i;j<n;j++){
                prod= prod*nums[j];
                maxprod= max(maxprod, prod);
            }
        }
        return maxprod;
    }
};
