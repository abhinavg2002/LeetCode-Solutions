class Solution {
public:
    bool canChoose(vector<vector<int>>& g, vector<int>& v) {
        auto it=v.begin();
        for(int i=0;i<g.size();i++){
            it=search(it, v.end(), g[i].begin(), g[i].end());
            if(it==v.end())return false;
            it=it+g[i].size();
        }
        return true;
    }
};