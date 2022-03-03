#include <bits/stdc++.h>
using namespace std;

int main(){
	set<pair<int,int>> st;
	vector<pair<int,int>> ans;
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a>b){
			a=a^b; b=a^b; a=a^b;
		}
		if(st.find({a,b})==st.end()){
			st.insert({a,b});
		}else{
			ans.push_back({a,b});
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}

	return 0;
}
