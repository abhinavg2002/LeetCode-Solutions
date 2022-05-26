class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x=0;
        while(n){
            n-=(n&(-n));
            x++;
        }
        return x;
    }
};