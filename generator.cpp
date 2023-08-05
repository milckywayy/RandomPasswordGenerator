#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

using namespace std;

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,.<>?"


int randomInteger(int min, int max) {
    return min + rand() % (max - min);
}


void swapChars(string *str, int a, int b) {
    char tmp = (*str)[a];
    (*str)[a] = (*str)[b];
    (*str)[b] = tmp;
}


void shuffleString(string *str) {
    for (int i = 0; i < str->length(); i++) {
        swapChars(str, i, randomInteger(0, str->length()));
    }
}


string generatePassword(int passwordLen, bool upper, bool digits, bool specialChars) {
    int i;
    vector<string> allChars = {LOWERCASE};
    string password_str = "";

    if (upper) {
        allChars.push_back(UPPERCASE);
    }
    if (digits) {
        allChars.push_back(DIGITS);
    }
    if (specialChars) {
        allChars.push_back(SPECIAL_CHARS);
    }

    srand((unsigned)time(NULL));

    for (i = 0; i < allChars.size(); i++) {
        string *str_pointer = &(allChars[i]);
        password_str += (*str_pointer)[randomInteger(0, str_pointer->length())];
    }
    for (i = allChars.size(); i < passwordLen; i++) {
        string *str_pointer = &(allChars[randomInteger(0, allChars.size())]);
        password_str += (*str_pointer)[randomInteger(0, str_pointer->length())];
    }

    shuffleString(&password_str);

    return password_str;
}
