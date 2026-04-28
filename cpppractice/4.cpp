#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

bool hasUniqueDigits(const string& text) {
    vector<bool> used(10, false);
    for (char ch : text) {
        const int digit = ch - '0';
        if (used[digit]) {
            return false;
        }
        used[digit] = true;
    }
    return true;
}

string generatePassword() {
    random_device rd;
    mt19937 gen(rd());

    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(digits.begin(), digits.end(), gen);

    if (digits[0] == 0) {
        for (int i = 1; i < 10; ++i) {
            if (digits[i] != 0) {
                swap(digits[0], digits[i]);
                break;
            }
        }
    }

    string password;
    for (int i = 0; i < 4; ++i) {
        password.push_back(static_cast<char>('0' + digits[i]));
    }
    return password;
}

bool isValidGuess(const string& guess) {
    if (guess.size() != 4) {
        return false;
    }
    for (char ch : guess) {
        if (!isdigit(static_cast<unsigned char>(ch))) {
            return false;
        }
    }
    if (guess[0] == '0') {
        return false;
    }
    return hasUniqueDigits(guess);
}

int main() {
    const string password = generatePassword();
    int attempts = 0;

    cout << "Guess the 4-digit password (digits are unique)." << endl;

    while (true) {
        string guess;
        cout << "Please input your guess: ";
        cin >> guess;

        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Input error. Please enter a 4-digit integer." << endl;
            continue;
        }

        if (!isValidGuess(guess)) {
            cout << "Invalid input. Please enter a 4-digit integer with no repeated digits." << endl;
            continue;
        }

        ++attempts;
        int exact = 0;
        int misplaced = 0;

        for (int i = 0; i < 4; ++i) {
            if (guess[i] == password[i]) {
                ++exact;
            } else if (password.find(guess[i]) != string::npos) {
                ++misplaced;
            }
        }

        if (exact == 4) {
            cout << "猜对了" << endl;
            cout << "Congratulations! You guessed the password in " << attempts << " attempt(s)." << endl;
            break;
        }

        if (exact == 0 && misplaced == 0) {
            cout << "无正确数字" << endl;
        } else if (exact == 0) {
            cout << "有 " << misplaced << " 个数字正确但位置错误" << endl;
        } else if (misplaced == 0) {
            cout << "有 " << exact << " 个数字正确且位置正确" << endl;
        } else {
            cout << "有 " << exact << " 个数字正确且位置正确，"
                 << misplaced << " 个数字正确但位置错误" << endl;
        }
    }

    return 0;
}
