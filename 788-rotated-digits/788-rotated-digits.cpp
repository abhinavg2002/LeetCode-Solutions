class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> a={1,1,2,0,0,2,2,0,1,2};
        int ct=0;
        for(int i=1;i<=n;i++){
            int v=1;
            int p=i;
            while(p){
                v*=a[p%10];
                p/=10;
            }
            ct+=(v>=2);
        }
        return ct;
    }
};