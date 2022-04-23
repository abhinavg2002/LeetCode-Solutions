class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[0]==target)
            return true;   
        int lo=0,hi=n-1,mid;
        while(lo<hi){
            mid=(lo+hi)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]<nums[hi]){
                if(nums[mid]<target&&nums[hi]>=target)
                    lo=mid+1;
                else
                    hi=mid;
            }
            else if(nums[mid]>nums[hi]){
                if(nums[mid]>target&&nums[lo]<=target)
                    hi=mid;
                else lo=mid+1;
            }
            else{
                hi--;
            }
        }
        return nums[lo]==target?true:false;
    }
};