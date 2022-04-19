class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        long long ans=0, mx=0;
        set<int> s(a.begin(), a.end());
        int n=a.size();
        for(int i=0;i<n;i++){
            long long diff=abs(a[i]-b[i]);
            ans+=diff;
            if(mx<diff){
                auto it=s.lower_bound(b[i]);
                if(it!=s.end()){
                    mx=max(mx,diff-abs((long long)(*it-b[i])));
                }
                if(it!=s.begin()){
                    it--;
                    mx=max(mx,diff- abs((long long)(*it-b[i])));
                }
            }
        }
        return (ans-mx)%(1000000007);
    }
};