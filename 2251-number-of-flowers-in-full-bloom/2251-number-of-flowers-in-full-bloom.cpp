class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& persons) {
        // for ith person it can be like number of end after p[i]-number of start after p[i];
        vector<int> ans;
        vector<int> s, e;
        for(auto x:f){
            s.push_back(x[0]);
            e.push_back(x[1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        
        for(auto x:persons){
            auto it1=lower_bound(e.begin(), e.end(), x)-e.begin();
            auto it2=upper_bound(s.begin(), s.end(), x)-s.begin();
            ans.push_back(it2-it1);
        }
        return ans;
    }
};