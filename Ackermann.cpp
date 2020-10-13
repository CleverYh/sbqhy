#include <iostream>

using namespace std;

// int ack(int m, int n) {
//     while (m != 0) {
//         if (n == 0)
//             n = 1;
//         else {
//             n = ack(m, n - 1);
//         }
//         m--;
//     }
//     return n + 1;
// }

void move (int count,int start, int finish,int temp,int &sbqhy){
    if(count>0) {
        move(count-1,start,temp,finish,sbqhy);
        sbqhy++;
        move(count-1,temp,finish,start,sbqhy);
    }
}

int main() {
    int sbqhy = 0;
    move(4, 3, 1, 2, sbqhy);
    cout << sbqhy<<endl;
    return 0;
}