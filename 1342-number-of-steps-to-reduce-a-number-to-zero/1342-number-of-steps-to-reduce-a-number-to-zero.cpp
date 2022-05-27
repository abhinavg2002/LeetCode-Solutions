class Solution {
public:
    int numberOfSteps(int n) {
        if(!n)return 0;
        int res=0;
        while(n){
            res+=((n&1)?2:1);
            n/=2;
        }
        return res-1;
    }
};