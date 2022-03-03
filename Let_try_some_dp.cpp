#include <bits/stdc++.h>
using namespace std;

int main(){

	const int N=200001;
	vector<vector<int>> dp(N,vector<int>(32,0));
	for(int j=0;j<32;j++){
		for(int i=1;i<=200000;i++){
			if(i&(1<<j)){
				if(i==1){
					dp[i][j]++;
				}else{
					dp[i][j]+=1+dp[i-1][j];
				}
			}else{
				if(i!=1){
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}

	int t;
	cin>>t;
	while(t-->0){
		int l,r;
		cin>>l>>r;
		int tt=r-l+1;
		int ans=0;
		for(int i=0;i<32;i++){
			if(l==1){
				ans=max(ans,dp[r][i]);
			}else{
				ans=max(ans,dp[r][i]-dp[l-1][i]);
			}
		}
		cout<<tt-ans<<"\n";
	}

	return 0;
}