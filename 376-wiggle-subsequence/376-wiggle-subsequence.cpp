class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n=a.size();
        vector<int> u(n), d(n);
        d[0]=1, u[0]=1;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                u[i]=u[i-1];
                d[i]=u[i-1]+1;
            }
            else if(a[i]>a[i-1]){
                u[i]=d[i-1]+1;
                d[i]=d[i-1];
            }else{
                d[i]=d[i-1];
                u[i]=u[i-1];
            }
        }
        return max(d[n-1], u[n-1]);
    }
};