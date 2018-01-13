#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
 class player
{
private:
	string name;
	int goals;
	int assists;
	int yellow;
	int red;
public:
	player();
	~player();
	string get_name();
	void set_name(string s);
	int get_goals();
	void set_goals(int n);
	int get_assists();
	void set_assists(int n);
	int get_yellow();
	void set_yellow(int n);
	int get_red();
	void set_red(int n);
	void get_info_player(); // printing the player info on the screen
	friend class team;
	friend class world;
	friend class group;
};