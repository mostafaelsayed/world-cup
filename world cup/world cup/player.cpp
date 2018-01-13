#include "player.h"
player::player()
{
	name="" ;
	goals=0;
	assists=0;
	yellow=0;
	red=0;
}
player::~player()
{
}
string player::get_name()
{
	return name;
}
void player::set_name(string s)
{
	name=s;
}
int player::get_goals()
{
	return goals;
}
void player::set_goals(int n)
{
	goals=n;
}
int player::get_assists()
{
	return assists;
}
void player::set_assists(int n)
{
	assists=n;
}
int player::get_yellow()
{
	return yellow;
}
void player::set_yellow(int n)
{
	yellow=n;
}
int player::get_red()
{
	return red;
}
void player::set_red(int n)
{
	red =n;
}
void player::get_info_player()
{
		
			cout<<"goals : "<<get_goals() ; 
			cout<<"\t Yellow Cards : "<<get_yellow();
			cout<<"\t Red Cards : "<<get_red() ;
			cout<<"\t Assists : " <<get_assists()<<endl;

}