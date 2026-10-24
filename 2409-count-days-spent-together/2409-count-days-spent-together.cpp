class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        int startA = month[stoi(arriveAlice.substr(0, 2)) - 1] +
                     stoi(arriveAlice.substr(3, 2));
        int endA = month[stoi(leaveAlice.substr(0, 2)) - 1] +
                   stoi(leaveAlice.substr(3, 2));

        int startB = month[stoi(arriveBob.substr(0, 2)) - 1] +
                     stoi(arriveBob.substr(3, 2));
        int endB = month[stoi(leaveBob.substr(0, 2)) - 1] +
                   stoi(leaveBob.substr(3, 2));

        int x = max(startA, startB);
        int y = min(endA, endB);

        if (x > y) {
            return 0;
        }
        return y - x + 1;
    }
};