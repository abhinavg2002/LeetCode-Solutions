class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(auto x:s){
            if(st.size()==0){
                st.push({x, 1});
                continue;
            }
            if(st.top().first==x){
                st.top().second++;
            }else{
                st.push({x, 1});
            }
            if(st.top().second==k){
                st.pop();
            }
        }
        string ans;
        while(st.size()){
            int x=st.top().second;
            char c=st.top().first;
            while(x--){
                ans.push_back(c);
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};