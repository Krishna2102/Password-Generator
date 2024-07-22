#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<algorithm>
// Function to generate a random password of a given length
std::string generatePassword(int length) {
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string digits = "0123456789";
    const std::string special = "!@#$%^&*()-_=+[]{}|;:',.<>?/`~";
    
    // Combine all character sets
    const std::string allChars = uppercase + lowercase + digits + special;
    
    std::string password;
    srand(time(0)); // Seed the random number generator

    // Ensure the password contains at least one character from each set
    password += uppercase[rand() % uppercase.size()];
    password += lowercase[rand() % lowercase.size()];
    password += digits[rand() % digits.size()];
    password += special[rand() % special.size()];

    // Fill the rest of the password with random characters from the combined set
    for (int i = 4; i < length; ++i) {
        password += allChars[rand() % allChars.size()];
    }

    // Shuffle the password to ensure randomness
    std::random_shuffle(password.begin(), password.end());

    return password;
}

int main() {
    int length = 8; // Length of the password
    std::string password = generatePassword(length);
    std::cout << "Generated Password: " << password << std::endl;
    return 0;
}
