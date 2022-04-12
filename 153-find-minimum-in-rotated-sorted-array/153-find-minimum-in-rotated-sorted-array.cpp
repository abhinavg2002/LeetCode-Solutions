class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int l=0, h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(a[mid]<=a[prev] and a[mid]<=a[next])return a[mid];
            else if(a[mid]<=a[h]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return 0;
    }
};