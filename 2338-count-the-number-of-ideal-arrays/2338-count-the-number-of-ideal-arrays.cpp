#define ll long long
const int N=30005;
const int mod=1e9+7;
// storing factorial of numbers with mod
ll fact[N];
// storing inverse factorial of numbers with mod
ll fact_inv[N];

ll modular_exponentiation(ll a, ll b, ll c){
    if(a==0)return 0;
    if(b==0)return 1;
    ll ans;
    if(b%2==0){
        ll small_ans=modular_exponentiation(a, b/2, c);

        ans=(small_ans*small_ans)%c;
    }
    else{
        ll small_ans=modular_exponentiation(a, b-1, c);
        ans=a%c;
        ans=(ans*small_ans)%c;
    }

    return (ll)((ans+c)%c);
}

// calculate mod inverse using fermat little theorem if p is prime
ll mod_inverse(int n, int p){
    return modular_exponentiation(n, p-2, p);
}

// function to pre calculate factorial of numbers
void fact_calc() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    fact_inv[N - 1] = mod_inverse(fact[N - 1], mod);
    for (ll i = N - 2; i >= 0; i--) {
        fact_inv[i] = (fact_inv[i + 1] * (i + 1)) % mod;
    }
}

// main function to calculate ncr
int ncr(int n, int r){
    if(r>n)return 0;
    return (fact[n]*((fact_inv[r]*fact_inv[n-r])%mod))%mod;
}
class Solution {
public:
    const int L=20;
    int idealArrays(int n, int mv) {
        fact_calc();
        ll dp[mv+1][L];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=mv;i++){
            dp[i][1]=1;
        }
        auto factorize = [&](int x){
            // take all factors except the number itself
            vector<int> res;
            if(x > 1){
                res.push_back(1);
            }
            for(int i=2;i*i<=x;i++){
                if(x%i == 0){
                    res.push_back(i);
                    if(i != x/i){
                        res.push_back(x/i);
                    }
                }
            }
            return res;
        };
        for(int i=1;i<=mv;i++){
            vector<int> f=factorize(i);
            for(int j=2;j<L;j++){
                for(auto x:f){
                    dp[i][j]+=dp[x][j-1];
                    dp[i][j]%=mod;
                }
            }
        }
        ll ans=0;
        for(int i=1;i<=mv;i++){
            ll temp=0;
            for(int j=1;j<min(n+1, L);j++){
                ll ways=ncr(n-1, j-1);
                temp+=1ll*ways*dp[i][j];
                temp%=mod;
            }
            ans+=temp;
            ans%=mod;
        }
        return ans;
    }
};