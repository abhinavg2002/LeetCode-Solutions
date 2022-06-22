class Solution {
public:
    string fractionToDecimal(int Num, int Den) {
        if(Num == 0) return "0";
    
        string ans = "";

        // sign check
        if(Num<0 ^ Den<0)
            ans += '-';

        // remove the signs
        long N = abs(long(Num));
        long D = abs(long(Den));

        // the integer part is easy
        ans += to_string(N/D);

        // if there is no fractional part
        if(N%D == 0) return ans;

        // adding decimal point
        ans += '.';
        unordered_map<int, int> M;

        long r=N%D;
        while(r!=0)
        {
            if(M.find(r) != M.end())
            {
                ans.insert(M[r], 1, '(');
                ans += ')';
                break;
            }

            M[r] = ans.size();

            r *= 10;
            ans += to_string(r/D);
            r %= D;
        }

        return ans;
    }
};