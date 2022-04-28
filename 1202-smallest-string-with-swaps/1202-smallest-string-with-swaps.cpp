class dsu{
    public:
    vector<int> p;
    vector<int> s;
    dsu(int n){
        p.resize(n);
        s.resize(n);
        fill(s.begin(), s.end(), 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        if(x==p[x])return x;
        return p[x]=find(p[x]);
    }
    void unite(int x, int y){
        int a=find(x);
        int b=find(y);
        if(a!=b){
            if(s[a]<s[b])swap(a, b);
            s[a]+=b;
            p[b]=a;
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        dsu un(n);
        // cout<<"HI\n";
        for(auto x:pairs){
            un.unite(x[0], x[1]);
        }
        vector<vector<int>> v(n);
        // har parent ke correponding uski idx rakhlo
        for(int i=0;i<n;i++){
            v[un.find(i)].push_back(i);
        }
        // har parent pe jao uske index ke char ko rakho sort karo and wapis string me daal do
        for(auto x:v){
            string t="";
            for(auto id:x){
                t.push_back(s[id]);
            }
            sort(t.begin(), t.end());
            for(int i=0;i<x.size();i++){
                s[x[i]]=t[i];
            }
        }
        return s;
    }
};