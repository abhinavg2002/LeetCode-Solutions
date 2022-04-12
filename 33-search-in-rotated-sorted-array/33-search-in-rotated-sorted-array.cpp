class Solution {
public:
    int search(vector<int>& a, int x) {
        int n=a.size();
        int i=0, l=n-1;
        int id=0;
        while(i<=l){
            int mid=i+(l-i)/2;
            int next=(mid+1)%n;
            int pre=(mid-1+n)%n;
            if(a[mid]<=a[pre] and a[mid]<=a[next]){
                id=mid;
                break;
            }else if(a[mid]<=a[l]){
                l=mid-1;
            }else{
                i=mid+1;
            }
        }
        int pre=(id-1+n)%n;
        if(binary_search(a.begin(), a.begin()+id, x)){
            return lower_bound(a.begin(), a.begin()+id, x)-a.begin();
        }else if(binary_search(a.begin()+id, a.end(), x)){
            return lower_bound(a.begin()+id, a.end(), x)-a.begin();
        }
        return -1;
    }
};