class dsu{
public:
    // p vector for storing parent of each node
    // s vector for storing size of tree
    vector<int> parent, size;
    dsu(int n){
        parent.resize(n);iota(parent.begin(), parent.end() , 0);
        size.resize(n);fill(size.begin(), size.end() , 1);
    }   
    int find_parent(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find_parent(parent[x]);
    }
    void unite(int x, int y){
        int a=find_parent(x);
        int b=find_parent(y);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a, b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
class Solution {
public:
    vector<vector<int>> l;
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        l.resize(n);
        for(auto x:edges){
            if(vals[x[0]]>=vals[x[1]]){
                l[x[0]].push_back(x[1]);
            }else{
                l[x[1]].push_back(x[0]);
            }
        }
        map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[vals[i]].push_back(i);
        }
        dsu u(n);
        int ans=0;
        for(auto x:m){
            
            for(auto ut:x.second){
                for(auto v:l[ut]){
                    u.unite(ut,v);
                }
            }
            unordered_map<int,int> g;
            for(auto ut:x.second){
                g[u.find_parent(ut)]++;
            }
            ans+=x.second.size();
            for(auto &[a, b]:g){
                ans+=(b*(b-1))/2;
            }
        }
        return ans;
    }
};