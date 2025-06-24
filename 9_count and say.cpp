class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";

        for (int iter = 1; iter < n; iter++) {
            string next = "";
            int i = 0;

            while (i < curr.length()) {
                int count = 1;

                // Count consecutive same digits
                while (i + 1 < curr.length() && curr[i] == curr[i + 1]) {
                    count++;
                    i++;
                }

                // Append count + digit to next
                next += to_string(count) + curr[i];
                i++;
            }

            curr = next;
        }

        return curr;
    }
};
