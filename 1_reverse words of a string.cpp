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

//         return result;
//     }
// };
