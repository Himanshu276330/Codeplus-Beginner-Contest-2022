#include<bits/stdc++.h>
using namespace std;

int main(){

	vector<int> dp(27,0);
	for(int i=1;i<=26;i++){
		dp[i]+=(dp[i-1]+pow(i,3));
	}

	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		n=n%dp[26];
		if(n==0) n=dp[26];
		for(int i=1;i<=26;i++){
			if(n<=dp[i]){
				cout<<(char)('a'+i-1)<<"\n";
				break;
			}
		}
	}
	return 0;
}