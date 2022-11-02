class Solution {
public:
    int minMutation(string start, string end, vector<string>& b) {
        set<string> bank(b.begin(), b.end());
        char c[]={'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(start);
        unordered_set<string> vis;
        vis.insert(start);
        int ans=0;
        while(q.size()){
            int s=q.size();
            while(s--){
                auto x=q.front();
                q.pop();
                if(x==end)return ans;
                char o;
                for(auto &ch:x){
                    o=ch;
                    for(int i=0;i<4;i++){
                        if(c[i]==o)continue;
                        ch=c[i];
                        if(vis.count(x) or !bank.count(x))continue;
                        q.push(x);
                        vis.insert(x);
                    }
                    ch=o;
                }
            }
            ans++;
        }
        return -1;
    }
};