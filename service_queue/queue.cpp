#include "RANDOM.h"
#include <conio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <windows.h>

using namespace std;

typedef class {
public:
    int time;
    int num;
    int waitingTime;
    // showWaitingTime() {
    //     cout<<"No."<<num<<" waiting time:"<<waitingTime<<endl;
    // }
} customer;

class window {

public:
    static int windowNumber;
    int ongoing = 0;
    int doneNum = 0;
    int windowNum;
    int timeLeft = 0;

    window() {
        windowNum = windowNumber++;
    };

    void showOngoing() {
        cout << windowNum << " " << ongoing << endl;
    };
};
class Bank {

public:
    int waitNum = 0;
    int waitTime = 0;
    int totalTime = 0;
    queue<customer> q;
    window w[5];

    void showWaitNum() {
        cout << "There're " << waitNum << " customer(s) waiting." << endl;
    };
};

int main() {
    window::windowNumber = 0;
    int Time = 0;
    int Num = 0;
    Bank *b = new Bank;
    while (!kbhit()) {
        // t.get_time();
        // t.show_time();
        Random ncn = new Random(true);
        int newCustomerNum = ncn.poisson(Time);
        for (int i = 0; i < newCustomerNum; i++) {
            customer *n = new customer;
            n->time = ncn.poisson(Time);
            n->num = Num++;
            n->waitingTime = b->waitTime;
            b->q.push(*n);
            b->waitNum++;
            b->waitTime += n->time;
            b->totalTime += n->time;
        }

        for (int i = 0; i < 5; i++) {
            if (b->w[i].timeLeft <= 1 && b->q.size() > 0) {
                b->w[i].timeLeft = b->q.front().time;
                b->w[i].ongoing = b->q.front().num;
                b->w[i].doneNum++;
                b->q.pop();
            }
            if (b->w[i].timeLeft > 1) {
                b->w[i].timeLeft--;
            }
            b->w[i].showOngoing();
        }

        cout << "Press 'enter' to end" << endl;
        Sleep(1000);
        system("cls");
        Time++;
    }
    return 0;
}