class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)return false;
        if(floor(log2(n))==ceil(log2(n))){
            int x=log2(n);
            if(x%2==0){
                return true;
            }
        }
        return false;
    }
};