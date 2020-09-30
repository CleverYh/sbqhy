#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> Term; // 第一个分量表示系数，第二个分量表示指数
typedef vector<Term> Polynomial;

Polynomial sum(const Polynomial &p, const Polynomial &q) {
    Polynomial s;
    for (int i = 0, j = 0; i < p.size() || j < q.size();) {
        if (p.empty() || i == p.size()) {
            for (j; j < q.size(); j++) {
                s.push_back(make_pair(q[j].first, q[j].second));
            }
            break;
        } else if (q.empty() || j == q.size()) {
            for (i; i < p.size(); i++) {
                s.push_back(make_pair(p[i].first, p[i].second));
            }
            break;
        }
        if (p[i].first == 0) {
            i++;
            continue;
        }
        if (q[j].first == 0) {
            j++;
            continue;
        } else if (p[i].second == q[j].second) {
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

    for (int i = 0; i < s.size(); i++) {
        if (s[i].first == 0) {
            s.erase(s.begin()+i,s.begin()+i+1);
            i--;
        }
    }
    return s;
}

void showvec(const Polynomial &line) {
    cout << line.size() << endl;
    for (Polynomial::const_iterator iter = line.cbegin(); iter != line.cend(); iter++) {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n) {
        int n1, n2;
        Polynomial p, q, s;
        cin >> n1;
        for (int i = 0; i < n1; i++) {
            int a, b;
            cin >> a >> b;
            p.push_back(make_pair(a, b));
        }

        cin >> n2;
        for (int i = 0; i < n2; i++) {
            int a, b;
            cin >> a >> b;
            q.push_back(make_pair(a, b));
        }

        s = sum(p, q);

        showvec(s);

        n--;
    }

    return 0;
}