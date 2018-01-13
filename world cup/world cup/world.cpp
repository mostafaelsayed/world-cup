#include"world.h"
void world::insert(int i,group g)
{	
	m[i]=g;
}
void world::load_time()
{
	for(int i=1;i<9;i++)
	{
		group gr; // group number i
		ostringstream s;
		s<<i;
		ifstream in1("group"+s.str()+".txt"); // input file whose name is group + group number
		string line; // to store match name(men m3 men)
		string g1; // store teams name (key)
		string l; // team stats
		for(int j=0;j<4;j++)
		{
			getline(in1,l); // team j name and its stats
			istringstream l1;
			l1.str(l); // stream of the j'th team name and its stats
			getline(l1,g1,' '); // team j name
			istringstream r; 
			r.str(l.substr(g1.length()+1,l.length()-g1.length())); // stream of team j states
			string h1,h2,h3,h4,h5,h6,h7,h8;
			getline(r,h1,' ');
			gr.set_team(g1,"Matchs Played:"+h1);
			getline(r,h2,' ');
			gr.set_team(g1,"Wins:"+h2);
			getline(r,h3,' ');
			gr.set_team(g1,"Draws:"+h3);
			getline(r,h4,' ');
			gr.set_team(g1,"Losses:"+h4);
			getline(r,h5,' ');
			gr.set_team(g1,"Goals Scored:"+h5);
			getline(r,h6,' ');
			gr.set_team(g1,"Goals Received:"+h6);
			getline(r,h7,' ');
			gr.set_team(g1,"Net Goals:"+h7);
			getline(r,h8,' ');
			gr.set_team(g1,"points:"+h8);
		} // we stored the information of each team of group j
		for(int j=0;j<6;j++)
		{
			getline(in1,line); // match between t1 and t2(map key)
			string l1,l2,l3,l4,l5,l6;
			getline(in1,l1);
			getline(in1,l2); 
			getline(in1,l3); 
			getline(in1,l4); 
			getline(in1,l5); 
			getline(in1,l6);
			gr.set_match(line,l1);
			gr.set_match(line,l2);
			gr.set_match(line,l3);
			gr.set_match(line,l4);
			gr.set_match(line,l5);
			gr.set_match(line,l6);
		}
		insert(i,gr);
	}
}
void world::view_specific_team_stats(string s)
{
	int n=0;
	for(int i=1;i<9;i++)
	{
			if(m[i].teams.count(s))
			{
				for(int j=0;j<m[i].teams[s].size();j++)
				{
				cout<<m[i].teams[s][j]<<endl;
				}
				n=1;
				break;
			}
	}
	if(n==0)
	{
		cout<<"Error...this team is not in the world cup"<<endl;
	}
}
bool world::view_specific_match_stats(string s)
{
	int n=0;
	for(int i=1;i<9;i++)
	{
			if(m[i].matches.count(s))
			{
				for(int j=0;j<6;j++)
				{
				cout<<m[i].matches[s][j]<<endl;
				}
				n=1;
				return true;
				break;
			}
	}
	if(n==0)
		return false;
}
group world::get_group(int i)
{
	return m[i];
}
 world::world(string arr[]) // Constructor to load everything 
{	
	    root = NULL ; // intialize the root 

		for(int i = 0 ; i< 32 ;i++ )  // loop over 32 team to insert	
		
		{
			if (root == NULL) 
			{ root = new team(arr[i]) ;  // make a team with a name arr[i] 
					
			load_team_players_in_this_node(arr[i],root);   // load players to that team
			
			continue ;	
								}

		team *parent = root ;
		while (1) // inserting the teams  names  by using BST method
	{
					
			if (arr[i] > parent->get_name_team())

				{ if (parent-> right != NULL) // go right if no place empty found 
					 parent =  parent ->right ;
		
				else   // if empty place found
					{   team * place_holder = new team(arr[i]);  // make a team with a name arr[i] 
							
							parent->right = place_holder ; 
							
							load_team_players_in_this_node(arr[i],parent->right); // load players to that team
							
							break ;
													}
			}


		else if (arr[i] < parent->get_name_team())

			{      if (parent ->left != NULL)  // go left if no place empty found 
					 parent =  parent ->left ;
		
				else   // if empty place found
					{  
						team * place_holder2 = new team(arr[i]);   // make a team with a name arr[i]
							parent->left = place_holder2 ;   
			
							load_team_players_in_this_node(arr[i],parent->left); // load players to that team
							
							break ;
													}
	       	}	
	
}
	
}

}



 void world::load_team_players_in_this_node(string team_name ,team * team_ptr) 
  {
        string c,s;
	//c ="Teams/" ;
		c =team_name+".txt"  ;
		ifstream in(c) ;
		// insert players names
		player x[23]   ;
		map <string,player> p;
		
		for (int j=0 ; j<23;j++)
		{
			 in>>s;
			 x[j].set_goals(atoi(s.c_str())) ;
			 getline(in,s);
			 int r = s.length() ;
			 s=s.substr(1,r-1);    // cancelling the effect of jump on the line to the player name 
			x[j].set_name(s); 
		 p[s]= x[j] ;
		}
		team_ptr->set_players(p); // assign the made map to that team by using the pointer to that team
  }
  void world:: find_in_team(string t_n,string p_n)  // searching the BST of World_Cup to get a team then get  a player if match happend
 
  {		if (root==NULL)
			cout<< "No Data loaded  !!!!!" ;
		
		team *n = root ;

		while (1)
		{	
			if (t_n == n-> name)
				{n->search_player(p_n);
					break ;}
			
			else if (t_n  > n->name)
				{ 
					if(n->right != NULL)
						n = n->right ;

					else 
					{cout<< "Sorry , No team Found " ;
							break ;	}
				}
			
			
			else if (t_n  < n->name)
		
				{ 
					if(n->left != NULL)
						n = n->left ;

					else 
					{cout<< "Sorry , No team Found " ;
						break ;	}
				}

		
		} 
  
  }


  

  void world :: view_team (string name) // Viewing the team players after searching for that team
{
  
  if (root==NULL)
			cout<< "No Data loaded  !!!!!" ;
		
		team *n = root ;

		while (1)
		{	
			if (name ==n->name)
			{n->view_players();
					break;}
			
			
			else if (name  > n->name)
				{ 
					if(n->right != NULL)
						n = n->right ;
					else 
						{cout<<"Sorry , No team Found " ;
								break;	}
					
				}
			
			
			else if (name  < n->name)
		
				{ 
					if(n->left != NULL)
						n = n->left ;

					else 
						{cout<<"Sorry , No team Found " ;
							break;	}
					
				}

		
		} 
  
  }
//some methods like is_Empty, insert, delete, Search, ..
