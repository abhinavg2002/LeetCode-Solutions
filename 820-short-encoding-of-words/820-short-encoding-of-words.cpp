class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &x:words){
            reverse(x.begin(), x.end());
        }
        sort(words.begin(), words.end());
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            if(words[i]!=words[i+1].substr(0, words[i].size())){
                ans+=words[i].size()+1;
                // cout<<words[i].size()+1<<endl;
            }
        }
        return ans+words.back().size()+1;
    }
};