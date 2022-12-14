#include <bits/stdc++.h>
using namespace std;

int main()
{
	int trees[99][99];
	int counted[99][99]={0};
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
	cout<<"end input"<<endl;
	int visible = 392; //edges
	for(int i=0; i<99; i++)
	{
		counted[i][0]=1;
		counted[i][98]=1;
	}
	for(int i=0; i<99; i++)
	{
		counted[0][i]=1;
		counted[98][i]=1;
	}
	cout<<"start left to right"<<endl;
	for(int i=1; i<98; i++) //left to right
	{
		int highest=-1;
		for(int j=0; j<99; j++)
		{
			if(trees[i][j]>highest)
			{
				highest=trees[i][j];
				counted[i][j]=1;
				if(j!=0 && j!=98)
					visible++;
			}
		}
	}
	cout<<"end left to right"<<endl;
	for(int i=1; i<98; i++) //right to left
	{
		int highest=-1;
		for(int j=98; j>=0; j--)
		{
			if(trees[i][j]>highest)
			{
				highest=trees[i][j];
				if(j!=0 && j!=98 && !counted[i][j])
				{
					visible++;
				}
				counted[i][j]=1;
			}
		}
	}
	for(int j=1; j<98; j++) //top to bottom
	{
		int highest=-1;
		for(int i=0; i<99; i++)
		{
			if(trees[i][j]>highest)
			{
				highest=trees[i][j];
				if(i!=0 && i!=98 && !counted[i][j])
				{
					visible++;
				}
				counted[i][j]=1;
			}
		}
	}
	for(int j=1; j<98; j++) //bottom to top
	{
		int highest=-1;
		for(int i=98; i>=0; i--)
		{
			if(trees[i][j]>highest)
			{
				highest=trees[i][j];
				if(i!=0 && i!=98 && !counted[i][j])
				{
					visible++;
				}
				counted[i][j]=1;
			}
		}
	}
	cout<<visible;
}
