class Solution {
public:
    int smallestDivisor(vector<int>& v, int t) {
        int l=1, h=1e7;
        auto check=[&](int mid){
            int s=0;
            for(auto x:v){
                s+=ceil(1.0*x/mid);
            }
            return s<=t;
        };
        int ans;
        while(l<=h){
            int mid=(h+l)>>1;
            if(check(mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};