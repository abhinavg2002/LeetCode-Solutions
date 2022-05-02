class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n=a.size();
        int i=0, j=n-1;
        while(i<=j){
            if(a[i]%2==0){
                i++;
            }else{
                swap(a[i], a[j]);
                j--;
            }
        }
        return a;
    }
};