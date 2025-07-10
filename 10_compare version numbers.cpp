// You are given two version numbers: version1 and version2, both are strings.

// Each version number consists of one or more revision levels separated by a dot (.).
// Each revision level is a non-negative integer (may contain leading zeros).

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length(), n2 = version2.length();
        int i = 0, j = 0;

        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;

            // Parse version1's current number
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Parse version2's current number
            while (j < n2 && version2[j] != '.') {  // ✅ fixed here
                num2 = num2 * 10 + (version2[j] - '0');  // ✅ fixed here
                j++;
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            i++;  // skip '.'
            j++;
        }

        return 0;
    }
};
