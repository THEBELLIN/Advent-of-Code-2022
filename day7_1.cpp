#include <bits/stdc++.h>
using namespace std;

int sum=0;
string line;

int inside()
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
				return dirsize;
			}
			else //inside new directory
				dirsize+=inside();
		}
	}
	if(dirsize<=100000)
		sum+=dirsize;
	return dirsize;
}

int main()
{
	int discard = inside();
	cout<<sum;
}







//TO BE FIXED
/*struct dir
{
	string name;
	int size = 0;
	dir* parent;
};

int main()
{
	vector<dir*> sys;
	int ans=0;
	dir m;
	m.name="/";
	m.parent=&m;
	sys.push_back(&m);
	string flush;
	cin>>flush; //discard first $cd /
	dir* currentdir=&m;
	while(1)
	{
		string line;
		getline(cin, line);
		cout<<"Processing line: "<<line<<endl;
		if(line=="stop")
			break;
		if(line[0]=='$') //command
		{
			if(line[2]=='c') //cd
			{
				string cmd = line.substr(5);
				if(cmd=="..")
					currentdir=currentdir->parent;
				else
				{
					for(int i=0; i<sys.size(); i++)
					{
						if((*sys[i]).name==cmd)
						{
							currentdir=sys[i];
							break;
						}
					}
				}
			}
		}
		if(line[0]=='d') //dir found
		{
			dir newdir;
			string name=line.substr(4);
			newdir.name=name;
			newdir.parent=currentdir;
			sys.push_back(&newdir);
		}
		else //file found
		{
		    stringstream l(line);
			int s;
			l>>s;
			currentdir->size+=s;
		}
	}
	for(int i=0; i<sys.size(); i++)
	{
		if((*sys[i]).size<=100000)
			ans+=(*sys[i]).size;
	}
	cout<<ans;
}*/
