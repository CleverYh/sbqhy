#include "setIntersection.h"

Set mySetIntersection(const Set A, const Set B){
	Set C;
	int k=0;
	for(int i = 0;i<A.size();i++){
		for(int j = k;j<B.size();j++){
			if(A[i] == B[j]){
				C.push_back(B[j]);
				k = j;
			}
		}
	}
	// for(int i = 0;i<C.size();i++) cout<<C[i]<<" ";
	return C;
}

void check(const Set A, const Set B){
	Set C = mySetIntersection(A,B);
	Set D = setIntersection(A,B);

	if(C.size()==0&&D.size()==0){
        cout<<"OK"<<endl;
        return;
    }
	if(C.size()==D.size()){
		int i;
		for(i=0;i<C.size();i++) {
			if(C[i]!=D[i]){
				cout<<"OBS"<<endl;
				break;
			} 
		}
		if(i == C.size()) cout<<"OK"<<endl;
	}else{
		cout<<"OBS"<<endl;
	}
	return;
}

int main() {
	int n;
	// cout<<"n"<<endl;
	cin>>n;
	
	while(n){
		int a,b;
		Set A,B;
		// cout<<"a"<<endl;
		cin>>a;
		for(int i = 0;i<a;i++){
			int tmp;
			cin>>tmp;
			A.push_back(tmp);
		}
		// cout<<"b"<<endl;
		cin>>b;
		for(int i = 0;i<b;i++){
			int tmp;
			cin>>tmp;
			B.push_back(tmp);
		}
		
		check(A,B);
		
		n--;
	}
	
	return 0;
}










