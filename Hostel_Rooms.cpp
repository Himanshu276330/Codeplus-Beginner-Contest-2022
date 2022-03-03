#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	string str;
	int rn;
	vector<vector<int>> arr(6,vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		cin>>str>>rn;
		string ss=str.substr(3,4);
		int tt=stoi(ss);
		arr[tt-2015][rn]++;
	}
	for(int i=0;i<=5;i++){
		for(int j=2;j<=n;j++){
			arr[i][j]+=arr[i][j-1];
		}
	}

	// for(int i=0;i<=5;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	int y,l,r;
	for(int i=1;i<=q;i++){
		cin>>y>>l>>r;
		if(l==1){
			cout<<arr[y-2015][r]<<"\n";
		}else{
			cout<<arr[y-2015][r]-arr[y-2015][l-1]<<"\n";
		}	
	}
}

int main(){	
	int t=1;
	while(t-->0){
		solve();
	}
	return 0;
}