#define ll long long
const int N=3000001;
int dp[N];
class Solution {
public:
    int mod=1e9+7;
    int bits(int number){
        return (int)log2(number)+1;
    }
    
    ll modular_exponentiation(ll a, ll b, ll c){
        if(a==0)return 0;
        if(b==0)return 1;
        if(dp[b]!=-1)return dp[b];
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

        return dp[b]=(ll)((ans+c)%c);
    }
    int concatenatedBinary(int n) {
        vector<int> pos(n+1, 0);
        memset(dp,-1,sizeof(dp));
        for(int i=n-1;i>=1;i--){
            pos[i]=pos[i+1];
            pos[i]+=bits(i+1);
        }
        // final ans if i from 1 to n sigma i*(pow(2, pos[i]))%mod;
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=(1ll*i*(modular_exponentiation(2, pos[i], mod)))%mod;
        }
        return ans%=mod;
    }
};