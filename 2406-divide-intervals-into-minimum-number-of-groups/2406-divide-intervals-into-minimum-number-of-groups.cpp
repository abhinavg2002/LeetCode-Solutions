class Solution {
public:
    const int N=1e6+5;
    int minGroups(vector<vector<int>>& a) {
        multiset<int> s;
        sort(a.begin(), a.end());
        for(int i=0;i<a.size();i++){
            auto it=s.lower_bound(a[i][0]);
            if(it!=s.begin()){
                s.erase(prev(it));
            }
            s.insert(a[i][1]);
        }
        return s.size();
    }
};