class Solution {
public:
    int reachNumber(int a) {
        a=abs(a);
        long long n = ceil((-1.0 + sqrt(1+8.0*a)) / 2);
        long long sum = n * (n+1) / 2;
        if(sum==a){
            return n;
        }
        long res=sum-a;
        if(res%2==0){
            return n;
        }
        return n+((n&1)?2:1);
    }
};