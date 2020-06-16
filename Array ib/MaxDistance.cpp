int Solution::maximumGap(const vector<int> &A) {

    int n = A.size();
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++){
        v[i] = make_pair(A[i], i);
    }

    sort(v.begin(), v.end());

    int maxDiff = 0, first = INT_MAX;

    for(int i = 0; i < n; i++){
        int index = v[i].second;
        if(index < first){
            first = index;
        }else{
            maxDiff = max(maxDiff, index - first);
        }
    }

    return maxDiff;

}
