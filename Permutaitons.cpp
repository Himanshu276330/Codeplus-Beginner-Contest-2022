#include <bits/stdc++.h>
using namespace std;

void solve(int a,int n,vector<int> &arr,vector<bool> &vis){
	if(a>n){
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}
	if(arr[a]!=-1){
		solve(a+1,n,arr,vis);
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				arr[a]=i;[i]=a;
				vis[a]=1;vis[i]=1;

				solve(a+1,n,arr,vis);
                
				arr[a]=-1;arr[i]=-1;
				vis[a]=0;vis[i]=0;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		vector<int> arr(n+1,-1);
		vector<bool> vis(n+1,0);
		solve(1,n,arr,vis);
	}
	return 0;
}