class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        int n=a.size();
        long long p=0, s=accumulate(a.begin(), a.end(), 0ll);
        if(n==1){
            return 0;
        }
        long long ans=1e18;
        int ct=0;
        int id;
        for(long long i=0;i<n;i++){
            p+=a[i];
            s-=a[i];
            ct++;
            long long d;
            if(ct==n){
                d=p/ct;
            }else{
                d=abs((p/ct)-(s/(n-ct)));
            }
            if(ans>d){
                ans=d;
                id=i;
            }
        }
        return id;
    }
};