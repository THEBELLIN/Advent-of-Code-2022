#include <bits/stdc++.h>
using namespace std;

int sum=0;
string line;
int deletedsize=30000000;

int inside(int targetsize)
{
	int dirsize=0;
	while(1)
	{
		if(line=="stop")
			break;
		getline(cin, line);
		if(line=="stop")
			break;
		if(line[0]>='1' && line[0]<='9') //file
		{
			for(int i=0; i<line.length(); i++)
			{
				if(line[i]==' ')
				{
					dirsize+=stoi(line.substr(0,i));
					break;
				}
			}
		}
		else if(line[0]=='$') //command
		{
			if(line[2]=='l') //ls
				continue;
			if(line[5]=='.') //cd ..
			{
				if(dirsize<=100000)
					sum+=dirsize;
				if(dirsize>=targetsize && dirsize<deletedsize)
					deletedsize=dirsize;
				return dirsize;
			}
			else //inside new directory
				dirsize+=inside(targetsize);
		}
	}
	if(dirsize<=100000)
		sum+=dirsize;
	if(dirsize>=targetsize && dirsize<deletedsize)
		deletedsize=dirsize;
	return dirsize;
}

int main()
{
	int totalsize = inside(0);
	deletedsize=30000000;
	line=" ";
	//INPUT MUST BE REPEATED HERE
	int discard = inside(30000000 - (70000000-totalsize));
	cout<<deletedsize;
}
