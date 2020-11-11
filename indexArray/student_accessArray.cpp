#include "Customer.h"

vector<int> accessArray(const vector<Customer> &table) {
    vector<int> res(table.size());
    for (int i = 0; i < table.size(); i++) res[i] = i;
    for (int i = 1; i < res.size(); i++) {
        int j = i - 1;
        int r = res[i];
        while (j >= 0 && table[r].name < table[res[j]].name) {
            res[j + 1] = res[j];
            j--;
        }
        res[j + 1] = r;
    }
    return res;
}
