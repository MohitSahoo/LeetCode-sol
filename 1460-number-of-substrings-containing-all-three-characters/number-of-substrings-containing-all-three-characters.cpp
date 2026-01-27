class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1};
        int count = 0;

        for (int r = 0; r < s.size(); r++) {
            last[s[r] - 'a'] = r;

            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                count += 1 + min({last[0], last[1], last[2]});
            }
        }
        return count;
    }
};
