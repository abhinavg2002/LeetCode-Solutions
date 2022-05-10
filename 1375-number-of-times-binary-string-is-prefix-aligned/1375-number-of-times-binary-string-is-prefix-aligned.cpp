class Solution {
public:
    int numTimesAllBlue(vector<int>& v) {
        multiset<int> s, t;
        vector<int> a=v;
        int ct=0;
        sort(a.begin(), a.end());
        int n=a.size();
        for(int i=0;i<n;i++){
            s.insert(v[i]);
            t.insert(a[i]);
            if(s==t){
                s.clear();
                t.clear();
                ct++;
            }
        }
        return ct;
    }
};