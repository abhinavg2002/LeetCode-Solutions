class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string, vector<string> > m;
        for(auto &x:s){
            string r=x;
            sort(r.begin(), r.end());
            m[r].push_back(x);
        }
        vector<vector<string>> v;
        for(auto &x:m){
            v.push_back(x.second);
        }
        return v;
    }
};