class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> m(a.begin(), a.end());
        int mx=0;
        for(auto x:a){
            if(m.find(x)!=m.end()){
                m.erase(x);
                int ct=1;
                int nxt=x+1;
                int pr=x-1;
                while(m.find(nxt)!=m.end()){
                    ct++;
                    m.erase(nxt++);
                }
                while(m.find(pr)!=m.end()){
                    ct++;
                    m.erase(pr--);
                }
                mx=max(mx, ct);
            }
        }
        return mx;
    }
};