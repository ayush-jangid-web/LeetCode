class Solution {
public:
    bool checkDivisibility(int n) {
        int k = n;
        long long pro = 1;
        long long sum = 0;

        while(n != 0){
            int digit = n%10;
            pro *= digit;
            sum += digit;
            n /=10;
        }

        if(k % (pro+sum) == 0){
            return true;
        }
        else{
            return false;
        }
    }
};