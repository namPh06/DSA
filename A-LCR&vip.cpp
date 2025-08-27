#include <bits/stdc++.h>
using namespace std;

int computeGCD(const vector<int>& arr) {
    int res = arr[0];
    for (int num : arr) {
        res = gcd(res, num);
        if (res == 1) break;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Check if all elements are the same
    bool allSame = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            allSame = false;
            break;
        }
    }
    if (allSame) {
        cout << "No\n";
        return;
    }
    
    // Try to split into B and C where B has the first element, C has the rest
    vector<int> B, C;
    B.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        C.push_back(a[i]);
    }
    int gcdB = computeGCD(B);
    int gcdC = computeGCD(C);
    if (gcdB != gcdC) {
        cout << "Yes\n";
        cout << "1";
        for (int i = 1; i < n; ++i) {
            cout << " 2";
        }
        cout << "\n";
        return;
    }
    
    // If the above split doesn't work, try putting one different element in B
    // Find the first element different from a[0]
    int diffIndex = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            diffIndex = i;
            break;
        }
    }
    if (diffIndex != -1) {
        B.clear();
        C.clear();
        B.push_back(a[diffIndex]);
        for (int i = 0; i < n; ++i) {
            if (i != diffIndex) {
                C.push_back(a[i]);
            }
        }
        gcdB = computeGCD(B);
        gcdC = computeGCD(C);
        if (gcdB != gcdC) {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i) {
                if (i == diffIndex) {
                    cout << "1";
                } else {
                    cout << "2";
                }
                if (i != n - 1) cout << " ";
            }
            cout << "\n";
            return;
        }
    }
    
    // If still not, try any possible split where B has one element and C has the rest
    for (int i = 0; i < n; ++i) {
        B.clear();
        C.clear();
        B.push_back(a[i]);
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                C.push_back(a[j]);
            }
        }
        gcdB = computeGCD(B);
        gcdC = computeGCD(C);
        if (gcdB != gcdC) {
            cout << "Yes\n";
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    cout << "1";
                } else {
                    cout << "2";
                }
                if (j != n - 1) cout << " ";
            }
            cout << "\n";
            return;
        }
    }
    
    // If all single splits fail, try any possible split
    // Since elements are not all same, there must exist a split
    // For example, split into first element and the rest
    // But earlier attempts failed, so try splitting into two groups where each has at least one element
    // The minimal case is when B has one element and C has the rest, but if all such splits have same GCD, then need another approach
    // Alternative: split into two groups where one group has elements with GCD different from the other
    // But given time constraints, we can proceed as follows:
    // Since the elements are not all same, there must be at least two distinct GCDs possible
    // So find any two elements with different GCDs when taken as groups
    // For example, find the minimal element and put it alone in B, rest in C
    int minElement = *min_element(a.begin(), a.end());
    int maxElement = *max_element(a.begin(), a.end());
    if (minElement != maxElement) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == minElement) {
                B.clear();
                C.clear();
                B.push_back(a[i]);
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        C.push_back(a[j]);
                    }
                }
                gcdB = computeGCD(B);
                gcdC = computeGCD(C);
                if (gcdB != gcdC) {
                    cout << "Yes\n";
                    for (int j = 0; j < n; ++j) {
                        if (j == i) {
                            cout << "1";
                        } else {
                            cout << "2";
                        }
                        if (j != n - 1) cout << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == maxElement) {
                B.clear();
                C.clear();
                B.push_back(a[i]);
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        C.push_back(a[j]);
                    }
                }
                gcdB = computeGCD(B);
                gcdC = computeGCD(C);
                if (gcdB != gcdC) {
                    cout << "Yes\n";
                    for (int j = 0; j < n; ++j) {
                        if (j == i) {
                            cout << "1";
                        } else {
                            cout << "2";
                        }
                        if (j != n - 1) cout << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
    }
    
    // If still not found, try splitting into two groups with different GCDs
    // This