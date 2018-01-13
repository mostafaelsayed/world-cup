#include"group.h"
class world
{
private:
	team * root  ;	
	map<int,group> m;
public:
	void insert(int i,group g);
	group get_group(int i);
	void load_time();
	void view_specific_team_stats(string s);
	bool view_specific_match_stats(string s);
	world(string arr[]) ;   //constructing , loading names of teams from an array of teams names , team players : names & goals 
	void find_in_team(string t_n,string p_n ) ;   // find a given player name inside a given team
	void load_team_players_in_this_node(string team_name , team * team_ptr) ; // during loading the name of the each team , call this function to 
// load each team with its players 
	void view_team (string name) ;  // view team players by viewing players of every node (team) 
//some methods like is_Empty, insert, delete, Search, ..
	friend class group;
	friend class team;
	friend class player;
};
