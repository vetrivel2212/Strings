#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int minCharsToMakePalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = s + "#" + rev;
    vector<int> lps(combined.length(), 0);

    computeLPS(combined, lps);

    return s.length() - lps.back();
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int ans = minCharsToMakePalindrome(s);
    cout << "Minimum chars to insert at beginning: " << ans << endl;

    return 0;
}
