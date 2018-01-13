#include "team.h"
team::team(string n) // constructor
{
	name=n;
	points=0;
	goals_scored=0;
	goals_received=0;
	right =NULL ;
	left = NULL ;
}
team::team(string s,int n1,int n2,int n3)// constructor
{
	name=s;
	points=n1;
	goals_scored=n2;
	goals_received=n3;
}
team::~team()
{
}
string team::get_name_team()
{
	return name;
}
void team::set_name_team(string s)
{
	name=s;
}
int team::get_points()
{
	return points;
}
void team::set_points(int n)
{
	points=n;
}
/*int team::get_goals_scored()
{
	int s=0;
	for(int i=0;i<24;i++)
		s=s+p[i].get_goals();
	return s;
}*/
void team::set_goals_scored(int n)
{
	goals_scored=n;
}
int team::get_goals_received()
{
	return goals_received;
}
void team::set_goals_received(int n)
{
	goals_received=n;
}
/*void team::view_players()
{
	for(int i=0;i<24;i++)
	{
		cout<<i+1<<"-"<<p[i].get_name()<<endl;
	}
}*/

void team::set_players(map<string,player> m)
{
		p = m ;
}

void team :: view_players()   // iterate over the map to get the every player object & its info
{
	 int i=0 ; 
	for (map<string,player>::iterator im = p.begin();im != p.end() ; im ++ )
	{ 
			cout<< ++i<<" - " << im->first<<" \t>>\t " ;
			(im->second).get_info_player();		
	}	
}

	void team:: search_player(string s) // search by using count method in the map
	{
		if (p.count(s)==0) // not found
			cout<<"OO OO  Not Found !!!!!!!!!! " <<endl;
		
		else   //found  
		{
		cout<<s<<"\t";
			p[s].get_info_player();

		}
	}

	bool team :: is_leaf()  // check if the team is in the end of the tree 
	{

		if (right==NULL && left == NULL )
			return true ;
			return false ; // otherwise
	}