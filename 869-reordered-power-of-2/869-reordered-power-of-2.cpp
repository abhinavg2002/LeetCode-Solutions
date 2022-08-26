long long no(vector<int>&a){
    long long n=0;
    for(auto x:a){
        n=n*10+x;
    }
    if(floor(log2(n))==ceil(log2(n)))return true;
    return false;
}
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> a;
        while(n){
            a.push_back(n%10);n/=10;
        }
        sort(a.begin(), a.end());
        do{
            if(a[0]==0)continue;
            if(no(a))return true;
        }while(next_permutation(a.begin(), a.end()));
        return false;
    }
};