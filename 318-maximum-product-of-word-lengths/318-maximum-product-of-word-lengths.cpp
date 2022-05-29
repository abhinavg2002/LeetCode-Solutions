class Solution {
public:
    int maxProduct(vector<string>& words) {
        map<string, int> m;
        for(auto &x:words){
            int mask=0;
            if(m.count(x)==0){
                for(auto y:x){
                    mask|=(1<<(y-'a'));
                }
                m[x]=mask;
            }
        }
        vector<pair<int, int>> v;
        for(auto &x:m){
            v.push_back({x.first.size(), x.second});
        }
        int ans=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((v[i].second&v[j].second)==0){
                    ans=max(ans, v[i].first*v[j].first);
                }
            }
        }
        return ans;
    }
};