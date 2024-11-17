#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vector<int>> vi2d;
typedef vector<vector<pi>> vpi2d;
typedef vector<string> vs;
typedef map<char,pi> mpcpi;
typedef map<char,vi> mpcvi;

mpcpi freqMap;

void populateFreqMaps(string word){
    for (auto c : word){
        freqMap[c].second += 1;
    }
}

void resetFreqMaps(string word){
    for (auto c : word){
        freqMap[c].first = 0;
    }
}

bool reachedMaxFreq(char c){
    return freqMap[c].first == freqMap[c].second;
}

bool indexOverflow(mpcvi indexMap, char c){
    return reachedMaxFreq(c) && freqMap[c].first < indexMap[c].size();
}

int extractSolution(mpcvi indexMap, string word, int slow){
    int maxIdx = -1;
    for (auto c : word){
        if (!reachedMaxFreq(c)){
            return -1;
        }
        int maxFreq = freqMap[c].second;
        maxIdx = max(maxIdx, indexMap[c][maxFreq - 1]);
    }
    return maxIdx - slow + 1;
}

int getLeastSubstring(string phrase, string word){
    int phraseSize = phrase.size();
    mpcvi indexMap;
    int fast = 0; int slow = 0;
    while(fast<phraseSize){
        char c_fast = phrase[fast];
        char c_slow = phrase[slow];
        if (word.find(c_slow) != -1){
            if (indexOverflow(indexMap, c_slow)){
                indexMap[c_slow].erase(indexMap[c_slow].begin());
                slow++;
                continue;
            }
        }else{
            slow++;
            continue;
        }
        if (word.find(c_fast) != -1){
            indexMap[c_fast].push_back(fast);
            if (!reachedMaxFreq(c_fast)){
                freqMap[c_fast].first++;
            }
        }
        fast++;
    }
    while(true){
        char c_slow = phrase[slow];
        if (word.find(c_slow) != -1){
            if (indexOverflow(indexMap, c_slow)){
                indexMap[c_slow].erase(indexMap[c_slow].begin());
                slow++;
            }else{
                break;
            }
        }else{
            slow++;
        }
    }
    return extractSolution(indexMap, word, slow);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T; cin >> T;

    string word = "hardwork";
    populateFreqMaps(word);


    while (T--) {
        resetFreqMaps(word);
        int N; cin >> N;
        string phrase; cin >> phrase;
        cout << getLeastSubstring(phrase,word) << "\n";
    }
    return 0;
}
