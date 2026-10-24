class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        string entermonthA = arriveAlice.substr(0, 2);
        string enterdateA = arriveAlice.substr(3, 2);

        string exitmonthA = leaveAlice.substr(0, 2);
        string exitdateA = leaveAlice.substr(3, 2);

        string entermonthB = arriveBob.substr(0, 2);
        string enterdateB = arriveBob.substr(3, 2);

        string exitmonthB = leaveBob.substr(0, 2);
        string exitdateB = leaveBob.substr(3, 2);

        int startA = month[stoi(entermonthA) - 1] + stoi(enterdateA);
        int endA = month[stoi(exitmonthA) - 1] + stoi(exitdateA);

        int startB = month[stoi(entermonthB) - 1] + stoi(enterdateB);
        int endB = month[stoi(exitmonthB) - 1] + stoi(exitdateB);

        int x = max(startA, startB);
        int y = min(endA, endB);

        if (x > y) {
            return 0;
        }
        return y - x + 1;
    }
};