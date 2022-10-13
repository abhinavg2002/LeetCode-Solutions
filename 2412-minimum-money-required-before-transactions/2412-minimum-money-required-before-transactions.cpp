class Solution {
public:
    #define ll long long
    long long minimumMoney(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](vector<int>&x, vector<int> &y){
            ll o1=min(-x[0], -x[0]+x[1]-y[0]);
            ll o2=min(-y[0], -y[0]+y[1]-x[0]);
            if(o1>o2){
                return false;
            }else if(o2>o1){
                return true;
            }
            return x[0]>y[0];
        });
        
        ll m=0, ans=0;
        for(auto x:v){
            m-=x[0];
            ans=min(ans, m);
            m+=x[1];
        }
        return abs(ans);
    }
};