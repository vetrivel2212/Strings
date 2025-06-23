/*naive
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0) return 0;
        if (n < m) return -1;

        for (int i = 0; i <= n - m; i++) {  // ✅ safe upper bound
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;  // ✅ full match
        }

        return -1; // ❌ no match
    }
};

*/

class Solution {
public:
    void computeLPS(string &needle, vector<int> &lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < needle.length()) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    }

    int strStr(string haystack, string needle) {
    int n = haystack.length();
    int m = needle.length();
    if (m == 0) return 0;

    vector<int> lps(m, 0);
    computeLPS(needle, lps);

    int i = 0, j = 0;  // i for haystack, j for needle

    while (i < n) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j; // found match
        }

        if (i < n && haystack[i] != needle[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1; // no match
}

};
