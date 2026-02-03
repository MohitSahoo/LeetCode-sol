class Solution {
public:
    // Expand and return palindrome length
    int expandFromCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;   // length of palindrome
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;

        for (int center = 0; center < s.length(); center++) {

            int lenOdd  = expandFromCenter(s, center, center);
            int lenEven = expandFromCenter(s, center, center + 1);

            int maxLen = max(lenOdd, lenEven);

            if (maxLen > end - start + 1) {
                start = center - (maxLen - 1) / 2;
                end   = center + maxLen / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
