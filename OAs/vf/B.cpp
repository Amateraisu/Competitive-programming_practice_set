#include <bits/stdc++.h>
using namespace std;

std::string stringToHexadecimal(const std::string& inputStr) {
    // Convert the string to an integer
    set<char>ss = {'A', 'B', 'C', 'D', 'E', 'F', 'I', 'O'};
    std::istringstream iss(inputStr);
    int number;
    iss >> number;

    // Check if conversion was successful
    if (!iss.fail()) {
        // Convert the integer to hexadecimal
        std::ostringstream oss;
        oss << std::hex << number;

        string s = oss.str();
        for (auto& c : s) {
            if (c == '0') c = 'O';
            if (c == '1') c = 'I';

        }
        for (auto& c : s) {
            if (ss.find(c) == ss.end()) {
                return "ERROR";
            }
        }
        cout << "Converted to string! " << s << '\n';
        return oss.str();
    } else {
        // Handle the case where the input string is not a valid number
        return "Invalid input";
    }
}

int main() {
    // Example usage:
    std::string inputStr = "3";
    std::string hexRepresentation = stringToHexadecimal(inputStr);
    std::cout << hexRepresentation << std::endl;

    return 0;
}

