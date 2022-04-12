class Solution {
public:
    int totalMoney(int n) {
        int ans=0,s=1;
        while(n>0){
            for(int i=0;i<7 and n--;i++){
                ans+=(s+i);
            }
            s++;
        }
        return ans;
    }
};