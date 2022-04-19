class Solution {
public:
    int hIndex(vector<int>& a) {
        int n=a.size();
        int i=0, j=n-1;
        int ans=1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(a[mid]==n-mid){
                return a[mid];
            }else{
                if(a[mid]>n-mid){
                    j=mid-1;
                }else{
                    i=mid+1;
                }
            }
        }
        return n-j-1;
    }
};