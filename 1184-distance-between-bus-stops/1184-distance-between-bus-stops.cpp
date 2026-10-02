class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();

        int a = 0;
        int b = 0;
        if(start <= destination){
            for(int i=start;i<destination;i++){
                a += distance[i];
            }

            for(int i=destination;i<(start+n);i++){
                b += distance[i%n];
            }
        }
        else{
            for(int i=start;i<(destination+n);i++){
                a += distance[i%n];
            }

            for(int i=destination;i<start;i++){
                b += distance[i];
            }
        }
        return min(a,b);
    }
};
