class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (totalLen > s.size())
            return ans;

        unordered_map<string, int> need;

        for (string word : words) {
            need[word]++;
        }

        // Try each possible alignment
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;

            unordered_map<string, int> window;

            int count = 0;

            while (right + wordLen <= s.size()) {

                // Take the next word
                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word is not required
                if (need.find(word) == need.end()) {

                    window.clear();
                    count = 0;
                    left = right;

                    continue;
                }

                // Add word to window
                window[word]++;
                count++;

                // Too many copies of this word
                while (window[word] > need[word]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Exactly wordCount words
                if (count == wordCount) {

                    ans.push_back(left);

                    // Move left forward to search for next window
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};