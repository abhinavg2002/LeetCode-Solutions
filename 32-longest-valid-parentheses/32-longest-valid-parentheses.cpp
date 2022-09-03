class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> a;
        int n=s.size();
        for(int i=0;i<n;i++){
            char x=s[i];
            if(x==')' and a.size() and s[a.back()]=='('){
                a.pop_back();
                continue;
            }
            a.push_back(i);
        }
        int longest=0;
        if(a.size()==0){
            longest=n;
        }else{
            a.insert(a.begin(), -1);
            int v=n, b=0;
            while(a.size()){
                b=a.back();a.pop_back();
                longest=max(longest, v-b-1);
                v=b;
            }
            // longest=max(longest, v);
        }
        return longest;
    }
};