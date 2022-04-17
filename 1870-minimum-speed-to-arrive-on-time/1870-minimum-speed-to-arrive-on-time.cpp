class Solution {
public:
    int minSpeedOnTime(vector<int>& d, double hour) {
        int n=d.size();
        if(n>ceil(hour)){
            return -1;
        }
        auto check=[&](int mid){
            double time=0;
            for(int i=0;i<n-1;i++){
                time+=ceil((1.0*d[i])/mid);
            }
            time+=(1.0*d[n-1])/mid;
            return time<=hour;
        };
        int l=1, h=1e8, ans;
        while(l<=h){
            int mid=l+(h-l)/2;
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