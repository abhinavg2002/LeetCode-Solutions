class Solution {
public:
    int longestBeautifulSubstring(string s) {
        vector<pair<char,int>> v;
        int n=s.size();
        v.push_back({s[0], 1});
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                v.back().second++;
            }else{
                v.push_back({s[i], 1});
            }
        }
        // find a string aeiou
        string t;
        for(auto x:v){
            t.push_back(x.first);
        }
        string f="aeiou";
        auto it=t.find(f);
        int ans=0;
        while(it!=-1){
            int l=0;
            for(int i=0;i<5;i++){
                l+=v[it+i].second;
            }
            ans=max(ans, l);
            it=t.find(f, it+1);
        }
        return ans;
    }
};