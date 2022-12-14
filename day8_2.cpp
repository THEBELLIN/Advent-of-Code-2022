#include <bits/stdc++.h>
using namespace std;

int trees[99][99];

int score(int i, int j)
{
	int left=0, right=0, top=0, bottom=0;
	for(int l=j-1; l>=0; l--) //left
	{
		left++;
		if(trees[i][l]<trees[i][j])
			continue;
		else
			break;
	}
	for(int r=j+1; r<99; r++) //right
	{
		right++;
		if(trees[i][r]<trees[i][j])
			continue;
		else
			break;
	}
	for(int t=i-1; t>=0; t--) //top
	{
		top++;
		if(trees[t][j]<trees[i][j])
			continue;
		else
			break;
	}
	for(int b=i+1; b<99; b++) //bottom
	{
		bottom++;
		if(trees[b][j]<trees[i][j])
			continue;
		else
			break;
	}
	return left*right*top*bottom;
}

int main()
{
	
	for(int i=0; i<99; i++)
	{
		string l;
		getline(cin, l);
		stringstream line(l);
		for(int j=0; j<99; j++)
		{
			char c;
			line>>c;
			int d=c-'0';
			trees[i][j]=d;
		}
	}
	int highscore=-1;
	for(int i=0; i<99; i++) //forall trees
	{
		for(int j=0; j<99; j++)
		{
			int s=score(i, j);
			if(s>highscore)
				highscore=s;
		}
	}
	cout<<highscore;
}
