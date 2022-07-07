class Solution {
public:
    #define ll long long
    bool judgeSquareSum(int c) {
        ll s=sqrt(c);
        ll l=0, r=s;
        while(l<=r){
            ll v=l*l+r*r;
            if(v==c){
                return true;
            }else if(v>c){
                r--;
            }else{
                l++;
            }
        }
        return false;
    }
};