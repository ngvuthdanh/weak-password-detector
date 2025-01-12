#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> commonPasswords = {
    "123456", "password", "123456789", "12345678", "12345", "qwerty", "abc123", "111111", "123123"
};

bool isCommonPassword(const string& password) {
    return find(commonPasswords.begin(), commonPasswords.end(), password) != commonPasswords.end();
}

string checkPasswordStrength(const string& password) {
    if (password.length() < 8) {
        return "Password is too short! (Minimum 8 characters)";
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSpecial = true;
    }

    if (!hasUpper) return "Password must contain at least one uppercase letter!";
    if (!hasLower) return "Password must contain at least one lowercase letter!";
    if (!hasDigit) return "Password must contain at least one digit!";
    if (!hasSpecial) return "Password must contain at least one special character!";
    if (isCommonPassword(password)) return "Password is too common and easily guessable!";

    return "Password is strong!";
}

int main() {
    cout << "=== WEAK PASSWORD DETECTOR ===\n";

    while (true) {
        string password;
        cout << "\nEnter a password to check (or type 'exit' to quit): ";
        cin >> password;

        if (password == "exit") {
            cout << "Goodbye!\n";
            break;
        }

        string result = checkPasswordStrength(password);
        cout << "Result: " << result << endl;
    }

}
