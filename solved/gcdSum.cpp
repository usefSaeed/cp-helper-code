#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        int x; cin >> x; 
    }

    long long res = N * (N-1) / 2; 

    cout << res;

    return 0;
}