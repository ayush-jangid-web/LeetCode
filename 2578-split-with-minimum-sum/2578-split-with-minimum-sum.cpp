class Solution {
    void solve(vector<int>&temp,int num){
        while(num!=0){
            int d = num%10;
            temp.push_back(d);
            num /= 10;
        }
    }
public:
    int splitNum(int num) {
        vector<int>temp;
        solve(temp,num);
        sort(temp.begin(),temp.end());

        int i = 0;
        int a = 0;
        int b = 0;

        while(i<temp.size()){
            a = (a*10) + temp[i++];
            if(i < temp.size())
                b = (b*10) + temp[i++];
        }
        return a+b;
    }
};