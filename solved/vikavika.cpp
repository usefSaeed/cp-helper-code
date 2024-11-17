#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vector<int>> vi2d;
typedef vector<vector<pi>> vpi2d;
typedef vector<string> vs;

bool isTVNice(vs tv, string word){
    int n = tv.size(); 
    int m = tv[0].size();
    int wordSize = word.size();
    if (wordSize > m) return false;
    int pointer = 0;
    for (int j = 0; j < m; j++){
        bool found = false;
        for (int i = 0; i < n; i++){
            if (tv[i][j] == word[pointer]){
                found = true;
                pointer++;
                if (pointer >= wordSize){
                    return true;
                }
                break;
            }
        }
        if (!found && wordSize - pointer > m - j - 1){
            return false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    string word = "vika";

    while (T--) {
        int N; cin >> N;
        int M; cin >> M;

        vs tv(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> tv[i];
        }

        isTVNice(tv, word) ? cout <<  "YES\n" : cout << "NO\n"; 
    }
    return 0;
}
