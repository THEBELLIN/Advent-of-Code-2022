#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string,int> scores=			  {{"A X", 4},
									   {"A Y", 8},
									   {"A Z", 3},
									   {"B X", 1},
									   {"B Y", 5},
									   {"B Z", 9},
									   {"C X", 7},
									   {"C Y", 2},
									   {"C Z", 6}};
	int totScore=0;
	while(1)
	{
		string s;
		getline(cin, s);
		if(s=="stop")
			break;
		totScore+=scores[s];
	}
	cout<<totScore;
}