class Solution {
    int datecount(int year, int month, int day) {
        int months[12] = {0,   31,  59,  90,  120, 151,
                          181, 212, 243, 273, 304, 334};
        // start 1900 - 01 - 01
        int cnt = 0;
        int noofyears = (year - 1) - 1900;
        int start = (1900 / 4) - (1900 / 100) + (1900 / 400);
        int end = ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);
        int totalLeapYear = (end - start);
        int nonleapyears = noofyears - totalLeapYear;

        cnt += (nonleapyears * 365) + (totalLeapYear * 366);

        cnt += months[month - 1];

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            // leap year
            if (month > 2) {
                cnt += 1;
            }
        }
        cnt += day;

        return cnt;
    }

public:
    int daysBetweenDates(string date1, string date2) {

        int a = datecount(stoi(date1.substr(0, 4)), stoi(date1.substr(5, 2)),
                          stoi(date1.substr(8, 2)));

        int b = datecount(stoi(date2.substr(0, 4)), stoi(date2.substr(5, 2)),
                          stoi(date2.substr(8, 2)));

        return abs(a - b);
    }
};