class Solution {
public:
    int largestVariance(string s) {
        int n=s.size();
        int ans=0;
        for(char c='a';c<='z';c++){
            for(char d='a';d<='z';d++){
                if(c==d)continue;
                int f=0;
                int cc=0, cd=0;
                for(auto x:s){
                    cc+=(x==c);
                    cd+=(x==d);
                    if(cd>0){
                        ans=max(ans, cc-cd);
                    }else if(cd==0 and f){
                        ans=max(ans, cc-cd-1);
                    }
                    if(cd>cc){
                        cd=cc=0;
                        f=1;
                    }
                }
            }
        }
        return ans;
    }
};