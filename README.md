# RandomPasswordGenerator
C++ program designed to generate secure passwords with customizable characteristics. The program utilizes command-line arguments to determine password length and the inclusion of uppercase letters, digits, and special characters. The password generation algorithm ensures randomness and security.

## Features:

- Customizable Passwords: The program allows users to customize various aspects of the generated password, including its length and the types of characters to include (lowercase, uppercase, digits, special characters).
- Secure Password Generation: The password generation process ensures randomness and security by utilizing a combination of character sets and shuffling techniques.
- Command-Line Interface: The program operates via a command-line interface, making it easily scriptable and integrable into various workflows.
- Error Handling: The program includes error handling for invalid input values, ensuring a smooth user experience.

## Usage:

- Clone the repository and navigate to the project directory.
- Compile the program using a C++ compiler.
- Run the compiled executable with command-line options to customize password generation.
- Command-Line Options:

- -l: Specify the length of the password (default is 12).
- -u: Include uppercase letters in the password.
- -d: Include digits in the password.
- -s: Include special characters in the password.

## Example Command:

Generate a password of length 16, including uppercase letters, digits, and special characters:

    ./password_generator -l 16 -u -d -s
