class Solution {
public:
    int mod=1e9+7;
    #define ll long long
    int modular_exponentiation(ll a, ll b, ll c){
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

        return (int)((ans+c)%c);
    }
    int numSubseq(vector<int>& a, int t) {
        int n=a.size();
        sort(a.begin(), a.end());
        long ans=0;
        for(int i=0;i<n;i++){
            int x=a[i];
            if(x>=t)break;
            int l=t-x;
            if(l<x)break;
            auto it=upper_bound(a.begin(), a.end(), l);
            it--;
            int id=it-a.begin();
            // min fix karne ke i+1 se max ke index tk ki length bachegi hamare pass 
            // jiske subsequence banane hai hme
            int no=id-i;
            ans+=modular_exponentiation(2, no, mod);
            ans%=mod;
        }
        return ans;
    }
};