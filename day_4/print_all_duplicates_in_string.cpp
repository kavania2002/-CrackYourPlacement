#include <bits/stdc++.h>

using namespace std;

void findDuplicates(string &s) {
    vector<int> counter(26, 0);

    for (char &c: s) counter[c-'a']++;

    for (int i = 0; i<26; i++) {
        if (counter[i] > 1) cout << char(i + 'a') << ' ';
    }
    cout << endl;
}

int main() {
    string str = "testingduplicates";
    findDuplicates((str));
}