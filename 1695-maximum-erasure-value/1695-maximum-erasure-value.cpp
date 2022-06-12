class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int i=0, j=0;
        unordered_map<int, int> m;
        int n=a.size();
        vector<int> p=a;
        for(int i=1;i<n;i++){
            p[i]+=p[i-1];
        }
        int sum=0;
        int mx=0;
        while(j<n){
            if(m.count(a[j]) and m[a[j]]>=i){
                i=m[a[j]]+1;
                sum=p[j-1]-(i?p[i-1]:0);
            }
            m[a[j]]=j;
            sum+=a[j];
            mx=max(mx, sum);
            j++;
        }
        return mx;
    }
};