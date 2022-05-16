class Solution {
public:
    int divide(long a, long b) {
        if(a==INT_MIN and b==-1)return INT_MAX;
        if(a==INT_MIN and b==1)return INT_MIN;
        if(a==INT_MAX and b==1)return INT_MAX;
        if(a==0)return 0;
        int r=1;
        if(a<0)r*=-1;
        if(b<0)r*=-1;
        a=abs(a), b=abs(b);
        int ans=0;
        while(a>=b){
            int ct=1;
            long x=a, y=b;
            while(x>=(y<<1ll)){
                y<<=1ll;
                ct<<=1ll;
            }   
            a-=y;
            ans+=ct;
        }
        return r*ans;
    }
};