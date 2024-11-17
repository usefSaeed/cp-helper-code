#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;

pll walksRange(long long x){
    return pll((x-1) * -1,x);
}

int main() {
    int N; cin >> N;
    while (N--){
        long long x; cin >> x;
        pll result = walksRange(x);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}