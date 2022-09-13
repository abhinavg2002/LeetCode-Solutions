class Solution {
public:
    #define ll long long
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long b) {
        ll i=0, s=0;
        int n=ct.size();
        multiset<int> m;
        for(ll j=0;j<n;j++){
            s+=rc[j];
            m.insert(ct[j]);
            if((*m.rbegin())+s*(j-i+1)>b){
                s-=rc[i];
                m.erase(m.find(ct[i]));
                i++;
            }
        }
        return n-i;
    }
};