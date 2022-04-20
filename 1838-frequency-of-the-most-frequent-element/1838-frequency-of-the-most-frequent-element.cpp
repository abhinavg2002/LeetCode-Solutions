class Solution {
public:
    int maxFrequency(vector<int>& a, long k) {
        int n=a.size();
        // cout<<n<<endl;
        sort(a.begin(), a.end());
        int i=0, j;
        for(j=0;j<n;j++){
            k+=a[j];
            if(k<(long)((long)a[j]*(long)(j-i+1))){
                k-=a[i++];
            }
        }
        return j-i;
    }
};