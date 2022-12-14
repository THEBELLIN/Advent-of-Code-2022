#include <bits/stdc++.h>
using namespace std;

int visited[1001][1001]={0};   //500, 500 is the middle
pair<int, int> head, tail;     //x, y coords

void updateTail()
{
	int hx=head.first, hy=head.second, tx=tail.first, ty=tail.second;
	if(hy==ty+2 && hx==tx) //straight up
		tail.second++;
	if(hy==ty-2 && hx==tx) //straight down
		tail.second--;
	if(hx==tx-2 && hy==ty) //straight left
		tail.first--;
	if(hx==tx+2 && hy==ty) //straight right
		tail.first++;
	if((hy==ty+2 && hx==tx+1) || (hy==ty+1 && hx==tx+2)) //diagonal upright
	{
		tail.first++;
		tail.second++;
	}
	if((hy==ty-2 && hx==tx+1) || (hy==ty-1 && hx==tx+2)) //diagonal downright
	{
		tail.first++;
		tail.second--;
	}
	if((hy==ty-2 && hx==tx-1) || (hy==ty-1 && hx==tx-2)) //diagonal downleft
	{
		tail.first--;
		tail.second--;
	}
	if((hy==ty+2 && hx==tx-1) || (hy==ty+1 && hx==tx-2)) //diagonal upleft
	{
		tail.first--;
		tail.second++;
	}
	visited[tail.first][tail.second]=1;
}

void nextStep(char dir)
{
	if(dir=='L')
		head.first--;
	if(dir=='R')
		head.first++;
	if(dir=='D')
		head.second--;
	if(dir=='U')
		head.second++;
	updateTail();
}

void nextCommand(char dir, int steps)
{
	for(int i=0; i<steps; i++)
		nextStep(dir);
}


int main()
{	
	head={500,500};
	tail=head;
	visited[500][500]=1;
	char dir;
	int steps;
	while(dir!='S')
	{
		cin>>dir;
		cin>>steps;
		nextCommand(dir, steps);
	}
	int ans=0;
	for(int i=0; i<1001; i++)
		for(int j=0; j<1001; j++)
			if(visited[i][j])
				ans++;
	cout<<ans;
}