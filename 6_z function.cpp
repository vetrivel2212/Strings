#include <iostream>
#include <vector>
using namespace std;

vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> z(n, 0);  // z[0] is always 0

    for (int i = 1; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
            if (s[j] == s[i + j]) {
                z[i]++;
            } else {
                break;
            }
        }
    }

    return z;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    vector<int> z = computeZ(s);

    cout << "Z-array: ";
    for (int val : z) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
