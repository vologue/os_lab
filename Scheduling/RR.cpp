#include <iostream>
#include <algorithm>

using namespace std;

struct process{
    int at;
    int bt;
    int tat;
    int et;
    int bt1;
    int wt;
};

bool comp (process lhs,process rhs){
    return (lhs.at<rhs.at);
}

bool maxcomp (process lhs,process rhs){
    return (lhs.bt<rhs.bt);
}


int main(){
    process ar[5]={{0,4,0,0,0,0},{2,3,0,0,0,0},{7,3,0,0,0,0},{0,6,0,0,0,0},{3,6,0,0,0,0}};
    for(int i=0;i<5;i++){
        ar[i].bt1=ar[i].bt;
    }
    int r;
    cin>>r;
    sort(ar,ar+5,comp);
    int t=0;
    cout<<"(ArrivalTime,BurstTime,WaitTime,TurnAroundTime): ";

    
    while(max_element(ar,ar+5,maxcomp)->bt>0){
        for(int i=0;i<5;i++){
            if(ar[i].at<=t){
                if(ar[i].bt>0){
                    if(ar[i].bt>r){
                        t+=r;
                        ar[i].bt-=r;
                    }
                    else{
                        t+=ar[i].bt;
                        ar[i].bt=0;
                        ar[i].et=t;
                        ar[i].tat=t-ar[i].at;
                        ar[i].wt=ar[i].tat-ar[i].bt1;
                    }
                }
            }
        }
        if(t==0){
            t=ar[0].at;
        }
    }
    double atat=0.0,awt=0.0;
        for(int j=0;j<5;j++){
            cout<<"("<<ar[j].at<<","<<ar[j].bt1<<","<<ar[j].wt<<","<<ar[j].tat<<") ";
            atat+=(double)ar[j].tat;
            awt+=(double)ar[j].wt;
        }
        cout<<"\nAWT: "<<awt/5<<"\nATAT: "<<atat/5<<"\n";

}