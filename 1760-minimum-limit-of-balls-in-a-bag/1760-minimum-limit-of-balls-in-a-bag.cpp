class Solution {
public:
    // what we can do is we can sum all elements and increase opr by n-1
    // eventually we will be left by to split in min number of balls in opr' operations
    // 16 and 7oprs
    // 16-8 8
    // 8
    int minimumSize(vector<int>& v, int opr) {
        auto check=[&](int mid){
            int ct=0;
            for(auto x:v){
                ct+=(x-1)/mid;
            }
            return ct<=opr;
        };
        
        int n=v.size();
        int l=1, h=*max_element(begin(v), end(v));
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;;
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