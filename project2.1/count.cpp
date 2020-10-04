#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// #define SIZE 1024;

string word[1024];
string keys[1024];
int cnt[1024], record[1024];

void readFile(string fileName,string array[]) {
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
        array[i] = w;
        // cout << word[i] << " ";
        i++;
    }
    cout << endl;
    ifs.close();
}

void mySort(string array[]) {
    for (int i = 0; !array[i + 1].empty(); i++) {
        for (int j = 0; !array[j + i + 1].empty(); j++) {
            if (array[j] > array[j + 1]) {
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void writeFile(string fileName) {
    ofstream ofs(fileName);

    mySort(keys); // sort keys

    for (int i = 0, j = 0; !word[i].empty(); i++) {
        if (record[i] == 1) continue;
        if (word[i] != keys[j]) continue;
        ofs << word[i] << " " << cnt[j] << endl;
        j++;
    }
}


void wordFreq() {
    for (int i = 0; i < 1024; i++) {
        cnt[i] = 1;
    }

    mySort(word);

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
    readFile(argv[1],word); // readFile("Arsmstrong.txt");
    readFile(argv[2],keys); // readKeys
    wordFreq();
    writeFile(argv[3]);

    return 0;
}
