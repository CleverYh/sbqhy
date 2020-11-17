#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>

using namespace std;

void createPhoneNumberMap(map<string,string> &f){
    int n; // customers num
    string str,name,phone;
    cin>>n;
    for(int i = 0;i < n;i++) {
        cin>>str;
        int comma = str.find(",");
        name = str.substr(0,comma);
        phone = str.substr(comma+1);
        f[name] = phone;
    }
}


void phoneNumberSearch(map<string,string> &f) {
    int m; // names num
    queue<string> names;
    string name;
    cin>>m;
    for (int i = 0; i < m; i++) {
        cin>>name;
        names.push(name);
    }

    for (int i = 0; !names.empty(); i++) {
        name = names.front();
        names.pop();
        cout<<name<<":";
        if(f[name]!="") cout<<f[name]<<endl;
        else cout<<"No"<<endl;
    }
    
    
}

int main(){
    map<string,string> f;
    createPhoneNumberMap(f);
    phoneNumberSearch(f);
    return 0;
}