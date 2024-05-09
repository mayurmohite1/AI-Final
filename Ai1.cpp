#include <iostream>
using namespace std;

class graph
{
	public:
	int visited[20];
	int m[20][20];
	int n;
	void accept();
	void display();
	void dfs (int);
	void bfs (int);
	int returnN()
	{
		return n;
	}
};


void graph::accept()
{
	cout<<"\nThe number of vertices are \n";
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	cout<<"\nEnter the value in adjacency matrix \n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>m[i][j];
		}
	}
}

void graph::display()
{
	cout<<"\n The adjacency matrix is \n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"\t"<<m[i][j];
		}
	}
}

void graph::dfs(int v)
{
	cout<<"\n"<<v<<" ";
	visited[v]=1;
	for(int i=1;i<=n;i++)
	{
		if(m[v][i]==1 && visited[i]==0)
		{
			dfs(i);
		}
	}
}


void graph::bfs(int v)
{
	int queue[20];
	int front=0,rear=0;
	visited[v]=1;
	cout<<v<<" ";
	queue[++rear]=v;
	while(front!=rear)
	{
		v=queue[++front];
		for(int j=1;j<=n;j++)
		{
			if(m[v][j]==1 && visited[j]==0)
			{
				queue[++rear]=j;
				visited[j]=1;
				cout<<j<<" ";
			}
		}
	}
}



int main()
{
	graph g;
	g.accept();
	g.display();
	int n;
	cout<<"\nThe number of vertices are \n";
	cin>>n;
	g.dfs(1);
	for(int i=1;i<=n;i++)
	{
		g.visited[i]=0;
	}
	g.bfs(1);
}