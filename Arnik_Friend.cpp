
#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int mod_inv(int a){
	int p=mod-2,res=1;
	while(p>0){
		if(p&1){
			res=(res*1LL*a)%mod;
		}
		p=(p>>1);
		a=(a*1LL*a)%mod;
	}
	return res%mod;
}
int fact(int n){
	int res=1;
	for(int i=1;i<=n;i++){
		res=(res*1LL*i)%mod;
	}
	return res;
}

int main(){
	int n,a,cnt=0;
	cin>>n;
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		cin>>a;
		mp[a]++;
	}
	int ans=fact(n)%mod;
	for(auto &it:mp){
		if(it.second>1){
			cnt=it.second;
			for(int i=1;i<=cnt;i++){
				ans=(ans*1LL*mod_inv(i))%mod;
			}
		}
	}
	cout<<ans<<"\n";

	return 0;
}