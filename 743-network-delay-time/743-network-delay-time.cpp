class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> l(n+1);
        for(auto x:times){
            l[x[0]].push_back({x[2], x[1]});
        }
        vector<int> dist(n+1, INT_MAX);
        set<pair<int, int>> s;
        dist[k]=0;
        s.insert({0, k});
        while(!s.empty()){
            auto it=s.begin();
            int node=it->second;
            int dtn=it->first;
            s.erase(it);
            for(auto x:l[node]){
                int nbr=x.second;
                int edge=x.first;
                if(dtn+edge<dist[nbr]){
                    auto f=s.find({dist[nbr], nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbr]=dtn+edge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }
        // cout<<endl;
        int mx=*max_element(dist.begin()+1, dist.end());
        if(mx==INT_MAX)return -1;
        return mx;
    }
};