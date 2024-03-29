#include <iostream>
#include <string>
using namespace std;

std::string convertTo12HourFormat(const std::string& time24) {
    int hours = std::stoi(time24.substr(0, 2));
    std::string minutes = time24.substr(3, 2);

    std::string am_pm = "AM";
    if (hours >= 12) {
        am_pm = "PM";
        hours -= 12;
    }
    if (hours == 0) {
        hours = 12;
    }

    std::string hoursStr = std::to_string(hours);
    if (hours < 10) {
        hoursStr = "0" + hoursStr;
    }

    return hoursStr + ":" + minutes + " " + am_pm;
}

int main() {

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << convertTo12HourFormat(s) << '\n';
    }

    return 0;
}
