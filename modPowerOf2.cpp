#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>


using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;

int getModPowerOF2(int x, int exp){
    return x & (int(pow(2,exp)) - 1);
}

int main() {
    int m; cin >> m;
    int x; cin >> x;
    cout << getModPowerOF2(x,m);
    return 0;
}