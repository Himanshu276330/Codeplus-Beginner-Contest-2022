#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int mod=1e9+7;

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

int main(){

	int n,p,b;
	cin>>n>>p>>b;
	mod=p;

	vector<int> arr(n+1);
	map<ll,ll> mp;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}

	if(b>=p){
		cout<<0<<"\n";
		return 0;
	}

	ll ans=0;
	for(int i=1;i<=n;i++){
		ll tt=(b*(mod_inv(arr[i])))%mod;
		if(arr[i]==tt){
			ans=ans+mp[tt]-1;
		}else{
			ans=ans+mp[tt];
		}
	}

	cout<<ans/2<<"\n";

	return 0;
}