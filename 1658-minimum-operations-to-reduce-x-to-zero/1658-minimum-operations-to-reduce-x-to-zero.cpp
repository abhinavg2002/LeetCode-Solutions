class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        long long s=accumulate(a.begin(), a.end(), 0LL);
        long long req=s-x;
        // need to find a largest window with req sum in a vector
        int i=0, j=0;
        long long sum=0;
        int mx=-1;
        int n=a.size();
        while(j<n){
            sum+=a[j];
            while(sum>req and i<=j){
                sum-=a[i];
                i++;
            }
            if(sum==req){
                mx=max(mx, j-i+1);
            }
            j++;
        }
        if(mx==-1)return mx;
        return a.size()-mx;
    }
};