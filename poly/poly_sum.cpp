#include "Polynomial.h"

Polynomial sum(const Polynomial &p, const Polynomial &q) {
    Polynomial s;
    for (int i = 0, j = 0; i < p.size() || j < q.size();) {
        if (p[i].second == q[j].second) {
            s.push_back(make_pair(p[i].first + q[j].first, q[j].second));
            i++;
            j++;
        } else if (p[i].second < q[j].second) {
            s.push_back(make_pair(q[j].first, q[j].second));
            j++;
        } else if (p[i].second > q[j].second) {
            s.push_back(make_pair(p[i].first, p[i].second));
            i++;
        }
    }
    return s;
}

void showvec(const Polynomial &line) {
    for (Polynomial::const_iterator iter = line.cbegin(); iter != line.cend(); iter++) {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
}

int main() {
    int n1, n2;
    Polynomial p, q, s;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }

    for (int i = 0; i < n2; i++) {
        int a, b;
        cin >> a >> b;
        q.push_back(make_pair(a, b));
    }

    s = sum(p, q);

    showvec(s);

    return 0;
}