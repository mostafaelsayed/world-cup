#include "player.h"
 class team
{
private:
	string name;
	int points;
	int goals_scored;
	int goals_received;
	map <string,player> p;
	team * right ;
	team * left ;
public:
	team(string n); // intializing by name only and all remainder attributes = 0 & NULL
	team(string s,int n1,int n2,int n3); // intializing by all attributes but  NULL for pointers (right ,left)
	~team();
	string get_name_team(); // fakess
	void set_name_team(string s); // fakess
	int get_points();
	void set_points(int n);
	int get_goals_scored();
	void set_goals_scored(int n);
	int get_goals_received();
	void set_goals_received(int n);
	void view_players(); // view players of  a team
	void set_players(map<string,player> m) ; // set a map of players to a team
	void search_player(string s) ; // search a team for a certain player
	bool is_leaf() ;  // check if this team is in the end of the tree
	friend class world ;
	friend class player;
	friend class group;
 };
