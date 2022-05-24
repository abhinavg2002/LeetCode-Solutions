class Solution {
public:
    int smallestChair(vector<vector<int>>& t, int f) {
        int ft=t[f][0];
        sort(t.begin(), t.end(), [](vector<int>&a, vector<int>&b){
            return a[0]<b[0];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        int n=0;
        set<int> s;
        for(auto x:t){
            int at=x[0], lt=x[1];
            while(p.size() and p.top().first<=at){
                s.insert(p.top().second);
                p.pop();
            }
            int cs=-1;
            if(s.size()){
                cs=*s.begin();
                s.erase(s.begin());
            }else{
                cs=n;
                n++;
            }
            p.push({lt, cs});
            if(at==ft){
                return cs;
            }
        }
        return -1;
    }
};