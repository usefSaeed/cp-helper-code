#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vector<int>> vi2d;
typedef vector<vector<pi>> vpi2d;


string mgd(vi arr, int v){
    int n = arr.size();
    vpi higherThanV;
    
    string s;
    for (int i = 1; i < n; i++){
        if (v == 0){
            if (higherThanV.empty()){
                s += '0';
                continue;
            }
            s[higherThanV[0].first - 1] = '0';
            higherThanV.erase(higherThanV.begin());
            v++;
            int j = 0;
            int decVal = 1;
            while (j < higherThanV.size()){
                higherThanV[j].second -= decVal;
                if (higherThanV[j].second <= 0){
                    higherThanV.erase(higherThanV.begin() + j);
                    v++;
                    decVal++;
                }else{
                    j++;
                }
            }
        }
        s += '1';
        if (arr[i] > v){
            higherThanV.push_back(make_pair(i,arr[i]-v));
            v--;
        }
    }
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
