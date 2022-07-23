#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>pbds;
class Solution {
public:
    vector<int> countSmaller(vector<int>& a) {
        pbds s;
        int n=a.size();
        vector<int> ct(n);
        for(int i=n-1;i>=0;i--){
            ct[i]=s.order_of_key({a[i], i});
            s.insert({a[i], i});     
        }
        return ct;
    }
};