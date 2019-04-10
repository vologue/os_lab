#include<iostream>
#include<algorithm>

using namespace std;

int check(int *f,int *n,int w, int s){
	for(int i=0;i<s;i++){
		if(f[i]==0 && w>=n[i]){
			return i;
		}
	}
	return -1;
}

bool fcheck(int *f,int n){
	for(int i=0;i<n;i++){
		if(f[i]==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	cout<<"Enter number of Processes: ";
	int n;
	cin>>n;
	int p[n],need[n],a[n],m[n],available,work,f[n],ss[n];
	cout<<"Enter allocation:\n";

	for(int i=0;i<n;i++){
		cin>>p[i];
	}

	cout<<"Enter Max:\n";
	for(int i=0;i<n;i++){
		cin>>m[i];
	}

	for(int i=0;i<n;i++){
		need[i]=m[i]-p[i];
		f[i]=0;
	}

	cout<<"Enter Available: ";
	cin>>available;
	work=available;
	int c;
	c=check(f,need,work,n);
	int count=0;
	while(c>=0){
        //cout<<work<<"\n";
		f[c]=1;
		ss[count]=c+1;
		count++;
		work=work+p[c];
		c=check(f,need,work,n);
	}
	if(fcheck(f,n)){
		cout<<"Safe State";
		cout<<"\nSafety Seq: ";
		for(int i=0;i<n;i++){
			cout<<ss[i]<<" ";
		}
	}
	else{
		cout<<"Unsafe State";
	}

//010 200 302 211 002

	return 0;
}
