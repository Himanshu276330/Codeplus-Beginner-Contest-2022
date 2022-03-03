#include <bits/stdc++.h>
using namespace std;

bool check(int mid,int a[],int n,int k){
	int count=0;
	int sum=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]>mid) return 0;
		sum+=a[i];
		cnt++;
		if(sum>mid || cnt>2){
			count++;
			sum=a[i];
			cnt=1;
		}
	}
	count++;
	if(count<=k) return 1;
	return 0;
}

int solve(int a[],int n,int k){
	int* max=max_element(a,a+n);
	int start=*max;
	int end=0;
	for(int i=0;i<n;i++){
		end+=a[i];
	}
	int answer=0;
	while(start<=end){
		int mid=(start+end)/2;
		if(check(mid,a,n,k)){
			answer=mid;
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return answer;
}

int findPermutation(int a[],int n,int k){
	int ans=INT_MAX;
	sort(a,a+n);

	do{
		ans=min(ans,solve(a,n,k));
		// cout<<"tt"<<endl;
	}while(next_permutation(a,a+n));

	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n,k;
		cin>>n>>k;
		int a[n];
		int mm=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			mm=max(mm,a[i]);
		}
		if(k>=n){
			cout<<mm<<"\n";
			continue;
		}
		cout<<findPermutation(a,n,k)<<"\n";
	}

	return 0;
}



