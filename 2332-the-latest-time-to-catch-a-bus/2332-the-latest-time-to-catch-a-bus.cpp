class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int c) {
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        int n=b.size();
        int m=p.size();
        set<int> s(p.begin(), p.end());
        int ans=0;
        for(int i=0, j=0;i<n;i++){
            int ct=0;
            while(ct<c and j<m and p[j]<=b[i]){
                ct++;
                if(s.count(p[j]-1)==0){
                    ans=p[j]-1;
                }
                j++;
            }
            if(ct<c){
                int cb=b[i];
                while(s.count(cb))cb--;
                ans=max(ans, cb);
            }
        }
        return ans;
    }
};