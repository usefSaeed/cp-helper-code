#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vector<int>> vi2d;
typedef vector<vector<pi>> vpi2d;


string mgd(vi arr, int vMax){
    int n = arr.size();
    
    string s;
    int v = 0;

    for (int i = n - 1; i >= 1; i--){
        if (v == vMax){
            if (arr[i] > v){
                s += '0';
            }else{
                s += '1';
            }
        }else{
            s += '1';
            if (arr[i] > v){
                v++;
            }        
        }
    }
    reverse(s.begin(),s.end());
    return s;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    while (T--) {
        int N; cin >> N;
        int V; cin >> V;

        vi gymDays(N+1);
        
        for (int i = 1; i <= N; ++i) {
            cin >> gymDays[i]; 
        }

        cout << mgd(gymDays, V) << '\n'; 
    }
    return 0;
}
