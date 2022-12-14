#include <bits/stdc++.h>
using namespace std;

int visited[1001][1001]={0};   //500, 500 is the middle
pair<int, int> knots[10];     //x, y coords

void updateTail(int iHead, int iTail)
{
	int hx=knots[iHead].first, hy=knots[iHead].second, tx=knots[iTail].first, ty=knots[iTail].second;
	if(hy==ty+2 && hx==tx) //straight up
		knots[iTail].second++;
	if(hy==ty-2 && hx==tx) //straight down
		knots[iTail].second--;
	if(hx==tx-2 && hy==ty) //straight left
		knots[iTail].first--;
	if(hx==tx+2 && hy==ty) //straight right
		knots[iTail].first++;
	if((hy==ty+2 && hx==tx+1) || (hy==ty+1 && hx==tx+2) || (hy==ty+2 && hx==tx+2)) //diagonal upright
	{
		knots[iTail].first++;
		knots[iTail].second++;
	}
	if((hy==ty-2 && hx==tx+1) || (hy==ty-1 && hx==tx+2) || (hy==ty-2 && hx==tx+2)) //diagonal downright
	{
		knots[iTail].first++;
		knots[iTail].second--;
	}
	if((hy==ty-2 && hx==tx-1) || (hy==ty-1 && hx==tx-2) || (hy==ty-2 && hx==tx-2)) //diagonal downleft
	{
		knots[iTail].first--;
		knots[iTail].second--;
	}
	if((hy==ty+2 && hx==tx-1) || (hy==ty+1 && hx==tx-2) || (hy==ty+2 && hx==tx-2)) //diagonal upleft
	{
		knots[iTail].first--;
		knots[iTail].second++;
	}
	if(iTail==9)
		visited[knots[9].first][knots[9].second]=1;
}

void nextStep(char dir)
{
	if(dir=='L')
		knots[0].first--;
	if(dir=='R')
		knots[0].first++;
	if(dir=='D')
		knots[0].second--;
	if(dir=='U')
		knots[0].second++;
	for(int i=1; i<10; i++)
		updateTail(i-1, i);
}

void nextCommand(char dir, int steps)
{
	for(int i=0; i<steps; i++)
		nextStep(dir);
}


int main()
{	
	knots[0]={500,500};
	for(int i=1; i<10; i++)
		knots[i]=knots[0];
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