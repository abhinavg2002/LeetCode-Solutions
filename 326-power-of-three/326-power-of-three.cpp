class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 and (int)pow(3ll, 19)%n==0;
    }
};