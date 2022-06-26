class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        
        int sum=0;
        
        int n=a.size();
        
        vector<int> pre(n, 0);
        
        pre[0]=a[0];
        
        int i=0, j=n-k-1;
        
        if(i>j)return accumulate(a.begin(), a.end(), 0);
        
        for(int m=1;m<n;m++){
            pre[m]=pre[m-1]+a[m];
        }
        
        int min_sum=pre[j];
        
        while(j+1<n){
            j++;i++;
            sum=pre[j]-pre[i-1];
            min_sum=min(min_sum, sum);
        }
        
        return accumulate(a.begin(), a.end(), 0)-min_sum;
    }
};