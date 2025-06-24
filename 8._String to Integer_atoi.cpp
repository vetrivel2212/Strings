class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long ans = 0;
        int i = 0, n = s.length();

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Handle sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');  // ✅ Fix here!

            // Step 4: Clamp if out of bounds
            if (sign * ans > INT_MAX) return INT_MAX;
            if (sign * ans < INT_MIN) return INT_MIN;
            i++;
        }

        return sign * ans;
    }
};
