class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int sz) {
        sort(bt.begin(), bt.end(), [](vector<int> a, vector<int>b){
            return a[1]>b[1]; 
        });
        int ans=0;
        for(auto x:bt){
            if(x[0]<=sz){
                ans+=x[0]*x[1];
                sz-=x[0];
            }else{
                ans+=sz*x[1];
                break;
            }
        }
        return ans;
    }
};