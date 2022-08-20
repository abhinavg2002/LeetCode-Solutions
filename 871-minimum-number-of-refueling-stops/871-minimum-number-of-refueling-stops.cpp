class Solution {
public:
    int minRefuelStops(int t, int sf, vector<vector<int>>& st) {
        int cf=sf;
        int n=st.size();
        priority_queue<int> q;
        sort(st.begin(), st.end());
        int i=0, ans=0;
        while(cf<t){
            while(i<n and cf>=st[i][0]){
                q.push(st[i][1]);
                i++;
            }
            if(q.size()==0){
                return -1;
            }
            cf+=q.top();q.pop();
            ans++;
        }
        return ans;
    }
};