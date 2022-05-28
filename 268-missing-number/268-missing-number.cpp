class Solution {
public:
    int missingNumber(vector<int>& v) {
        int x=v.size();
        for(int i=0;i<v.size();i++){
            x^=i;
            x^=v[i];
        }
        return x;
    }
};