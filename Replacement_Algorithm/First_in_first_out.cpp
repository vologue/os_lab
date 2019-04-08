#include<iostream>
#include<algorithm>

using namespace std;

struct page{
    int num;
};

bool checkin(page *ar,int n,int num){     //Returns 1 if the page already is in the memory
    for(int i=0;i<n;i++){
        if(num==ar[i].num){
            return 1;
        }
    }
    return 0;
}

int main(){
    int a[]={1,2,3,4,5,6,3,2,5,2};                              //take input in array a and size in insize
    int n,insize=10,page_faults=0;                              //number of pages we can store at one time
    cin>>n;
    page ar[10]={0};

    for(int i=0; i<insize; i++){                  
        if(!checkin(ar,n,a[i])){
            ar[i%n].num=a[i];                   //Replacement
            page_faults++;
        }
    }
    cout<<"Pages in the Memory: ";
    for(int i=0;i<n;i++){
        cout<<ar[i].num<<" ";
    }
    cout<<"\nPage Faults: "<<page_faults-n<<"\n";
    return 0;
}