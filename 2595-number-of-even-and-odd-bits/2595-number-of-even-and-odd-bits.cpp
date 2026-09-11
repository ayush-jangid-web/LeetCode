class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd = 0;
        int even = 0;

        int k = 0;
        while(n!=0){
            int bit = n&1;
            if(bit == 1){
                if(k%2==0){
                    even++;
                }
                else{
                    odd++;
                }
            }
            k++;
            n>>=1;
        }
        return {even,odd};
    }
};