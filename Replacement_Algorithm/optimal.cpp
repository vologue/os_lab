#include<iostream>
#include<algorithm>

using namespace std;

struct page{
    int next;
    int num;
};

bool checkin(page *ar,int n,int num,int m){     //Returns 1 if the page already is in the memory
    for(int i=0;i<n;i++){
        if(num==ar[i].num){
            ar[i].next=-1;
            return 1;
        }
    }
    return 0;
}

bool comp(page a, page b) { 
    return (a.next < b.next); 
} 

int predict(page *ar,int arpos, int *a,int pos, int len){
    for(int i=pos+1;i<len;i++){
        if(ar[arpos].num==a[i]){
            return i;
        }
    }
    return INT8_MAX;                                                  //INT_MAX
}

void pred(page *ar,int *a,int i,int pos,int n){
    for(int l=0;l<n;l++){
        if(l!=pos)
        ar[l].next=predict(ar,l,a,i,10);
    }
}
int main(){
    int a[]={1,2,3,4,5,6,3,2,5,2};                              //take input in array a and size in insize
    int n,insize=10,page_faults=0;                              //number of pages we can store at one time
    cin>>n;
    page ar[10]={{0,0}};
    for(int i=0; i<insize; i++){
        if(!checkin(ar,n,a[i],i)){
            page *m;
            m= max_element(ar,ar+n,comp);
            m->num=a[i];
            m->next=-1;
            page_faults++;
            if(i>=n){
                pred(ar,a,i,(int)(m-ar),n);
                continue;
            }
        }
        else{
            int g;
            for(g=0;g<n;g++){
                if(ar[g].num==a[i])
                break;
            }
            pred(ar,a,i,g,n);
            continue;
        }
        if(i>=n)
        pred(ar,a,i,-1,n);
    }
    cout<<"Pages in the Memory: ";
    for(int i=0;i<n;i++){
        cout<<ar[i].num<<" ";
    }
    cout<<"\nPage Faults: "<<page_faults-n<<"\n";
    return 0;
}