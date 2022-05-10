class Solution {
public:
    int fun(int a){
        int s=0;
        while(a){
            s+=(a%10);
            a/=10;
        }
        return s;
    }
    int addDigits(int a) {
        while(a>=10){
            a=fun(a);
        }
        return a;
    }
};