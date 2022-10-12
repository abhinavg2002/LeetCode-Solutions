#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
#define ll long long
typedef pair<ll, ll> pii; 

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    // a[i]<=a[j]+d
    long long numberOfPairs(vector<int>& n1, vector<int>& n2, int d) {
        int n=n1.size();
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i]=n1[i]-n2[i];
        }
        pbds s;
        long long ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=(s.size())-s.order_of_key({a[i]-d, -1});
            s.insert({a[i], i});
        }
        return ans;
    }
};