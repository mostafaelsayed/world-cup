#include"team.h"
class group
{
private:
	map<string,vector<string>> matches; // map of matchs key is the match name(men m3 men) and value is string vector of its stats()
	map<string,vector<string>> teams; // map of teams key is team name and value is vector of its stats
public:
	void set_team(string s1,string s2); // working on m3
	void view_teams();
	void view_matches();
	void set_match(string s1,string s2); // working on m2
	friend class world;
	friend class player;
	friend class team;
};