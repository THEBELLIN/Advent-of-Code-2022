#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c;
	int tempsum = 0;
	vector<int> sums;
	string line;
	while(1)
	{
		getline(cin, line);
		if(line=="stop")
			break;
		if(line.length()==0)
		{
			sums.push_back(tempsum);
			tempsum=0;
			continue;
		}
		c=stoi(line);
		tempsum+=c;
	}
	sort(sums.rbegin(), sums.rend());
	cout<<sums[0]+sums[1]+sums[2];
}
