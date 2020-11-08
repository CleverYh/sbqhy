#include <iostream>
#include <vector>
#include "check.h"
#include "MyArrayList.h"
//#include "ArrayList.cpp"


using namespace std;


  //ofstream out("temp.txt");

void print(T &c){
   cout << c<< " ";
}

void show(ArrayList v){
  for (size_t i=0;i<v.size();i++)
    cout << v[i] << " ";
  cout <<endl;
}

void show(vector<int> v){
  for (size_t i=0;i<v.size();i++)
    cout << v[i] << " ";
  cout <<endl;
}

bool cmp(ArrayList u, vector<int> v){
    if (u.size()!=v.size())
      return false;

   for (size_t i=0;i<u.size();i++){
         if (u[i]!=v[i]) 
             return false;
   }
   return true;
}
//show Obs + mes  if u and v are different
void show(ArrayList u, vector<int> v, string mes){
    if (!cmp(u,v))
      cout<<"Obs:"<<mes<<endl;
 //  else
  //    cout<<"Ok:"<<mes<<endl;
}         


 

int main(){

  ArrayList v0;
  vector<int> vec0;
  if (v0.size()!=vec0.size())
      cout <<"Obs: v.size()"<<endl;
  ArrayList v(10);
  vector<int> vec(10);
  if (v.size()!=vec.size())
    cout <<"Obs: v.size()"<<endl;
  v.clear();
  vec.clear();
  show(v, vec, "clear");
  vector<int> :: iterator it = vec.begin();
  for (size_t i=0; i<5; i++){
    v.insert(i, 2*i);
    vec.insert(it+i, 2*i);
  }
  v.traverse(print);

  v.insert(5, 5);
  v.insert(0, 10);
  v.insert(1, 10);

  it = vec.begin();
  vec.insert(it+5, 5);
  vec.insert(it+0, 10);
  vec.insert(it+1, 10); 
  show(v,vec,"insert");
 

  v.push_back(100);
  v.push_back(100);
  v.push_back(100);
  vec.push_back(100);
  vec.push_back(100);
  vec.push_back(100);
  show(v,vec,"push_back");


  v.erase(9);
  v.erase(8);
  v.erase(1);
  v.erase(0);
  v.erase(0);
  it = vec.begin();
  vec.erase(it+9);
  vec.erase(it+8);
  vec.erase(it+1);
  vec.erase(it+0);
  vec.erase(it+0);
  show(v,vec,"erase");

  ArrayList v1;
  ArrayList v2(v);
  vector<int> u1;
  vector<int> u2(vec);
  show(v2, u2,"copy constructor");


  v.push_back(100);
  vec.push_back(100);
  show(v2, u2, "copy constructor");


  v1 = v;
  v.push_back(200);
  u1 = vec;
  vec.push_back(200);
  show(v1, u1, "assignmnet");



  ArrayList *p = new ArrayList(v);
  vector<int> *p1 = new vector<int>(vec);
  show(*p, *p1, "assignment");

  delete p; 
  show(v2, u2, "destructor");

  for (size_t i=0; i<1000;i++){
    v2.insert(i, i);
    u2.insert(u2.begin()+i,i);
  }
  show(v2, u2, "insert");

  cout<<"OK"<<endl;
  return 0;
 

}