class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32>n1(start);
        bitset<32>n2(goal);
        int ans=0;
        for(int i=0;i<32;i++){
            if(n1[i]!=n2[i]) ans++;
        }
        return ans;

        
    }
};