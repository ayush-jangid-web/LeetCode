class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;

        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        };

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(y-x !=0){
                pq.push(y-x);
            }
        }
        return !pq.empty() ? pq.top(): 0; 
    }
};