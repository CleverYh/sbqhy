#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// #define SIZE 1024;

string word[1024];
int cnt[1024], record[1024];

void readFile(string fileName) {
    string w;
    // char ch;
    ifstream ifs(fileName);
    if (!ifs) {
        cout << "cannot open the file" << endl;
        return;
    }
    int i = 0;
    while (ifs >> w) {

        for (int j = 0; j < w.size(); j++) {
            if (!((w[j] >= 65 && w[j] <= 90) || (w[j] >= 97 && w[j] <= 122))) {
                w.erase(j);
            }
        }
        word[i] = w;
        // cout << word[i] << " ";
        i++;
    }
    cout << endl;
    ifs.close();
}

void writeFile(string fileName) {
    ofstream ofs(fileName);
    
    for (int i = 0, j = 0; !word[i].empty(); i++) {
        if (record[i] == 1) continue;
        ofs << word[i] << " " << cnt[j] << endl;
        j++;
    }
}

void wordFreq() {
    for (int i = 0; i < 1024; i++) {
        cnt[i] = 1;
    }
    for (int i = 0; !word[i + 1].empty(); i++) {
        for (int j = 0; !word[j + i + 1].empty(); j++) {
            if (word[j] > word[j + 1]) {
                string temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }

    // for(int i = 0; !word[i].empty(); i++){
    //     cout << word[i] << " ";
    // }

    int flag = 0, c = 0;

    for (int i = 0; !word[i + 1].empty(); i++) {
        if (word[flag] == word[i + 1]) {
            record[i + 1] = 1;
            cnt[c]++;
            // i++;
        } else {
            c++;
            flag = i + 1;
        }
    }

}

int main(int argc, char *argv[]) {
    readFile(argv[1]); // readFile("Arsmstrong.txt");
    wordFreq();
    writeFile(argv[2]);

    return 0;
}
