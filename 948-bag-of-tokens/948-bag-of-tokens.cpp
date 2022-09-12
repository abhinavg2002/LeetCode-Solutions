class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());
        int i=0, j=n-1;
        int score=0;
        int max_s=0;
        while(i<=j){
            if(score>=1 and p<tokens[i]){
                if(score>max_s)max_s=score;
                score--;
                p+=tokens[j--];
            }else if(p>=tokens[i]){
                p-=tokens[i++];
                score++;
            }else{
                return max_s;
            }
        }
        return max(score, max_s);
    }
};