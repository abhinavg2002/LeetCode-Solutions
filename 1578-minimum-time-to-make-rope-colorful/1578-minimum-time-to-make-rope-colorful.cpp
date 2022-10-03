class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        vector<pair<char, vector<int>>> v;
        v.push_back({s[0], {cost[0]}});
        int n=s.size();
        vector<int> r;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                v.back().second.push_back(cost[i]);
            }else{
                v.push_back({s[i], {cost[i]}});
            }
        }
        int ans=0;
        for(auto &x:v){
            vector<int>t=x.second;
            if(t.size()>1)ans+=accumulate(t.begin(), t.end(), 0)-*max_element(t.begin(), t.end());
        }
        return ans;
    }
};