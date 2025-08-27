#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

int countWays(const string &S, const vector<string> &words) {
    int N = S.size();
    vector<int> dp(N + 1, 0);
    dp[0] = 1; // Có một cách ghép xâu rỗng

    unordered_map<int, vector<string>> lengthToWords;
    for (const string &word : words) {
        lengthToWords[word.size()].push_back(word);
    }

    for (int i = 1; i <= N; ++i) {
        for (auto &entry : lengthToWords) {
            int len = entry.first;
            if (i >= len) {
                string current = S.substr(i - len, len);
                for (const string &word : entry.second) {
                    if (current == word) {
                        dp[i] = (dp[i] + dp[i - len]) % MOD;
                    }
                }
            }
        }
    }
    return dp[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int K;
    cin >> K;
    vector<string> words(K);
    for (int i = 0; i < K; ++i) {
        cin >> words[i];
    }
    cout << countWays(S, words) << endl;
    return 0;
}