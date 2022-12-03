#include <bits/stdc++.h>
using namespace std;

int main()
{
	string line;
	int sum = 0;
	while(1)
	{
		getline(cin, line);
		if(line=="stop")
			break;
		string s1 = line.substr(0, line.length()/2);
		string s2 = line.substr(line.length()/2, line.length()/2);
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		int i=0, j=0, value; 
		while(i<s1.length() && j<s2.length())
		{
			if(s1[i]==s2[j])
			{
				if((s1[i]-'a'+1)>0)
					value = s1[i]-'a'+1;
				else
					value = s1[i]-'A'+27;
				sum+=value;
				break;
			}
			if(s1[i]>s2[j])
			{
				j++;
				continue;
			}
			else
			{
				i++;
				continue;
			}
		}
	}
	cout<<sum;
}