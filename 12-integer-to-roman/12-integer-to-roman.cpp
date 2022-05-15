class Solution {
public:
    string intToRoman(int v) {
        string s;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for(int i=0;v;i++){
            while(v>=val[i]){
                v-=val[i];
                s+=sym[i];
            }
        }
        return s;
    }
};