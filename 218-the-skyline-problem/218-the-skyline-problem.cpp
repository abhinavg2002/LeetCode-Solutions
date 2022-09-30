class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> v;
        for(auto b:buildings){
            v.push_back({b[0],-b[2]});
            v.push_back({b[1],b[2]});
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        multiset<int> m;
        int p=0, c=0;
        m.insert(0);
        for(auto x:v){
            if(x.second<0){
                m.insert(-x.second);
            }else{
                m.erase(m.find(x.second));
            }
            c=*m.rbegin();
            if(c!=p){
                ans.push_back({x.first, c});
                p=c;
            }
        }
        return ans;
    }
};