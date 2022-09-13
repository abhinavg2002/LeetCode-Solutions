/*
(sum of speed of k engineers)*(min effiency out of these k engineers)
10 8 5 3 2 1
 4 2 7 3 5 9
 
 1 5 2 10 3 8
 9 7 5  4 3 2
*/
class Solution {
public:
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& ss, vector<int>& e, int k) {
        vector<pair<int,int>> c;
        for(int i=0;i<n;i++){
            c.push_back({e[i], ss[i]});
        }
        sort(c.rbegin(), c.rend());
        multiset<int> s;
        long long sp=0, ans=0;
        for(auto x:c){
            sp+=x.second;
            s.insert(x.second);
            if(s.size()>k){
                int sm=*s.begin();
                sp-=sm;
                s.erase(s.find(sm));
            }
            ans=max(ans, 1ll*sp*x.first);
        }
        return ans%mod;
    }
};