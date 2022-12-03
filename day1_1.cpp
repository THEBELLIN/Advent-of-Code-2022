#include <bits/stdc++.h>
using namespace std;

int main()
{
	int max = -1;
	int c;
	int tempsum = 0;
	string line;
	while(1)
	{
		getline(cin, line);
		if(line=="stop")
			break;
		if(line.length()==0)
		{
			if(tempsum>max)
				max=tempsum;
			tempsum = 0;
			continue;
		}
		c=stoi(line);
		tempsum+=c;
	}
	cout<<max;
}
