#include <iostream>
#include <string>
#include <getopt.h>
#include "generator.h"

using namespace std;

#define PASSWORD_MIN_LEN 12
#define PASSWORD_MAX_LEN 256


int main(int argc, char **argv) {
    int option;
    
    int passwordLen = PASSWORD_MIN_LEN;
    bool enableUppercase = false;
    bool enableDigits = false;
    bool enableSpecialChars = false;
    string password;

    while ((option = getopt(argc, argv, "l:uds")) != -1) {
        switch (option) {
            case 'l':
                try {
                    passwordLen = stoi(optarg);
                }
                catch (exception e) {
                    cout << "Argument must be an integer." << endl;
                    return 1;
                }                
                break;
            case 'u':
                enableUppercase = true;
                break;
            case 'd':
                enableDigits = true;
                break;
            case 's':
                enableSpecialChars = true;
                break;
            case '?':
                if (optopt == 'l') {
                    cerr << "No argument given for -" << (char)optopt << endl;
                }
                else {
                    cerr << "Unknown option: " << argv[optind - 1] << endl;
                }
                return 1;
            default:
                return 1;
        }
    }

    if (passwordLen < PASSWORD_MIN_LEN) {
        cerr << "Password minimum lenght is " << PASSWORD_MIN_LEN << "." << endl;
        return 2;
    }
    else if (passwordLen > PASSWORD_MAX_LEN) {
        cerr << "Password maximum lenght is " << PASSWORD_MAX_LEN << "." << endl;
        return 2;
    }

    password = generatePassword(passwordLen, enableUppercase, enableDigits, enableSpecialChars);

    cout << password << endl;

    return 0;
}
