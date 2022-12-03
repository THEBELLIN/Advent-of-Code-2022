#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1, s2, s3;
	int sum = 0;
	while(1)
	{
		getline(cin, s1);
		if(s1=="stop")
			break;
		getline(cin, s2);
		getline(cin, s3);
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		sort(s3.begin(), s3.end());
		int i=0, j=0, value;
		while(i<s1.length() && j<s2.length())
		{
			if(s1[i]==s2[j])
			{
				bool f=false;
				for(int k=0; k<s3.length(); k++)
				{
					if(s1[i]==s3[k])
					{
						if((s1[i]-'a'+1)>0)
							value = s1[i]-'a'+1;
						else
							value = s1[i]-'A'+27;
						sum+=value;
						f=true;
						break;
					}
				}
				if(!f)
					i++;
                if(f)
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
