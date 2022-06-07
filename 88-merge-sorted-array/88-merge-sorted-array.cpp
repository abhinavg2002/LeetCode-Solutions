class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> v(n+m);
        int i=0, j=0, k=0;
        while(i<m and j<n){
            if(a[i]<=b[j])v[k++]=a[i++];
            else{
                v[k++]=b[j++];
            }
        }
        
        while(i<m)v[k++]=a[i++];
        while(j<n)v[k++]=b[j++];
        k=0;
        for(auto x:v){
            a[k++]=x;
        }
    }
};