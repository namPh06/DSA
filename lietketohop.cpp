#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool isArithmeticProgression(const vector<int>& v) {
    if (v.size() < 2) return false;
    int d = v[1] - v[0];
    for (int i = 2; i < v.size(); ++i) {
        if (v[i] - v[i - 1] != d)
            return false;
    }
    return true;
}
void generateCombinations(vector<int>& a, int k, int start, vector<int>& current, set<vector<int>>& printed) {
    if (current.size() == k) {
        vector<int> temp = current;
        sort(temp.begin(), temp.end());
        if (isArithmeticProgression(temp) && printed.find(temp) == printed.end()) {
            printed.insert(temp);
            for (int num : temp) cout << num << " ";
            cout << endl;
        }
        return;
    }
    for (int i = start; i < a.size(); ++i) {
        current.push_back(a[i]);
        generateCombinations(a, k, i + 1, current, printed);
        current.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    set<vector<int>> printed;
    vector<int> current;
    generateCombinations(a, k, 0, current, printed);
    return 0;
}
