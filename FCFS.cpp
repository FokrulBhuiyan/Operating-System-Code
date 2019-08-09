#include<iostream>
#include<queue>
using namespace std;

class process{
public:
	int pid;
	double bt;
	double at;
	double wt;
	double tt;
};
void ganttchart(process p[],queue <int> q){
	int init=0,temp=0;
	cout<<init;
	while(!q.empty()){
		p[temp].wt = init;
		p[temp].tt = p[temp].wt + p[temp++].bt;
		init+=q.front();;
		cout<<"----"<<init;
		q.pop();
	}
	cout<<endl<<"p\twt\ttt";
	for(int i =0;i<temp;i++){
		cout<<endl<<"p"<<i+1<<"\t"<<p[i].wt<<"\t"<<p[i].tt;
	}
}

int main(){
	 process p[100];
	 int n;
	 cout<<"Enter number of process: ";
	 cin>>n;
	 queue <int> q;
	 for(int i=0;i<n;i++){
	 	cout<<"Enter beust time for p"<<i+1<<": ";
	 	cin>>p[i].bt;
	 	q.push(p[i].bt);
	 }
	 ganttchart(p,q);
}
