	using namespace std;
#include<iostream>
#include<string.h>
struct Player
{
	char name[30];
	int jno;
	int matches;
	int wickets;
	//default
	Player()
	{
		strcpy(this->name,"no name");
		this->jno=0;
		this->matches=0;
		this->wickets=0;
	}
	
	//parameterized
	Player(char*nm,int j,int m,int w)
	{
		strcpy(this->name,nm);
		this->jno=j;
		this->matches=m;
		this->wickets=w;
	}
	//setters and getters
	
	void setname(char*nm)
	{
		strcpy(this->name,nm);
	}
	void setjno(int j)
	{
		this->jno=j;
	}
	void setmatches(int m)
	{
		this->matches=m;
	}
	void setwickets(int w)
	{
		this->wickets=w;
	}
	char* getname()
	{
		return this->name;
	}
	int getjno()
	{
		return this->jno;
	}
	int getmatches()
	{
		return this->matches;
	}
	int getwickets()
	{
		return this->wickets;
	}
	
	void display(Player* player,int n )
	{
		cout<<"\t__________________________________________________________________________________\n";
		cout<<"\t|\tPlayer name\t     |  jersey no.   | matches  |   wickets            |\n";
		cout<<"\t|____________________|_______________|__________|_________|______________________|\n";
		cout<<"\t|"<<this->name<<"     "<<this->jno<<"    "<<this->matches<<"    "<<this->wickets<<"\n";
		cout<<"\t|____________________|_______________|________________________|____________________|\n";
		
	}
};
void add(Player*,int );
void display(Player*,int );
void remove(Player*,int );
void top3(Player*,int );
void bywickets(Player*,int );
void bymatches(Player*,int );
void search(Player*,int );
void searchbyname(Player*,int );
void searchbyjno(Player*,int );
void update(Player*,int );
void updatematch(Player*,int );
void updatewicket(Player*,int );




