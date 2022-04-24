class Solution {
public:
    vector<int> intersection(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<int> v=a[0];
        set<int> s(v.begin(), v.end());
        for(int i=1;i<n;i++){
            set<int> t;
            for(auto x:a[i]){
                if(s.count(x)){
                    t.insert(x);
                }
            }
            s=t;
        }
        return vector<int>(s.begin(), s.end());
    }
};