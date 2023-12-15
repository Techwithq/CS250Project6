#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

bool palindrome(const string& str, int start, int end) {
    // Base case: If the string is empty or has one character, it's a palindrome
    if (start >= end) {
        return true;
    }

    // Convert both characters to lower case for case-insensitive comparison
    char start_c = tolower(str[start]);
    char end_c = tolower(str[end]);

    // Check if the characters are different
    if (start_c != end_c) {
        return false;
    }

    // Recursive case
    return palindrome(str, start + 1, end - 1);
}

bool verify_input(const string& input) {
    // Check if the input consists solely of letters
    for (char c : input) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string user_input;
    cout << "Enter a string to check if it's a palindrome: ";
    cin >> user_input;

    try {
        if (!verify_input(user_input)) {
            throw invalid_argument("Input must consist solely of letters.");
        }

        if (palindrome(user_input, 0, user_input.length() - 1)) {
            cout << "'" << user_input << "' is a palindrome." << endl;
        } else {
            cout << "'" << user_input << "' is not a palindrome." << endl;
        }
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

