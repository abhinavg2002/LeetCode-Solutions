class Solution {
public:
    int shortestSequence(vector<int>& r, int k) {
        map<int,int> m;
        int ct=0, s=0;
        for(auto x:r){
            m[x]++;
            if(m.size()==k){
                m.clear();
                s++;
            }
        }
        return s+1;
    }
};