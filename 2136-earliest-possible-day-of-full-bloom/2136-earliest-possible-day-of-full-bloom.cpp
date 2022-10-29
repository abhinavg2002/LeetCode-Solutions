class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int, int>> v;
        int n=pt.size();
        for(int i=0;i<n;i++){
            v.push_back({gt[i], pt[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int ct=0;;
        int mx=0;
        for(int i=0;i<n;i++){
            ct+=v[i].second;
            mx=max(mx, ct+v[i].first);
        }
        return mx;
    }
};