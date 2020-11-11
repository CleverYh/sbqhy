// #define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>
#include <map>
#include <vector>
#include <string>

#define MAX_N 100001

#include "md5.h"

using namespace std;

typedef pair<string, string> Account;
typedef vector<vector<Account>> hashingTable;

int base = 47;

int hashing(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = s[i] + res * base;
    }
    return res % MAX_N;
}

void insert(hashingTable &t, const Account &a) {
    int r = hashing(a.first);
    t[r].push_back(a);
}

bool find(hashingTable &t, const string u, const string p) {
    int r = hashing(u);
    for (int i = 0; i < t[r].size(); i++)
        if ((t[r][i].first == u) && (t[r][i].second == md5(p))) return true;
    return false;
}

int main() {

    string user, password;

    int m;
    cin >> m;
    hashingTable accounts(MAX_N);
    vector<string> input(m);
    for (int i = 0; i < m; i++) {
        cin >> user >> password;
        insert(accounts, make_pair(user, password));
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> user >> password;
        if (find(accounts, user, password))
            cout << user << ":OK" << endl;
        else
            cout << user << ":Invalid user name or password" << endl;
    }
    return 0;
}