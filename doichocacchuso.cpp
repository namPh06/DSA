#include <bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin >> t;
        while(t--){
            int k;
            cin >> k;
            string s;
            cin >> s;
            for (int i = 0 ; i< k && i < s.size() ; i++){
                int max_id = i;
                for(int j = s.size() - 1 ; j > i ; j--){
                    if (s[j] > s[max_id])
                    max_id = j;
                }
                if (max_id != i)
                swap(s[i] , s[max_id]);
            }
            cout << s << endl;
        }
        return 0;
}