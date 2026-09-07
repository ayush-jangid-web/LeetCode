class Solution {
public:
    string intToRoman(int num) {
        int place = 1;
        vector<int>temp;
        while(num != 0){
            int digit = num%10;
            temp.push_back(digit*place);
            place *= 10;
            num /= 10;
        }
        reverse(temp.begin(),temp.end());

        string result = "";
        for(auto &it:temp){
            while(it <= 3999 && it >= 1000){
                result += "M";
                it -= 1000;
            }
            if(it == 900){
                result +="CM";
                it -= 900;
            }
            while(it <= 999 && it >= 500){
                result += "D";
                it -= 500;
            }
            if(it == 400){
                result += "CD";
                it -= 400;
            }
            while(it <= 499 && it >= 100){
                result += "C";
                it -= 100;
            }
            if(it == 90){
                result += "XC";
                it -= 90;
            }
            while(it <= 99 && it >= 50){
                result += "L";
                it -= 50;
            }
            if(it == 40){
                result += "XL";
                it -= 40;
            }
            while(it <= 49 && it >= 10){
                result += "X";
                it -= 10;
            }
            if(it == 9){
                result += "IX";
                it -= 9;
            }
            while(it < 9 && it >= 5){
                result += "V";
                it -= 5;
            }
            if(it == 4){
                result += "IV";
                it -= 4;
            }
            while(it < 4 && it >= 1){
                result += "I";
                it -= 1;
            }
        }
        return result;
    }
};

