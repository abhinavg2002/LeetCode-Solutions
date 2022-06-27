class Solution {
public:
    int minPartitions(string a) {
        int mx=0;
        for(auto x:a){
            mx=max(mx, (x-'0'));
            // if(mx==9)break;
        }
        return mx;
    }
};