int main()
{
	int n;
	cout<<"Enter the storage size :";
	cin>>n;
	Player* player;
	player = new Player[n];
	char exit;
	do
	{
		int s;
		int Choice;
		cout<<"\t________________________________________________________________________________________\n";
		cout<<"\t|       Menu                                                                            |\n";
		cout<<"\t|       which operation you would like to perform                                       |\n";
		cout<<"\t|       1.Display All Player                                                            |\n";
		cout<<"\t|       2.Add palyer                                                                    |\n";
		cout<<"\t|       3.Remove player                                                                 |\n";
		cout<<"\t|       4.top 3 palyers                                                                 |\n";
		cout<<"\t|       5.search player                                                                 |\n";
		cout<<"\t|       6.update player                                                                 |\n";
		cout<<"\t|_______________________________________________________________________________________|\n";   
		
		cin>>Choice;
		if(n==0 && Choice !=1)
		{
			cout<<"\n DATABASE IS EMPTY.\n";
			                                                 
		}
		else
		{
			switch(Choice)
			{
				case(1):
				{
					display(player,n);
				
				}
				break;
			
				case(2):
				{
					add(player,n);
//					n++;
					
				}
			break;
			
					case(3):
				{
					remove(player,n);
					n--;
				
				}
				break;

			
				case(4):
				{
					top3(player,n);
				}
				break;
			
				case(5):
				{
					search(player,n);
				
				}
				break;
				
				case(6):
					{
						update(player,n);
					}
			
				default:
				{
				cout<<"\nInvalid choice<<\n";
				}	
			}
			cout<<"\n\t Do you want to continue(y/n):";
			fflush(stdin);
			cin>>exit;
		}
	}while(exit=='y');
}
	void display(Player* player,int n )
	{
		
		cout<<"\t_________________________________________________________________________\n";
		cout<<"\t|Player name\t        |  jersey no.   | matches  |   wickets           |\n";
		cout<<"\t|_______________________|_______________|__________|_____________________|\n";
		int i;
		for(i=0;i<n;i++)
		{
		cout<<"\t|"<<player[i].getname()<<"\t\t|"<<player[i].getjno() <<"\t        | "<<player[i].getmatches()<<"\t   |"<<player[i].getwickets()<<"\t\t         |\n";
		cout<<"\t|_______________________|_______________|__________|_____________________|\n";
		}
		
	}
	
	void add(Player*player,int n)
	{
	char name[30];
	int jno;	
	int matches;
	int wickets;
	int i;
	for(i=0;i<n;i++)
	{
	cout<<"\nEnter player name:  ";
	fflush(stdin);
	gets(name);
	player[i].setname(name);
	
	cout<<"Enter the jersey no: ";
	cin>>jno;
	player[i].setjno(jno);
	
	cout<<"Enter the total matches: ";
	cin>>matches;
	player[i].setmatches(matches);
	
	cout<<"Enter the total wickets: ";
	cin>>wickets;
	player[i].setwickets(wickets);
	
	}
}
void remove(Player*player,int n)
{

		int i;
		char name[30];
		cout<<"Enter the player name: ";
		fflush(stdin);
		gets(name);
		player[i].setname(name);
	
		
		
		for(i=0;i<n;i++)
		{
			if(strcmp(name,player[i].name)==0)
			{	
				cout<<player[i].name<<" "<<player[i].jno<<" "<<player[i].matches<<" "<<player[i].wickets<<"\n";
				break;
			}
		}
		
		 if(i==n)
        {
		
        	cout<<"player not found<<\n";
        }
        else
        {

		for (i; i<n-1; i++) 
		{
            player[i] = player[i + 1];
        }
		
        	cout<<"Remove successfully<<\n";
        }
        
	}
	
	void top3(Player*player,int n)
{
	Player p[n];
	int i;
	for(i=0;i<n;i++)
	{
		p[i]=player[i];
		//printf("Book Id:%d Book Name:%s Author Name:%s Price:%lf Rating:%d Star\n",b[i].bookid,b[i].bookname,b[i].authorname,b[i].price,b[i].rating);
	}
	int choice;
	cout<<"Top 3 Players 1.By wickets 2.By matches:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			bywickets(p,n);
			break;
		case 2:
			bymatches(p,n);
			break;
	}
	
}
	void bywickets(Player*p,int n)
{
	int i;
	Player temp;
	for(int i=0;i<n-1;n--)
	{
		for(int j=0;j<n-1;j++)
		{
			if(p[j].wickets<p[j+1].wickets)
			{
				Player temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		cout<<p[i].name<<" "<<p[i].jno<<" "<<p[i].wickets<<" "<<p[i].matches<<"\n";
	}
}
void bymatches(Player*p,int n)
{
	int i;
	Player temp;
	for(int i=0;i<n-1;n--)
	{
		for(int j=0;j<n-1;j++)
		{
			if(p[j].matches<p[j+1].matches)
			{
				Player temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		} 
	}
	for(i=0;i<3;i++)
	{
		cout<< p[i].name<<" "<< p[i].jno<<" "<<p[i].wickets<<" "<<p[i].matches<<"\n";
	}
}
void search(Player*player,int n)
{
	int choice;
	cout<<"Do you: 1.Search By name 2.Search by jersey no: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			
			   searchbyname(player,n);
			   break;
	    case 2:
	    	   searchbyjno(player,n);
	    	   break;
	    default:
	    		cout<<"Invalid choice\n";
	}
	
}

void searchbyname(Player*player,int n)
{
	char name[30];
	int i;
	cout<<"Enter the Player Name For Search: ";
	cin>>name;
	for(i=0;i<n;i++)
	{
				if(strcasecmp(name,player[i].name)==0)

	
		{
				cout<<"player name:"<<player[i].name<<" jersey no:"<<player[i].jno<<" total matches: "<<player[i].matches<<" total wickets"<<player[i].wickets<<"\n";
				break;
		}
		else
		{
			cout<<"not found.";	
		}
	}
	
}
void searchbyjno(Player*player,int n)
{
	int jno;
	fflush(stdin);
	cout<<"Enter the Jersey Nuumber For Search: ";
	cin>>jno;
	int i;
	for(i=0;i<n;i++)
	{
		if(jno==player[i].jno)
	
		{
			cout<<" player name:"<<player[i].name<<"jersey no:"<<player[i].jno<<"total matches:"<<player[i].matches<<" total wickets:"<<player[i].wickets<<" "<<"\n";
			break;
		}
	
	else
	{
	
	cout<<"\n Player not found.";
	}
}
}
void update(Player*player,int n)
{
	int choice;
	cout<<"Do you: 1.Update matches 2.Update wickets: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				updatematch(player,n);
			    break;
			}
			  
	    case 2:
	    	{
	    		updatewicket(player,n);
	    	    break;
			}
	   		  
	    default:
	    	{
	    		cout<<"Invalid choice<<\n";
			}
	    	
	}
	
}
void updatematch(Player*player,int n)
{
	int choice;
	cout<<"Data Find for update 1 Search by Jersey Number 2 Search by Name:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
			
				int no,i;
				cout<<"Enter the Jersey No For Search: ";
				cin>>no;
				for(i=0;i<n;i++)
				{
					if(no==player[i].jno)
					{
						cout<<" player name:"<<player[i].name<<" jersey number: "<<player[i].jno<<"total matches: "<<player[i].matches<<" total wickets:"<<player[i].wickets<<"\n";
						break;
					}
				}
				int match;
				cout<<"Enter the New No Of Matches: ";
				cin>>match;
				player[i].matches=match;
				cout<<" player name:"<<player[i].name<<" jersey no:"<<player[i].jno<<" total mathces"<<player[i].matches<<" total wickets "<<player[i].wickets<<"\n";
				
			}break;
		case 2: 
			{
				char name[30];
				fflush(stdin);
				cout<<"Enter the Player Name For Search: ";
				gets(name);
				int i;
				for(i=0;i<n;i++)
				{
	
					if(strcasecmp(name,player[i].name)==0)
					{
						cout<<" player name:"<<player[i].name<<"jersey number:"<<player[i].jno<<" total matches: "<<player[i].matches<<"total wickets:"<<player[i].wickets<<"\n";
						break;
					}
				}
				int match;
				cout<<"Enter the New No Of Mathches: ";
				cin>>match;
				player[i].matches=match;
				cout<<" player name:"<<player[i].name<<" jersey number:"<<player[i].jno<<" total matches: "<<player[i].matches<<" total wickets:"<<player[i].wickets<<"\n";
	    	}break;

	    default:
	    	cout<<"Invalid choice\n";
	}
}
void updatewicket(Player*player,int n)
{
	int choice;
	cout<<"Data Find for update 1 Search by Jersey No 2 Search by Name:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				int no,i;
				cout<<"Enter the Jersey No For Search: ";
				cin>>no;
				for(i=0;i<n;i++)
				{
					if(no==player[i].jno)
					{
						cout<<" player name:"<<player[i].name<<"jersey number:"<<player[i].jno<<" total matches: "<<player[i].matches<<"total wickets:"<<player[i].wickets<<"\n";
						break;
					}
				}
			
				int wicket;
				cout<<"Enter the New No Of Wickets: ";
				cin>>wicket;
				player[i].wickets=wicket;
				cout<<" player name:"<<player[i].name<<"jersey number:"<<player[i].jno<<" total matches: "<<player[i].matches<<"total wickets:"<<player[i].wickets<<"\n";	
			}break;
		case 2: 
			{	
				char nm[20];
				fflush(stdin);
				cout<<"Enter the Player Name For Search: ";
				gets(nm);
				int i;
				for(i=0;i<n;i++)
				{
	
					if(strcasecmp(nm,player[i].name)==0)
					{
						cout<<" player name:"<<player[i].name<<"jersey number:"<<player[i].jno<<" total matches: "<<player[i].matches<<"total wickets:"<<player[i].wickets<<"\n";

						break;
					}
				}
				int wicket;
				cout<<"Enter the New NOo Of Wickets: ";
				cin>>wicket;
				player[i].wickets=wicket;
				cout<<" player name:"<<player[i].name<<"jersey number:"<<player[i].jno<<" total matches: "<<player[i].matches<<"total wickets:"<<player[i].wickets<<"\n";   
	    	} break;	
	}
}
