class ATM {
public:
    #define ll long long
    // 20,50,100,200,500
    map<int,ll> m;
    vector<int> nt={20,50,100,200,500};
    ATM() {
        
    }
    
    void deposit(vector<int> c) {
        for(int i=0;i<5;i++){
            m[nt[i]]+=c[i];
        }
    }
    
    vector<int> withdraw(int a) {
        vector<int> ans(5);
        map<int, ll> old=m;
        // for(auto x:m){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        for(int i=4;i>=0;i--){
            ll v=a/nt[i];
            ll mn=min(v, m[nt[i]]);
            ans[i]=mn;
            a-=(1ll*mn*nt[i]);
            m[nt[i]]-=mn;
        }
        if(a){
            m=old;
            return {-1};
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */