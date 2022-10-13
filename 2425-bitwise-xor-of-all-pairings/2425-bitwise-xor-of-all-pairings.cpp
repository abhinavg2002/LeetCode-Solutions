class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        // a[i] m baar and b[i] n baar
        int ans=0;
        for(int i=0;i<n;i++){
            if(m%2==0){
                a[i]=0;
            }
            ans^=(a[i]);
        }
        for(int i=0;i<m;i++){
            if(n%2==0){
                b[i]=0;
            }
            ans^=b[i];
        }
        return ans;
    }
};