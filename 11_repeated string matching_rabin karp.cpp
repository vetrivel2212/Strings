class Solution {
public:
   void computeLPS(string pattern, vector<int> &lps, int m) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
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

bool kmp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return true; // Edge case

    vector<int> lps(m, 0);
    computeLPS(pattern, lps, m);

    int i = 0; // for text
    int j = 0; // for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return true; // Match found
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return false; // No match found
}

    int repeatedStringMatch(string a, string b) {
        int n=b.length()/a.length();
        string na = "";
        int cnt = n;
        while(cnt--)
        {
            na+=a;
        }
        if(kmp(na,b)) return n;
        na+=a;
        if(kmp(na,b)) return n+1;
          na+=a;
        if(kmp(na,b)) return n+2;
        return -1;
    }
};
