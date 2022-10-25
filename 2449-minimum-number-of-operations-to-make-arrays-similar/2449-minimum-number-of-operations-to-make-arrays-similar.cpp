class Solution {
public:
    #define ll long long
    void p(vector<int> a){
        for(auto x:a)cout<<x<<" ";
        cout<<endl;
    }
    ll fun(vector<int> a, vector<int> b, ll &dc, ll &ic){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int n=a.size();
        ll ct=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i])continue;
            if(a[i]<b[i]){
                // we have to increase a[i]
                ll req=(b[i]-a[i])/2;
                if(ic){
                    ll mn=min(req, ic);
                    ic-=mn;
                    req-=mn;
                }
                if(req){
                    ct+=req;
                    dc+=req;
                }
            }else{
                // we have to decrease a[i];
                ll req=(a[i]-b[i])/2;
                if(dc){
                    ll mn=min(req, dc);
                    dc-=mn;
                    req-=mn;
                }
                if(req){
                    ct+=req;
                    ic+=req;
                }
            }
        }
        return ct;
    }
    long long makeSimilar(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<int> oa, ea, eb, ob;
        for(int i=0;i<n;i++){
            if(a[i]%2){
                oa.push_back(a[i]);
            }else{
                ea.push_back(a[i]);
            }
            if(b[i]%2){
                ob.push_back(b[i]);
            }else{
                eb.push_back(b[i]);
            }
        }
        ll dc=0, ic=0;
        return fun(oa, ob, dc, ic)+fun(ea, eb, dc, ic);
    }
};