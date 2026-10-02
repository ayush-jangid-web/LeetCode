class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int totaldist = 0;
        int count = 0;
        if(start > destination){
            swap(start,destination);
        }

        for(int i=0;i<n;i++){
            totaldist += distance[i];

            if(start <= i && i < destination){
                count += distance[i];
            }
        }

        return min(count,(totaldist-count));
    }
};