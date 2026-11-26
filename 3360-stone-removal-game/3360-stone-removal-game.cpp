class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10){
            return false;
        }
        else if(n < 19){
            return true;
        }
        else if(n < 27){
            return false;
        }
        else if(n < 34){
            return true;
        }
        else if(n < 40){
            return false;
        }
        else if(n < 45){
            return true;
        }
        else if(n < 49){
            return false;
        }
        return true;
    }
};
/*
a -> 10
b -> 9
a -> 8
b -> 7
a -> 6
b -> 5
a -> 4
b -> 3
a -> 2
b -> 1

19 a
27 b
34 a
40 b
45 a
49 b 
52 a 
54 b 
55 a



55
*/
