bool check(vector<int> &a, int n, int m, int k, int mid){
    vector<int> v(n);
    for(int i=0;i<n;i++){
        if(a[i]<=mid){
            v[i]=1;
        }else{
            v[i]=0;
        }
    }
    int no=0, ct=0;
    for(int i=0;i<n;i++){
        if(v[i]==1){
            ct++;
            if(ct==k){
                no++;
                ct=0;
            }
        }else{
            if(ct==k){
                no++;
            }
            ct=0;
        }
    }
    //cout<<ct<<endl;
    return no>=m;
}

class Solution {
public:
    int minDays(vector<int>& a, int m, int k) {
        int n=a.size();
        //cout<<n<<" "<<m<<" "<<k<<endl;
        if(m*k>n)return -1;
        int l=0, h=*max_element(a.begin(), a.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(a, n, m, k, mid)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};