class Solution {
public:
    int largestInteger(int n) {
        string s=to_string(n);
        vector<char> a, b;
        for(auto x:s){
            int v=x-'0';
            if(v&1){
                a.push_back(x);
            }else{
                b.push_back(x);
            }
        }
        sort(a.begin(), a.end());        
        sort(b.begin(), b.end());
        int i=0, j=0;
        string ans;
        for(auto x:s){
            int v=x-'0';
            if(v&1){
                ans.push_back(a.back());
                a.pop_back();
            }else{
                ans.push_back(b.back());
                b.pop_back();
            }
        }
        return stoi(ans);
    }
};