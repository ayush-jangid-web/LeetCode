class Solution {
    bool check(int num,int t){
        int pro = 1; 
        while(num!=0){
            pro *= num%10;
            num /= 10;
        }
        return (pro%t == 0);
    }
public:
    int smallestNumber(int n, int t) {
        int m=0;
        if(n+10 <= 100){
            m=n+10;
        }
        else{
            m = 100;
        }
        for(int i=n;i<=m;i++){
            if(check(i,t)){
                return i;
            }
        }
        return -1;
    }
};