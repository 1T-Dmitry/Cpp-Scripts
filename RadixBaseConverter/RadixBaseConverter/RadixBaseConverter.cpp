#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

bool isValidNumber(const string& number, int base) {
    if (number.empty()) return false;

    string validChars;
    switch (base) {
    case 2: validChars = "01"; break;
    case 8: validChars = "01234567"; break;
    case 10: validChars = "0123456789"; break;
    case 16: validChars = "0123456789ABCDEFabcdef"; break;
    default: return false;
    }

    for (char c : number) {
        if (validChars.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

char valueToChar(int value) {
    if (value >= 0 && value <= 9) return '0' + value;
    if (value >= 10 && value <= 15) return 'A' + (value - 10);
    return '0';
}

long long toDecimal(const string& number, int fromBase) {
    long long result = 0;
    int power = 0;

    for (int i = number.length() - 1; i >= 0; i--) {
        int digitValue = charToValue(number[i]);
        result += digitValue * pow(fromBase, power);
        power++;
    }

    return result;
}

string fromDecimal(long long decimalNumber, int toBase) {
    if (decimalNumber == 0) return "0";

    string result = "";

    while (decimalNumber > 0) {
        int remainder = decimalNumber % toBase;
        result = valueToChar(remainder) + result;
        decimalNumber /= toBase;
    }

    return result;
}

string convertNumber(const string& number, int fromBase, int toBase) {
    if (fromBase == toBase) return number;

    long long decimalValue = toDecimal(number, fromBase);

    return fromDecimal(decimalValue, toBase);
}

void displayMenu() {
    cout << "=== КОНВЕРТЕР СИСТЕМ СЧИСЛЕНИЯ ===" << endl;
    cout << "1. Двоичная (2) -> Другая система" << endl;
    cout << "2. Восьмеричная (8) -> Другая система" << endl;
    cout << "3. Десятичная (10) -> Другая система" << endl;
    cout << "4. Шестнадцатеричная (16) -> Другая система" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "До свидания!" << endl;
            break;
        }

        string number;
        int fromBase, toBase;

        switch (choice) {
        case 1:
            fromBase = 2;
            cout << "Введите двоичное число: ";
            break;
        case 2:
            fromBase = 8;
            cout << "Введите восьмеричное число: ";
            break;
        case 3:
            fromBase = 10;
            cout << "Введите десятичное число: ";
            break;
        case 4:
            fromBase = 16;
            cout << "Введите шестнадцатеричное число: ";
            break;
        default:
            cout << "Неверный выбор!" << endl;
            continue;
        }

        cin >> number;

        if (fromBase == 16) {
            transform(number.begin(), number.end(), number.begin(), ::toupper);
        }

        if (!isValidNumber(number, fromBase)) {
            cout << "Ошибка: неверный формат числа для выбранной системы счисления!" << endl;
            continue;
        }

        cout << "Выберите целевую систему счисления (2, 8, 10, 16): ";
        cin >> toBase;

        if (toBase != 2 && toBase != 8 && toBase != 10 && toBase != 16) {
            cout << "Ошибка: неверная целевая система счисления!" << endl;
            continue;
        }

        string result = convertNumber(number, fromBase, toBase);

        cout << "Результат: " << number << " (" << fromBase << ") = "
            << result << " (" << toBase << ")" << endl << endl;

    } while (true);

    return 0;
}
