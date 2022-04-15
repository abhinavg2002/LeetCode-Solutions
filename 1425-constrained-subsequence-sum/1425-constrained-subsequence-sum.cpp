class Solution {
public:
    int constrainedSubsetSum(vector<int>& v, int k) {
        int n=v.size();
        vector<int> dp(n, 0);
        multiset<int> s;// will contain our window and use islie kia coz hme max chaiye tha
        int j=0;// window start
        for(int i=0;i<n;i++){
            dp[i]=v[i];
            // agr window me kuch elements hai
            if(s.size()){
                dp[i]+=max(0, *s.rbegin());
            }
            // agr window ka size k ya usse bada hai to window ko km karo and = islie coz current element abhi add hoga islie km karo
            if(s.size()>=k){
                s.erase(s.find(dp[j++]));
            }
            // naya ans add kardo window me
            s.insert(dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};