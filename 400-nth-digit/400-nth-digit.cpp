#define ll long long
class Solution {
public:
    int findNthDigit(int n) {
        ll len=1, ct=9, s=1;
        while(n>len*ct){
            n-=len*ct;
            len++;
            ct*=10;
            s*=10;
        }
        s+=(n-1)/len;
        string t=to_string(s);
        return t[(n-1)%len]-'0';
    }
};