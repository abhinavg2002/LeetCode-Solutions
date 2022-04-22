class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        if(*max_element(w.begin(), w.end())<*min_element(d.begin(), d.end()))return 0;
        int n=p.size();
        vector<pair<int, int>> v(n);
        v[0].first=d[0];
        v[0].second=p[0];
        for(int i=1;i<n;i++){
            v[i].first=d[i];
            v[i].second=p[i];
        }
        sort(v.begin(), v.end());
        vector<int> t;
        for(auto x:v){
            t.push_back(x.first);
        }
        for(int i=1;i<n;i++){
            v[i].second=max(v[i].second, v[i-1].second);
        }
        // for(auto x:v){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        int ans=0;
        for(auto x:w){
            auto i=upper_bound(t.begin(), t.end(), x);
            if(i!=t.begin()){
                i--;
                int id=i-t.begin();
                ans+=v[id].second;
            }
        }
        return ans;
    }
};