class Solution {
public:
    int largestValsFromLabels(vector<int>& vl, vector<int>& l, int nw, int ul) {
        int n=vl.size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            v.push_back({vl[i], l[i]});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        map<int, int> m;
        int ans=0, s=0;
        for(int i=0;i<n and s<nw;i++){
            if(m[v[i].second]<ul){
                m[v[i].second]++;
                ans+=v[i].first;
                s++;
            }
        }
        return ans;
    }
};