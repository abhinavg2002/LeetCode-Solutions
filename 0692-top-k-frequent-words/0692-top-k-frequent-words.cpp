class Solution {
public:
    vector<string> topKFrequent(vector<string>& w, int k) {
        map<string, int> m;
        for(auto x:w){
            m[x]++;
        }
        auto c=[&](string &a, string &b){
            if(m[a]==m[b]){
                return a<b;
            }
            return m[a]>m[b];
        };
        sort(w.begin(), w.end(), c);
        
        vector<string> ans;
        ans.push_back(w[0]);
        for(int i=1;i<w.size() and ans.size()<k;i++){
            if(w[i]==w[i-1]){
                continue;
            }else{
                ans.push_back(w[i]);
            }
        }
        return ans;
    }
};