#include <iostream>
#include <vector>
using namespace std;

// Hàm tính tổng chữ số
int digitSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAX_N = 200005;
    vector<int> specialNumbers;
    int num = 19;
    
    // Tiền xử lý trước các số Thập Cẩm nhỏ nhất đến số thứ 200000
    while ((int)specialNumbers.size() < MAX_N) {
        if (digitSum(num) == 10) {
            specialNumbers.push_back(num);
        }
        ++num;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << specialNumbers[n - 1] << '\n';
    }

    return 0;
}
