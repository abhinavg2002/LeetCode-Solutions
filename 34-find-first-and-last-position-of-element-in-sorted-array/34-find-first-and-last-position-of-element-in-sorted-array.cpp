int first(vector<int>& a, int x, int n){
    int s=0, e=n-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==x){
            res=mid;
            e=mid-1;
        }else if(a[mid]>x){// x is small
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return res;
}

int last(vector<int>& a, int x, int n){
    int s=0, e=n-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==x){
            res=mid;
            s=mid+1;
        }else if(a[mid]>x){// x is small
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return res;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int x) {
        int n=a.size();
        int f=first(a, x, n);
        int l=last(a, x, n);
        return {f, l};
    }
};