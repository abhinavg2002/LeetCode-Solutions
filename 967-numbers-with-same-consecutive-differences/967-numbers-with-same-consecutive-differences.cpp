class Solution {
public:
    vector<int> a;
    void fun(int n, int k, int d, int osf){
        if(d==n){
            a.push_back(osf);
            return;
        }
        
        int lst=osf%10;
        if(k){
            if(lst+k<10){
                fun(n, k, d+1, osf*10+lst+k);
            }
            if(lst-k>=0){
                fun(n, k, d+1, osf*10+(lst-k));
            }
        }else{
            fun(n, k, d+1, osf*10+lst);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            fun(n, k, 1, i);
        }
        return a;
    }
};