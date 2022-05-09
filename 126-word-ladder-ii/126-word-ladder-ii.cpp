class Solution {
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        unordered_map<string, int> m;
        for(auto &x:wl){
            m[x]=1e9;
        }
        m[bw]=0;
        vector<vector<string>> ans;
        queue<pair<string, vector<string>>>q;
        q.push({bw, {bw}});
        while(q.size()){
            int s=q.size();
            while(s--){
                auto p=q.front();
                q.pop();
                string w=p.first;
                auto v=p.second;
                if(w==ew){
                    ans.push_back(v);
                    continue;
                }
                for(auto &x:w){
                    char o=x;
                    for(char c='a';c<='z';c++){
                        x=c;
                        if(x==o or w==bw or m.count(w)==0 or m[w]<(int)v.size()){
                            continue;
                        }
                        m[w]=v.size();
                        v.push_back(w);
                        q.push({w, v});
                        v.pop_back();
                    }
                    x=o;
                }
            }
        }
        return ans;
    }
};