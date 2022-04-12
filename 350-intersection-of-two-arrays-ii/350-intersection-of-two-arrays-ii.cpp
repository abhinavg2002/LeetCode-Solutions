class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(auto x:a){
            m[x]++;
        }
        for(auto x:b){
            if(m[x]>0){
                ans.push_back(x);
                m[x]--;
            }
        }
        return ans;
    }
};