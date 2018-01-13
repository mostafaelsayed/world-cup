#include"world.h"
void main()
{
	string teams1[32]={"algeria","america","argentina","australia","belgium","bosnia","brazil","cameron","chile","colombia","costa rica","cote de voir","croatia","ecuador","england","france","germany","ghana","greece","honduras","iran","italy","japan","mexico","netherlands","nigeria","portugal","russia","south korea","spain","switzerland","uruguay"} ;
	world *w1=new world(teams1);
	w1->load_time();
	while(1)
	{
	l1:cout<<"Enter the operation you want"<<endl;
	cout<<"Press 1 if you wanna view teams statistics in each group"<<endl;
	cout<<"press 2 if you wanna view matches statistics in each group"<<endl;
	cout<<"press 3 if you wanna search a specific player statistics"<<endl;
	cout<<"press 4 if you wanna view team players"<<endl;
	cout<<"press 5 if you wanna view specific team statistics"<<endl;
	cout<<"press 6 if you wanna view specific match statistics"<<endl;
	cout<<"press 7 if you wanna exit"<<endl;
	int b;
	cin>>b;
	if(b==1)
	{
		cout<<"enter the group number"<<endl;
		int a1;
		cin>>a1;
		w1->get_group(a1).view_teams();
		goto l1;
	}
	else if(b==2)
	{
		cout<<"enter the group number"<<endl;
		int a1;
		cin>>a1;
		w1->get_group(a1).view_matches();
		goto l1;
	}
	else if(b==3)
	{
		string s1,s2;
		cout<<"enter the player name : ";
		cin>>s1;
		cout<<"Enter the team name of this player : ";
		cin>>s2;
		w1->find_in_team(s2,s1);
	}
	else if(b==4)
	{
		cout<<"Enter the team name : "<<endl;
		string f;
		cin>>f;
		w1->view_team(f);
	}
	else if(b==5)
	{
		cout<<"Enter the team name : "<<endl;
		string f;
		cin>>f;
		w1->view_specific_team_stats(f);
	}
	else if(b==6)
	{
		cout<<"Enter the first team name : "<<endl;
		string f1;
		cin>>f1;
		cout<<"Enter the second team name : "<<endl;
		string f2;
		cin>>f2;
		if(w1->view_specific_match_stats(f1+":"+f2))
		{
		}
		else if(w1->view_specific_match_stats(f2+":"+f1))
		{
		}
		else
		{
			cout<<"Error...this match is not in the world cup"<<endl;
		}
	}
	else if(b==7)
	{
		break;
	}
	else
	{
		cout<<"Error...try again";
		goto l1;
	}
	}
}