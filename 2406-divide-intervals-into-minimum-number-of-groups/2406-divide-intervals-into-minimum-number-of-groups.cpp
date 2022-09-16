class Solution {
public:
    const int N=1e6+5;
    int minGroups(vector<vector<int>>& a) {
        vector<int> p(N,0);
        for(auto x:a){
            p[x[0]]++;
            p[x[1]+1]--;
        }
        for(int i=1;i<N;i++){
            p[i]+=p[i-1];
        }
        return *max_element(p.begin(), p.end());
    }
};