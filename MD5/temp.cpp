#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

#include "md5.h"

using namespace std;

typedef pair<string, string> Account;

typedef vector<vector<Account>> Table;

void print(Table as) {
    for (unsigned i = 0; i < as.size(); i++) {
        cout << as[i].size() << endl;
        for (size_t j = 0; j < as[i].size(); j++) {
            cout << as[i][j].first << ", " << as[i][j].second << "; ";
        }
        cout << endl;
    }
}

//hash function
int base = 41;
size_t N = 199999;

size_t h(string s) {
    size_t ad = 0;
    for (size_t i = 0; i < s.size(); i++)
        ad = s[i] + ad * base;
    //    ad = knuth(ad);
    return ad % N;
}

void insert(Table &t, const Account &r) {
    size_t ad = h(r.first);
    //cout<<r.first<<" address:"<<ad<<endl;
    t[ad].push_back(r);
}
bool find(Table &t, const string u, const string p) {
    size_t ad = h(u);
    for (size_t i = 0; i < t[ad].size(); i++) {
        if ((t[ad][i].first == u) && (md5(p) == t[ad][i].second))
            return true;
    }
    return false;
}

int main() {

    //ifstream in("userpwd_in3.txt");
    string u, p, w;
    int m; //number of pairs
    int n; //number of names to search
    int id = 1;
    cin >> m;
    getline(cin, u, '\n');
    Table accounts(N);
    vector<string> input(m);
    for (int i = 0; i < m; i++) {
        getline(cin, u, '\n');
        getline(cin, p, '\n');
        insert(accounts, make_pair(u, p));
    }
    cin >> n;
    bool b;
    for (int i = 0; i < n; i++) {
        cin >> u >> p;
        b = find(accounts, u, p);
        if (b)
            cout << u << ":OK" << endl;
        else
            cout << u << ":Invalid user name or password" << endl;
    }
    return 0;
}

#if 0

#include "Customer.h"

vector<int> accessArray(const vector<Customer> & table){
   vector<int> result(table.size());
   for (size_t i=0;i<table.size();i++){
      result[i] = i;
   }
   for (int i=1; i<result.size();i++){
     int j = i-1;
     int r = result[i];
//cout<<"r:"<<r;
     while(j>=0 && table[r].name < table[result[j]].name){
//cout<<" i:"<<j<<" :"<<table[result[i]].name <<": "<< table[result[j]].name<<endl;

        result[j+1]= result[j];
        j--;
     }
     result[j+1] = r;
   }
   return result;
}

#endif