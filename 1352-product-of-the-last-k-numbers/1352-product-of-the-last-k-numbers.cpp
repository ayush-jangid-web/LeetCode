class ProductOfNumbers {
public:
    vector<long long>temp;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            temp.clear();
        }   
        else{
            if(temp.size() > 0){
                temp.push_back( 1LL*temp.back()* num);
            }   
            else{
                temp.push_back(num);
            }
        } 
    }
    
    int getProduct(int k) {
        if(k > temp.size()){
            return 0;
        }
        if(k == temp.size()){
            return temp.back();
        }
        else{
            return temp.back() / temp[temp.size()-1-k]; 
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */