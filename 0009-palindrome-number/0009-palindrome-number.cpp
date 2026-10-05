class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes
        // Numbers ending in 0 are not palindromes unless x == 0
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // Even number of digits
        if (x == reversedHalf)
            return true;

        // Odd number of digits: ignore middle digit
        return x == reversedHalf / 10;
    }
};