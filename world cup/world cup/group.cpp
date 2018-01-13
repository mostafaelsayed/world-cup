#include "group.h"
void group::set_team(string s1,string s2) // 
{
	teams[s1].push_back(s2); // map of teams and their stats
}
void group::view_teams()
{	
		for(map<string,vector<string>>::iterator i=teams.begin();i!=teams.end();i++)
		{
			cout<<i->first<<endl;
			for(int j=0;j<teams[i->first].size();j++)
			{
			cout<<teams[i->first][j]<<endl;
			}
			for(int k=0;k<4;k++)
			cout<<endl;
		}
}
void group::set_match(string s1,string s2) // and push result in v2
{
	matches[s1].push_back(s2);
}
void group::view_matches()
{
	for(map<string,vector<string>>::iterator i=matches.begin();i!=matches.end();i++)
		{
			cout<<i->first<<endl;
			for(int j=0;j<matches[i->first].size();j++)
			{
			cout<<matches[i->first][j]<<endl;
			}
			for(int k=0;k<4;k++)
			cout<<endl;
		}
}