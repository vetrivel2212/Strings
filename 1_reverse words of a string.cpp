// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.size();
//         int i = 0;
//         vector<string> words;

//         while (i < n) {
//             // skip spaces
//             while (i < n && s[i] == ' ') i++;

//             if (i >= n) break;

//             int j = i;
//             while (j < n && s[j] != ' ') j++;

//             words.push_back(s.substr(i, j - i));
//             i = j;
//         }

//         reverse(words.begin(), words.end());

//         string result = "";
//         for (int i = 0; i < words.size(); i++) {
//             result += words[i];
//             if (i != words.size() - 1) result += " ";
//         }
#include <algorithm>
using namespace std;

class Solution {
public:
    string cleanspaces(string s) {
        int i = 0, j = 0, n = s.size();

        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            while (i < n && s[i] != ' ')
                s[j++] = s[i++];

            if (i < n && s[i] == ' ') {
                s[j++] = ' ';
                while (i < n && s[i] == ' ') i++;
            }
        }

        if (j > 0 && s[j - 1] == ' ') j--;

        s.resize(j);
        return s;
    }

    string reverseWords(string s) {
        s = cleanspaces(s);                    // Step 1: clean spaces
        reverse(s.begin(), s.end());           // Step 2: reverse entire string

        int n = s.size();
        int start = 0;

        // Step 3: reverse each word
        for (int end = 0; end <= n; end++) {
            if (end == n || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};

//         return result;
//     }
// };
