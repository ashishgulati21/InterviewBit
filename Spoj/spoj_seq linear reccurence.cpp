#include <bits/stdc++.h>

#define MOD 1000000000
#define ll long long int
#define matrix vector<vector<ll>>

using namespace std;

matrix multiplyMatrix(matrix a, matrix b, int K){

    matrix c(K, vector<ll>(K, 0));
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            for(int k = 0; k < K; k++){
                c[i][j] = ((c[i][j]%MOD) + (((a[i][k]%MOD)*(b[k][j]%MOD))%MOD)%MOD);
            }
        }
    }

    return c;

}

matrix pow(matrix a, ll p, int K){
    if(p == 1)
        return a;

    matrix x = pow(a, p/2, K);
    if(p % 2 == 0){     // even
        return multiplyMatrix(x, x, K);
    }

    return multiplyMatrix(a, multiplyMatrix(x, x, K), K);

}

int main()
{

    int t;
    cin >> t;

    while(t--){
        int K;
        cin >> K;

        vector<ll> f1(K);
        for(int i = 0; i < K; i++){
            cin >> f1[i];
        }


        matrix T(K, vector<ll>(K, 0));
        for(int i = 0; i < K-1; i++){
            for(int j = 0; j < K; j++){
                if(i+1 == j){
                    T[i][j] = 1;
                }
            }
        }

        for(int i = K-1; i >= 0; i--){
            cin >> T[K-1][i];
        }

        ll n;
        cin >> n;

        if(n <= K){
            cout << f1[n-1] << endl;
            continue;
        }
        else{
            // cout << getAns(F1, T, n, K) << endl;
        }

        T = pow(T, n-1, K);

        ll ans = 0;

        for(int i = 0; i < K; i++){
            ans = (ans%MOD + ((T[0][i]%MOD * f1[i]%MOD) % MOD) % MOD) % MOD;
        }

        cout << ans << endl;

    }


}
