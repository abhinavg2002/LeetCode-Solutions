class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++){
            double d=sqrt(c-i*i);
            if(d==(int)d)return true;
        }
        return false;
    }
};