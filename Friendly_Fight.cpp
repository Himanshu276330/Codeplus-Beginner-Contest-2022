#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int a,b;
		cin>>a>>b;
		int ac=0,bc=0;
		for(int i=0;i<32;i++){
			if((a&(1<<i))>0 && (b&(1<<i))>0) ac+=i;
			else if((a&(1<<i))>0 || (b&(1<<i))>0) bc+=i;
		}
		if(ac>bc){
			cout<<"SHANTANU\n";
		}else if(ac<bc){
			cout<<"GAUTAM\n";
		}else{
			cout<<"DRAW\n";
		}
		cout<<abs(ac-bc)<<"\n";
	}
	return 0;
}
