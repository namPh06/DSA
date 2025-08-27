#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string filename;
    cin >> filename; 
    size_t dot_pos = filename.rfind('.');
    if (dot_pos == string::npos || dot_pos == 0 || dot_pos == filename.length() - 1) {
        cout << "no" << endl;
        return 0;
    }
    string extension = filename.substr(dot_pos + 1);
    transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    if (extension == "py") {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
