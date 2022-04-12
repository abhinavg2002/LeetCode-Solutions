class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size();
        int i=0, j=n-1;
        // width -> j-i
        long mx=0;
        while(i<j){
            int h=min(a[i], a[j]);
            // /long water=h*(j-i);
            mx=max(mx,(long) h*(j-i));
            while(i<j and a[j]<=h)j--;
            while(i<j and a[i]<=h)i++;
        }
        return mx;
    }
};