class Solution {
public:
    vector<string> sortPeople(vector<string>& m, vector<int>& h) {
        vector<pair<string,int>> v;
        int n=m.size();
        for(int i=0;i<n;i++){
            v.push_back({m[i], h[i]});
        }
        sort(v.begin(), v.end(), [](pair<string,int> a, pair<string,int> b){
            return a.second>b.second; 
        });
        for(int i=0;i<n;i++){
            m[i]=v[i].first;
        }
        return m;
    }
};