#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int max,min;
	Node *left,*right;
	Node(){
		left=nullptr;
		right=nullptr;
		max=0;
		min=INT_MAX;
	}
};

void dfs(int cur,int k,Node *root,vector<int> &arr){
	if(k<0){
		root->min=arr[cur];
		root->max=arr[cur];
		return;
	}
	Node *l=new Node();
	root->left=l;
	dfs(cur,k-1,l,arr);

	Node *r=new Node();
	root->right=r;
	int p=pow(2,k);
	dfs(cur+p,k-1,r,arr);

	root->min=min(root->left->min,root->right->min);
	root->max=max(root->left->max,root->right->max);

}

int solve(Node *root){
	if(root->left==nullptr){
		return root->max;
	}
	if(root->left->left==nullptr){
		return min(root->left->min,root->left->min);
	}
	return min(
		max(solve(root->left->left),solve(root->left->right))
		,max(solve(root->right->left),solve(root->right->right))
	);
}

int main(){
	int n;
	cin>>n;
	int k=n;
	n=pow(2,n);
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i-1>=0){
			arr[i]+=arr[i-1];
		}
	}
	Node *root=new Node();
	dfs(0,k-1,root,arr);
	cout<<solve(root)<<"\n";

	return 0;
}




