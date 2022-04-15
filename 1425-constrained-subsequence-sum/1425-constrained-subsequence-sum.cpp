class Solution {
public:
    int constrainedSubsetSum(vector<int>& v, int k) {
        int n=v.size();
        vector<int> dp(n, 0);
        multiset<int> s;
        int j=0;
        for(int i=0;i<n;i++){
            dp[i]=v[i];
            if(s.size()){
                dp[i]+=max(0, *s.rbegin());
            }
            if(s.size()>=k){
                s.erase(s.find(dp[j++]));
            }
            s.insert(dp[i]);
        }
        // for(auto x:dp){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        return *max_element(dp.begin(), dp.end());
    }
};