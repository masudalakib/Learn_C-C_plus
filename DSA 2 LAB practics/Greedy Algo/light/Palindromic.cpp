#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindromic(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

string findNextPalindrome(const string& num) {
    string result = num;
    int len = result.size();

    int mid = len / 2;
    int i = mid - 1;
    int j = (len % 2 == 0) ? mid : mid + 1;

    // Move pointers to find the first non-matching pair of digits
    while (i >= 0 && result[i] == result[j]) {
        i--;
        j++;
    }

    // If we have reached the leftmost digit, increment the middle and set i and j accordingly
    if (i < 0) {
        i = mid - 1;
        j = (len % 2 == 0) ? mid : mid + 1;
    }

    // Copy the left side to the right side to mirror the palindrome
    while (i >= 0 && result[i] == result[j]) {
        i--;
        j++;
    }

    // Increment the middle digit
    if (i >= 0 && result[i] < result[j]) {
        result[mid]++;
        i = mid - 1;
        j = (len % 2 == 0) ? mid : mid + 1;
    }

    // Copy the left side to the right side to mirror the palindrome
    while (i >= 0) {
        result[j] = result[i];
        i--;
        j++;
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        string num;
        cin >> num;

        string nextPalindrome = findNextPalindrome(num);

        cout << "Case " << caseNum << ": " << nextPalindrome << endl;
    }

    return 0;
}
