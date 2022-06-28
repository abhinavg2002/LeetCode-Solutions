class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        set<int> st;
        for(auto x:s){
            m[x]++;
        }
        int ans=0;
        for(auto x:m){
            int ct=x.second;
            while(ct>0){
                if(st.find(ct)==st.end()){
                    st.insert(ct);
                    break;
                }
                ct--;
                ans++;
            }
        }
        return ans;
    }
};