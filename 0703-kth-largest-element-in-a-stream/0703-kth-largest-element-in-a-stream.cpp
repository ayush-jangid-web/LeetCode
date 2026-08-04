class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int> > pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        if(k>nums.size()){
            for(auto it:nums){
                pq.push(it);
            }
        }
        else{
            for(int i=0;i<k;i++){
                pq.push(nums[i]);
            }
            for(int i=k;i<nums.size();i++){
                if(pq.top() <= nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(k>pq.size()){
            pq.push(val);
            return pq.top();
        }
        else{
            if(pq.top() <= val){
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */