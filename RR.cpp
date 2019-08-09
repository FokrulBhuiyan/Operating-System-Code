#include<iostream>
#include<queue>
using namespace std;

class process{
public:
	int pid;
	double bt;
	double wt;
	double tt;
};
void ganttchart(process p[], int n, int q){
	int temp=0;
    int t = 0;
    cout<<t;
    for(int i=0;i<n;i++)
    {
        bool x = true;
        for (int i = 0 ; i < n; i++)
        {
            if (p[i].bt > 0)
            {
                x = false;
                if (p[i].bt > q)
                {
                    t += q;
                    p[i].bt -= q;
                }
                else
                {
                    t = t + p[i].bt;
                    p[i].wt= t - p[i].bt;
                    p[i].bt = 0;
                }
            }
        }
        cout<<"----"<<t;
        
        if (x == true)
          break;
    }
	cout<<endl<<"p\twt\ttt";
	for(int i =0;i<temp;i++){
		cout<<endl<<"p"<<i+1<<"\t"<<p[i].wt<<"\t"<<p[i].tt;
	}
}
int main()
{
    process p[100];
    int n,q;
	 cout<<"Enter number of process: ";
	 cin>>n;
	 cout<<"Enter time retio: ";
	 cin>>q;
	 for(int i=0;i<n;i++){
	 	cout<<"Enter beust time for p"<<i+1<<": ";
	 	cin>>p[i].bt;
	 	p[i].pid=i+1;
	 }
	 ganttchart(p,n,q);
}

