class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n=a.size();
        int l=0, h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if((mid==0 or a[mid]>=a[mid-1]) and (mid==n-1 or a[mid]>=a[mid+1])){
                return mid;
            }else if(mid>0 and a[mid-1]>a[mid]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return 0;
    }
};