class Solution {
public:
    vector<int> v;
    int lon=0;
    int fun(vector<vector<int>>&g, string &s, int node){
        char c=s[node];
        int l=1;
        // basically har node ki max depth nikalo
        for(auto x:g[node]){
            if(s[x]!=c){
                l=max(l, 1+fun(g, s, x));
            }else{
                fun(g, s, x);
            }
        }
        // and global variable me maan lo agr path har node se ja rha hai to node ke top to lengthy child leo and global len se max karlo
        priority_queue<int> p;
        for(auto x:g[node]){
            if(s[x]!=c)
            p.push(v[x]);
        }
        int ans=1;
        if(p.size()){
            ans+=p.top();p.pop();
        }
        if(p.size()){
            ans+=p.top();p.pop();
        }
        lon=max({ans, lon, l});
        return v[node]=l;
    }
    int longestPath(vector<int>& p, string s) {
        int n=p.size();
        v.assign(n, 1);
        vector<vector<int>> l(n);
        for(int i=1;i<n;i++){
            l[p[i]].push_back(i);
        }
        fun(l, s, 0);
        return lon;
    }
};