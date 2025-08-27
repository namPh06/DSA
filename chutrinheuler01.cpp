#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

// Hàm kiểm tra đồ thị liên thông
bool isConnected(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 0 && !visited[i]) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra bậc của các đỉnh
int checkEuler(int n, vector<vector<int>>& adj) {
    int oddCount = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount == 0 && isConnected(n, adj)) {
        return 1; // Đồ thị Euler
    } else if (oddCount == 2 && isConnected(n, adj)) {
        return 2; // Đồ thị nửa Euler
    }
    return 0; // Không phải Euler/nửa Euler
}

// Hàm tìm chu trình Euler
void findEulerCycle(int u, vector<vector<int>>& adj) {
    vector<vector<int>> tempAdj = adj; // Tạo bản sao đồ thị
    vector<int> cycle;
    stack<int> st;

    st.push(u);
    while (!st.empty()) {
        int cur = st.top();
        if (!tempAdj[cur].empty()) {
            int next = tempAdj[cur].back();
            tempAdj[cur].pop_back();
            tempAdj[next].erase(find(tempAdj[next].begin(), tempAdj[next].end(), cur));
            st.push(next);
        } else {
            cycle.push_back(cur);
            st.pop();
        }
    }

    for (int i = 0; i < cycle.size(); i++) {
        cout << cycle[i] << " ";
    }
    cout << endl;
}

int main() {
    ifstream inputFile("CT.INP");
    ofstream outputFile("CT.OUT");

    int t, n, m, u;
    inputFile >> t;

    if (t == 1) {
        inputFile >> n >> m;
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            inputFile >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result = checkEuler(n, adj);
        outputFile << result << endl;

    } else if (t == 2) {
        inputFile >> n >> m >> u;
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            inputFile >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        findEulerCycle(u, adj);
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
