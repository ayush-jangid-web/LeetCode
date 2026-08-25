class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int max_dist = 0;
        for(int i=0;i<n;i++){
            if(seats[i] == 0 && i!= 0 && i != n-1){
                
                int ldist = 0;
                int rdist = 0;
                // seat to right
                for(int j=i+1;j<n;j++){
                    if(seats[j] == 1){
                        rdist = (j-i);
                        break;
                    }
                }
                // seat to left
                for(int j=i-1;j>=0;j--){
                    if(seats[j] == 1){
                        ldist = (i-j);
                        break;
                    }
                }
                int dist = min(ldist,rdist);
                max_dist = max(max_dist,dist);
            }
            else if(seats[i] == 0 && i == 0){
                int rdist = 0;
                for(int j=i+1;j<n;j++){
                    if(seats[j] == 1){
                        rdist = j-i;
                        break;
                    }
                }
                max_dist = max(max_dist,rdist);
            }
            else if(seats[i] == 0 && i == n-1){
                int ldist = 0;
                for(int j=i-1;j>=0;j--){
                    if(seats[j] == 1){
                        ldist = i-j;
                        break;
                    }
                }
                max_dist = max(max_dist,ldist);
            }
        }
        return max_dist;
    }
};