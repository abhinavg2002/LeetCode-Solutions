class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        unordered_map<int, int> m;
        int n=v.size();
        for(int i=0;i<=min(k, n-1);i++){
            if(m.count(v[i]))return true;
            m[v[i]]++;
        }
        for(int i=k+1;i<n;i++){
            m[v[i-(k+1)]]--;
            if(m[v[i-(k+1)]]==0)m.erase(v[i-(k+1)]);
            if(m.count(v[i]))return true;
            m[v[i]]++;
        }
        return false;
    }
};