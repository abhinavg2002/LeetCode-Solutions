class Solution {
public:
    void fun(vector<pair<int, int>> l[], int n, vector<int>&ans, vector<int>&dis){
        queue<pair<int, int>> q, p;
        q.push({0, -1});
        dis[0]=0;
        int d=0;
        set<pair<int, int>> vis;
        while(q.size()){
            int s=q.size();
            d++;
            while(s--){
                auto node=q.front();
                q.pop();
                // cout<<node.first<<" "<<node.second<<endl;
                if(node.second==-1){
                    for(auto x:l[node.first]){
                        dis[x.first]=min(dis[x.first], d);
                        q.push(x);
                    }
                }else{
                    int le=node.second;
                    for(auto x:l[node.first]){
                        if(le==(x.second^1) and vis.count({x.first, le})==0){
                            vis.insert({x.first, le});
                            dis[x.first]=min(dis[x.first], d);
                            q.push(x);
                        }
                    }
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector<pair<int, int>> l[n+1];
        // red-1, blue-0
        for(auto x:re){
            l[x[0]].push_back({x[1], 1});
        }
        for(auto x:be){
            l[x[0]].push_back({x[1], 0});
        }
        vector<int> ans(n, -1);
        vector<int> dis(n, INT_MAX);
        fun(l, n, ans, dis);
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX)continue;
            ans[i]=dis[i];
        }
        return ans;
    }
};