#include <iostream>
#include <getopt.h>

using namespace std;

#define PASSWORD_MIN_LEN 12
#define PASSWORD_MAX_LEN 256


int main(int argc, char **argv) {
    int option;
    
    int password_len = PASSWORD_MIN_LEN;
    bool enable_uppercase = false;
    bool enable_digits = false;
    bool enable_special_chars = false;

    while ((option = getopt(argc, argv, "l:uds")) != -1) {
        switch (option) {
            case 'l':
                try {
                    password_len = stoi(optarg);
                }
                catch (exception e) {
                    cout << "Argument must be an integer." << endl;
                    return 1;
                }                
                break;
            case 'u':
                enable_uppercase = true;
                break;
            case 'd':
                enable_digits = true;
                break;
            case 's':
                enable_special_chars = true;
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

    if (password_len < PASSWORD_MIN_LEN) {
        cerr << "Password minimum lenght is " << PASSWORD_MIN_LEN << "." << endl;
        return 2;
    }
    else if (password_len > PASSWORD_MAX_LEN) {
        cerr << "Password maximum lenght is " << PASSWORD_MAX_LEN << "." << endl;
        return 2;
    }

    return 0;
}
