class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1, r=100000;
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0;
            for(auto x:q){
                sum+=(x+(mid-1))/mid;
            }
            if(sum>n){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};