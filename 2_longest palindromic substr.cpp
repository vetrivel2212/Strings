class Solution {
public:
    void expandAroundCenter(string s, int left, int right, int &start, int &maxlength) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxlength) {
                maxlength = len;
                start = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int start = 0, maxlength = 0;
        for (int i = 0; i < s.size(); i++) {
            expandAroundCenter(s, i, i, start, maxlength);       // odd length
            expandAroundCenter(s, i, i + 1, start, maxlength);   // even length
        }
        return s.substr(start, maxlength);
    }
};
