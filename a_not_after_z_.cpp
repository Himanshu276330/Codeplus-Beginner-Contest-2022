#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t-->0){
		string s1,s2;
		cin>>s1>>s2;
		int n1=s1.length();
		int n2=s2.length();
		bool f=1;
		int j=0;
		for(int i=0;i<n1;i++){
			if(j<n2 && s1[i]<=s2[j]){
				j++;
			}
		}
		if(j>=n2){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}