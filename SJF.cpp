#include <iostream>
using namespace std;

class process{
public:
	int pid;
	double bt;
	double wt;
	double tt;
};
void Sort(process p[], int n)
{
    int i, j;
    process temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1; j++)
        {
          if (p[j].bt > p[j+1].bt)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
        }
    }
}
void printArr(process p[],int count_){

for (int i=0; i<count_;i++){
        cout << p[i].bt<<" pid is: "<<p[i].pid <<endl;

    }

}
void ganttchart(process p[],int n){
	int init=0;
    int temp=0;
    cout<<n<<endl;
    printArr(p,n);
    Sort(p,n);
    printArr(p,n);
    cout<<endl<<init;
	for(int i=0;i<n;i++){
		p[i].wt = init;
		p[i].tt = p[i].wt + p[i].bt;
        init=init+p[i].bt;
        
		cout<<"----"<<init;
	}
	cout<<endl<<"p\twt\ttt";
	for(int i =0;i<n;i++){
		cout<<endl<<"p"<<p[i].pid<<"\t"<<p[i].wt<<"\t"<<p[i].tt;
	}
}

int main(){
	 process p[100];
	 int n;
	 cout<<"Enter number of process: ";
	 cin>>n;
	 for(int i=0;i<n;i++){
	 	cout<<"Enter beust time for p"<<i+1<<": ";
	 	cin>>p[i].bt;
	 	p[i].pid=i+1;
	 }
	 ganttchart(p,n);
}


