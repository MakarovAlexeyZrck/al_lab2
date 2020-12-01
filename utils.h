#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Проверяем, чтоб было введено натуральное число
inline int is_invalidinput(string msg) {

    int user_input;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0 || user_input > 7);

    return user_input;
}


// Проверяем, чтоб было введена переменная типа float
inline float is_float(string msg) {

    float user_input;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0);

    return user_input;
}


// Ввод целого неотрицательного числа от пользователя
inline int is_integer(string msg) {

    int user_input;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0);

    return user_input;
}


// Ввод булевого значения
inline bool is_bool(string msg) {

    bool user_input = 1;

    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << msg;
        cin >> user_input;
    } while (cin.fail() || user_input < 0 || user_input > 2);

    return user_input;

}


