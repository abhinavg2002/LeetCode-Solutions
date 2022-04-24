class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& pt) {
        vector<vector<int>> h(101);
        for(auto x:r){
            h[x[1]].push_back(x[0]);
        }
        for(auto &x:h){
            sort(x.begin(), x.end());
        }
        int n=r.size();
        vector<int> ans;
        for(auto p:pt){
            int x=p[0], y=p[1];
            int s=0;
            for(int k=y;k<=100;k++){
                s+=end(h[k])-lower_bound(h[k].begin(), h[k].end(), x);
            }
            ans.push_back(s);
        }
        return ans;
    }
};