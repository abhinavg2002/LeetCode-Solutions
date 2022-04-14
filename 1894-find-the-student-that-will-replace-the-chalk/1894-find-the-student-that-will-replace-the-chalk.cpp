class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        long long sum=accumulate(a.begin(), a.end(), 0LL);
        k%=sum;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]<=k){
                k-=a[i];
            }else{
                return i;
            }
        }
        return 0;
    }
};