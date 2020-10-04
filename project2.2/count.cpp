#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// #define SIZE 1024;

// string word[1024];
string keys[1024];
// int cnt[1024], record[1024];

void readFile(string fileName) {
    string w;
    // char ch;
    ifstream ifs(fileName);
    if (!ifs) {
        cout << "cannot open the file" << fileName << endl;
        return;
    }
    int i = 0;
    while (ifs >> w) {

        // for (int j = 0; j < w.size(); j++) {
        //     if (!((w[j] >= 65 && w[j] <= 90) || (w[j] >= 97 && w[j] <= 122))) {
        //         w.erase(j);
        //     }
        // }
        keys[i] = w;
        // cout << keys[i] << " ";
        i++;
    }
    cout << endl;
    ifs.close();
}

void searchFile(string fileName, string wfileName, string key) {
    ofstream ofs(wfileName, ios::app);
    ofs << key << " ";
    // ifstream ifs(fileName);
    // if (!ifs) {
    //     cout << "cannot open file " << fileName << endl;
    // }
    // string w;
    // int i = 0,line = 1;
    // while(ifs >> w){
    //     if (w[0] == '\n'){//这里有问题
    //         line++;
    //     }
    //     else if (key == w){
    //         cout << key << " " << line << endl;
    //     }
    // }
    // ifs.close();

    FILE *fp = fopen(fileName.data(), "a+");

    char buf[1024];
    char *p;
    int s = -1, line = 0, flag = 0;

    while (!feof(fp)) {
        fgets(buf, sizeof(buf), fp);
        line++;
        p = buf;
        while (*p) {
            if (*p == key[0] && s == -1) {
                s = 0;
            } else if (*p == key[s + 1]) {
                s++;
            } else {
                s = -1;
            }
            p++;
            if (s == key.size() - 1) {
                s = -1;
                if (flag == 0) {
                    ofs << line;
                    flag = 1;
                    break;
                } else if (flag == 1) {
                    ofs << "," << line;
                    flag = 1;
                    break;
                }
            }
        }
        s = -1;
    }
    ofs << endl;
}

void keysLine(string fileName, string wfileName) {
    int i = 0;
    while (!keys[i].empty()) {
        searchFile(fileName, wfileName, keys[i]);
        i++;
    }
}

int main(int argc, char *argv[]) {
    // readFile(argv[1],word); // readFile("Arsmstrong.txt");
    readFile(argv[2]); // readKeys

    // wordFreq();
    keysLine(argv[1], argv[3]);

    return 0;
}
