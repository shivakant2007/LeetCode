class Solution {
public:
    vector<string> result;

    string keypad[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string& current) {
        // Base case
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to current digit
        string letters = keypad[digits[index] - '0'];

        // Try every possible letter
        for (char ch : letters) {
            current.push_back(ch);

            backtrack(digits, index + 1, current);

            // Undo choice
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        string current;
        backtrack(digits, 0, current);

        return result;
    }
};