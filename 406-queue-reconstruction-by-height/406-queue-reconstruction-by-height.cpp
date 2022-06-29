class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]>p2[0];
        else return p1[1]<p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);
        vector<vector<int>> res;
        int n=v.size();
        for(int i=0;i<n;i++){
            res.insert(res.begin()+v[i][1], v[i]);
        }
        return res;
    }
};