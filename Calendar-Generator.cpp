#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class Calendar {
private:
    int year;
    const vector<string> months = {"January", "February", "March", "April", "May", "June", 
                                   "July", "August", "September", "October", "November", "December"};
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getFirstDayOfYear() const {
        int y = year - 1;
        return (y * 365 + y / 4 - y / 100 + y / 400 + 1) % 7;
    }

public:
    Calendar(int y) : year(y) {
        if (isLeapYear()) {
            daysInMonth[1] = 29;
        }
    }

    void printCalendar() const {
        cout << "\n================ Calendar for " << year << " ================\n";
        int currentDay = getFirstDayOfYear();

        for (int i = 0; i < 12; ++i) {
            cout << "\n  ------------" << months[i] << "------------\n";
            cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

            int k;
            for (k = 0; k < currentDay; k++) {
                cout << "     ";
            }

            for (int j = 1; j <= daysInMonth[i]; ++j) {
                cout << setw(5) << j;
                if (++k > 6) {
                    k = 0;
                    cout << '\n';
                }
            }
            if (k != 0) cout << '\n';
            currentDay = k;
        }
    }
};

int main() {
    int inputYear;
    cout << "Enter a year: ";
    if (cin >> inputYear && inputYear > 0) {
        Calendar cal(inputYear);
        cal.printCalendar();
    } else {
        cout << "Invalid year input.\n";
    }
    return 0;
}