#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;

vi longToVector(long number) {
    string strNum = std::to_string(number);
    strNum.erase(0, strNum.find_first_not_of('0'));
    vi digits; 
    for (char digit : strNum) {
        digits.push_back(digit - '0'); 
    }
    if (digits.empty()) {
        digits.push_back(0);
    }
    return digits;
}

void swapMax(vi &v, int maxSwaps){
    int swaps = 0;
    int size = v.size();
    for (int i = 0; i < size; i++){
        int toBeSwapped = i;
        for (int j = i + 1; j < size; j++){
            if (v[j] >= v[toBeSwapped]){
                toBeSwapped = j;
            }
        }
        if (toBeSwapped != i){
            swap(v[i],v[toBeSwapped]);
            swaps++;
            if (swaps == maxSwaps)
                break;
        }
    }
    while (swaps < maxSwaps){
        swap(v[size - 2],v[size - 1]);
        swaps++;
    }
}

long vectorToLong(const vi& digits) {
    long number = 0;
    long multiplier = 1; 
    for (int i = digits.size() - 1; i >= 0; --i) {
        number += digits[i] * multiplier; 
        multiplier *= 10; 
    }
    return number;
}

int main() {
    long N; cin >> N;
    int K; cin >> K;
    vi digitsOfN = longToVector(N);
    swapMax(digitsOfN,K);
    cout << vectorToLong(digitsOfN);
    return 0;
}