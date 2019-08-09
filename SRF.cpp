#include<iostream>
using namespace std;

int main()
{
 int a[10],b[10],x[10];
 int waiting[10],turnaround[10],completion[10];
 int i,j,temp,count=0,time,n,end;
 cout<<"Enter the number of Processes: ";
 cin>>n;
 for(i=0;i<n;i++)
 {
 	cout<<"Enter arrival time of process : ";
 	cin>>a[i];
 }
 for(i=0;i<n;i++)
 {
 	cout<<"Enter burst time of process : ";
 	cin>>b[i];
 }
 for(i=0;i<n;i++)
 x[i]=b[i];

  b[9]=INT_MAX;
 for(time=0;count!=n;time++)
 {
   temp=9;
  for(i=0;i<n;i++)
  {
   if(a[i]<=time && b[i]<b[temp] && b[i]>0 )
   temp=i;
   //cout<<endl<<temp<<endl;
  }
  b[temp]--;
  cout<<time+1<<"--->p"<<temp<<endl;;
  if(b[temp]==0)
  {
   count++;
   //end=time+1;
   //cout<<endl<<"End time "<<end<<endl;
   waiting[temp] = time+1 - a[temp] - x[temp];
   turnaround[temp] = time+1 - a[temp];
  }
 }
 cout<<"\npid     \tburst     \tarrival     \twaiting     \tturnaround";
 for(i=0;i<n;i++)
 {
 	cout<<endl<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i];
 }
 return 0;
}
