class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        int l=0, r=n-1;
        
        while(l<r){
            int mid=l+(r-l)/2;
            if(mid%2){
                if(a[mid]!=a[mid-1]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            }else{
                if(a[mid]!=a[mid+1]){
                    // l=mid+1;
                    r=mid;
                }else{
                    // r=mid;
                    l=mid+1;
                }
            }
        }
        return a[l];
    }
};