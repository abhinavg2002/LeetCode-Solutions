class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        int n=r.size();
        vector<int> ans(n, -1);
        set<int> z;
        map<int,set<int>> m;
        for(int i=0;i<n;i++){
            if(r[i]==0){
                z.insert(i);
            }else{
                if(m[r[i]].size()){
                    int id=*(m[r[i]].begin());
                    auto it=z.upper_bound(id);
                    if(it==z.end())return {};
                    ans[*it]=r[i];
                    z.erase(it);
                    m[r[i]].clear();
                }
                m[r[i]].insert(i);
            }
        }
        for(int i=0;i<n;i++){
            if(r[i]==0 and ans[i]==-1){
                ans[i]=1;
            }
        }
        return ans;
    }
};