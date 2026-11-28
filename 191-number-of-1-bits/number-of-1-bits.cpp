class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> number(n);

        int ans=0;
        for(int i=0;i<number.size();i++){
            if(number[i]==1) ans++;
        }
        return ans;
        
    }
};