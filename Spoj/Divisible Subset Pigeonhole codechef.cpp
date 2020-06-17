#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Print(vector<int> arr, int n){
    
    vector<ll> sum(n);
    
    sum[0] = arr[0]%n;
    
    for(int i = 1; i < n; i++){
        sum[i] = (sum[i-1]%n + arr[i]%n) % n;
    }
    
    vector<pair<ll, int>> freq(n, make_pair(0, 0));

    
    freq[0] = make_pair(1, -1);
    
    for(int i = 0; i < n; i++){
        ll currSum = sum[i];
        
        
        if(freq[currSum].first > 0){
            int j = freq[currSum].second+1;
            
            cout << i - j + 1 << endl;
            
            while(j <= i){
                cout << j+1 << " ";
                j++;
            }
            
            cout << endl;
            
            return;
        }
        
        freq[currSum] = make_pair(1, i);
    }
    
    cout << "-1" << endl;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        
        
        Print(arr, n);
        
        
        
    }
    
    
}
