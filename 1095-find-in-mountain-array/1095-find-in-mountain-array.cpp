/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeakId(MountainArray &a){
        int n=a.length();
        int l=1, h=n-2;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int left=a.get(mid-1), v=a.get(mid), r=a.get(mid+1);
            if(left<v and v>r){
                ans=mid;break;
            }
            else if(left<v and r>v){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
    int bsR(int x, MountainArray &a, int l, int r){
        if(l<=r){
            int mid=l+(r-l)/2;
            int v=a.get(mid);
            if(v==x)return mid;
            if(v<x){
                return bsR(x, a, l, mid-1);
            }else{
                return bsR(x, a, mid+1, r);
            }
        }
        return -1;
    }
    int bs(int x, MountainArray &a, int l, int r){
        if(l<=r){
            int mid=l+(r-l)/2;
            int v=a.get(mid);
            if(v==x)return mid;
            if(v<x){
                return bs(x, a, mid+1, r);
            }else{
                return bs(x, a, l, mid-1);
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &a) {
        int id=findPeakId(a);
        int n=a.length();
        int l=bs(target, a, 0, id);
        int r=bsR(target, a, id+1, n-1);
        if(l!=-1)return l;
        return r;
    }
};