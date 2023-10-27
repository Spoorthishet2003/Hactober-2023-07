#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int minEditDistance(string str1, string str2, int m, int n) {
    // If either of the strings is empty, the number of operations is the length of the other string.
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    // If the last characters of the strings are the same, no operation is needed.
    if (str1[m - 1] == str2[n - 1]) {
        return minEditDistance(str1, str2, m - 1, n - 1);
    }

    // If the last characters are different, consider all three operations and find the minimum.
    int insertOp = minEditDistance(str1, str2, m, n - 1);
    int deleteOp = minEditDistance(str1, str2, m - 1, n);
    int replaceOp = minEditDistance(str1, str2, m - 1, n - 1);

    // Return the minimum of the three operations plus one for the current operation.
    return 1 + min({insertOp, deleteOp, replaceOp});
}

int main() {
    string str1 = "kitten";
    string str2 = "sitting";

    int distance = minEditDistance(str1, str2, str1.length(), str2.length());

    cout << "Minimum Edit Distance between '" << str1 << "' and '" << str2 << "' is: " << distance << endl;

    return 0;
}
