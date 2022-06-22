class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        sort(a.begin(), a.end(), greater<int>());
        return a[k-1];
    }
};