class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string,int> m;
        int n=s.size();
        if(n<k)return false;
        string t;
        for(int i=0;i<k;i++){
            t.push_back(s[i]);
        }
        m[t]++;
        for(int i=k;i<n;i++){
            t.push_back(s[i]);
            t.erase(t.begin());
            m[t]++;
        }
        return m.size()==(1<<k);
    }
};