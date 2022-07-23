class Solution {
public:
    int shortestSequence(vector<int>& r, int k) {
        map<int,int> d;
        int ct=0, s=0;
        for(auto x:r){
            if(d[x]==s){
                d[x]++;
                ct++;
                if(ct%k==0){
                    s++;
                }
            }
        }
        return s+1;
    }
};