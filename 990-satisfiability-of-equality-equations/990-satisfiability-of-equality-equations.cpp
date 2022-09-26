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
    bool equationsPossible(vector<string>& e) {
        dsu u(26);
        for(auto x:e){
            if(x[1]=='='){
                u.unite(x[0]-'a', x[3]-'a');
            }
        }
        for(auto x:e){
            if(x[1]=='!'){
                if(u.find_parent(x[0]-'a')==u.find_parent(x[3]-'a'))return false;
            }
        }
        return true;
    }
};