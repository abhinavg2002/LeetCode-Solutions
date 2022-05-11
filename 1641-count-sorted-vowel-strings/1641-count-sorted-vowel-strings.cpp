long long ans=0;
char v[]={'a', 'e', 'i', 'o', 'u'};
void s(int i, int n, int l, char last){
    if(l==n){
        ans++;
        return;
    }
    for(int j=0;j<5;j++){
        if(v[j]>=last){
            s(j, n, l+1, v[j]);
        }
    }
}

class Solution {
public:
    int countVowelStrings(int n) {
        ans=0;
        s(0, n, 0, 'a');
        return ans;
    }
};