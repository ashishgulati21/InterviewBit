bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    vector<pair<int, int>> v;
    for(int i = 0; i < arrive.size(); i++){
        v.push_back(make_pair(arrive[i], 1));
        v.push_back(make_pair(depart[i], 0));
    }
    
    sort(v.begin(), v.end());    
    
    int currReq = 0;
    for(auto i : v){
        if(i.second == 1){
            currReq++;
            
            if(currReq > K)
                return false;
            
        }
        else{
            currReq--;
        }
    }
    
    return true;
    
    
}
