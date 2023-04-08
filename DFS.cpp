#include<bits/stdc++.h>
using namespace std;
int A[50][50],n,chuaxet[50];
void init(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		chuaxet[i]=1;
		for(int j=1;j<=n;j++)
		{
			cin>>A[i][j];
		}
	}
}
void DFS_Dequy(int u)
{
	chuaxet[u]=0;
	for(int v=1;v<=n;v++)
	{
		if(A[u][v]&&chuaxet[v])
		DFS_Dequy(v);
	}
}
void DFS_Stack(int u)
{
	int x[50],dem=0;
	stack<int> st;
	st.push(u);
	chuaxet[u]=0;
	x[dem++]=u;
	while(!st.empty())
	{
		int s=st.top();st.pop();
		for(int t=1;t<=n;t++)
		{
			if(A[s][t]&&chuaxet[t])
			{
				chuaxet[t]=0;
				st.push(s);
				st.push(t);
				x[dem++]=t;
				break;
			}
		}
	}
	for(int i=0;i<dem;i++)
	cout<<x[i]<<" ";
	cout<<endl;
	
}
main(){
	int u;
	init();
	cin>>u;
	DFS_Stack(u);
}
