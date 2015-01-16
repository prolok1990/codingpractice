#include <iostream>
using namespace std;

class npuzzle
{
	int **initial_state;// stores intial state in matrix form
	int **current_state;// stores current state in matrix form
	int current_blank[2]; // current position of the blank column
	int **goal_state;// stores the location of each blocks, goal_state[0][i] => row of the number i in goal, goal_state[1][i]=> column of number i in goal
	int **goal_state_matrix;
	int nval; // stores the value of N

public:
	npuzzle(int); // constructor initializes all values to 0
	~npuzzle(); // destroys all the allocated memory


	bool valid(int **);  // check if a state is valid or not
	bool build_goal_state(int **); // build the object if the goal is valid,returns true if success
	bool build_initial_state(int **);// build the object if initial state is valid and assign current state to initial state, returns true if success

	bool move(int);// moves a block to the empty block, 1 -> moves from top ,2-> from bottom , 3-> from left , 4-> from right, returns true if success
	int maxswaphrts();// N-max swap heuristics
	int manhattan_distance();
	int tiles_out_of_pos();

	void display_goal_state(int); // display the goal, if argument =1 then in location form, argument =2, then in matrix form
	void display_initial_state(); // display the initial state
	void display_current_state();// display current state

	bool goal_test(); // returns true if the current state is goal
	bool goal_test(int**); // check if the argument is goal or not

	
};

npuzzle::npuzzle(int n)
{
	int i,j;
	nval=n;
	goal_state=new int*[2];
	initial_state=new int*[nval];
	current_state=new int*[nval];
	goal_state_matrix=new int*[nval];
	current_blank[0]=0;
	current_blank[1]=0;
	goal_state[0]=new int[nval*nval];
	goal_state[1]=new int[nval*nval];
	for (i=0;i<nval*nval;i++)
	{
		goal_state[0][i]=0;
		goal_state[1][i]=0;
	}
	for (i=0;i<nval;i++)
	{
		initial_state[i]=new int[nval];
		current_state[i]=new int[nval];
		goal_state_matrix[i]=new int[nval];
	}
	for (i=0;i<nval;i++)
	{
		for(j=0;j<nval;j++)
		{
			initial_state[i][j]=0;
			current_state[i][j]=0;
			goal_state_matrix[i][j]=0;
		}
	}
	
}

npuzzle::~npuzzle()
{
	int i;
	delete goal_state[0];

	delete goal_state[1];	
	for(i=0;i<nval;i++)
	{
		delete initial_state[i];
		delete current_state[i];
		delete goal_state_matrix[i];
	}
	delete goal_state;
	delete initial_state;
	delete current_state;
	delete goal_state_matrix;
}

bool npuzzle::valid(int** rslt) //returns true if the state is valid
{	
	int i,j;
	bool* check=new bool[nval*nval]; // map to validate the goal_state input
	for(i=0;i<nval*nval;i++)
	{
		check[i]=false; //initializing
	}

	for (i=0;i<nval;i++)
	{
		for(j=0;j<nval;j++)
		{
			if (rslt[i][j]<0 || rslt[i][j]>=nval*nval)
			{
				return false;
			}
			else
			{

				if (check[rslt[i][j]]==false) //checking if number is already present
				{
					check[rslt[i][j]]=true;
				}
				else
				{
					return false; //return false if the number is already present
				}
			}

		}
	}
	for(i=0;i<nval*nval;i++)
	{
		if (check[i]== false)
		{
			return false;// return false if some number from 0 to n*n-1 is absent
		}
	}
	delete check;

	
	return true;

}
bool npuzzle::build_initial_state(int** initial) // returns true if success
{
	int i,j;
	if (this->valid(initial)==true)
	{


		for (i=0;i<nval;i++)
		{
			for(j=0;j<nval;j++)
			{
				initial_state[i][j]=initial[i][j];
				current_state[i][j]=initial_state[i][j];
				if (current_state[i][j] == 0)
				{
					current_blank[0]=i;
					current_blank[1]=j;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}

}
void npuzzle::display_initial_state()
{
	int i,j;
	for (i=0;i<nval;i++)
	{
		for(j=0;j<nval;j++)
		{
			cout<<initial_state[i][j]<<" ";
		}
		cout<<endl;
		
	}
	cout<<endl;
}
void npuzzle::display_current_state()
{
	int i,j;
	for (i=0;i<nval;i++)
	{
		for(j=0;j<nval;j++)
		{
			cout<<current_state[i][j]<<" ";
		}
		cout<<endl;
		
	}
	cout<<endl;
}

bool npuzzle::build_goal_state(int** goal)
{
	int i,j;
	if (this->valid(goal)==true)
	{


		for (i=0;i<nval;i++)
		{
			for(j=0;j<nval;j++)
			{
				goal_state[0][goal[i][j]]=i;
				goal_state[1][goal[i][j]]=j;
				goal_state_matrix[i][j]=goal[i][j];
			}
		}

		return true;
	}
	else
	{
		return false;
	}

}
void npuzzle::display_goal_state(int n)
{
	if (n==1)
	{
		for (int i=0;i<nval*nval;i++)
		{
			cout<<i<<":"<<goal_state[0][i]<<" "<<goal_state[1][i]<<endl;
			
		}
	}
	if (n==2)
	{
		for (int i=0;i<nval;i++)
		{
			for(int j=0;j<nval;j++)
			{
				cout<<goal_state_matrix[i][j]<<" ";
			}
		cout<<endl;
		}
	}
	cout<<endl;
}

bool npuzzle::move(int mov)
{
	int temp,row,col;
	row=current_blank[0];
	col=current_blank[1];
	if (this->valid(current_state) == false)
	{
		return false;
	}

	switch(mov)
	{
		case 1:     		 //move from up to blank

			if (row==0) // if blank is at the topmost row
			{
				return false;
			}
			else
			{
				temp=current_state[row-1][col];
				current_state[row-1][col]=current_state[row][col];
				current_state[row][col]=temp;
				current_blank[0]=row-1;
				
			}




			break;

		case 2:				// move from down to blank	

			if (row==nval-1) // if the blank is at the bottom most row
			{
				return false;
			}
			else
			{
				temp=current_state[row+1][col];
				current_state[row+1][col]=current_state[row][col];
				current_state[row][col]=temp;
				current_blank[0]=row+1;
				

			}

			break;

		case 3:				// move from left to blank
			if (col==0) // if blank is at the left most col
			{
				return false;
			}
			else
			{
				temp=current_state[row][col-1];
				current_state[row][col-1]=current_state[row][col];
				current_state[row][col]=temp;
				current_blank[1]=col-1;
			}

			break;

		case 4:				// move from right to blank
			if (col==nval-1) // if blank is at the right most col
			{
				return false;
			}
			else
			{
				temp=current_state[row][col+1];
				current_state[row][col+1]=current_state[row][col];
				current_state[row][col]=temp;
				current_blank[1]=col+1;
			}

			break;

		default:
			return false;

	
	}
	return true;
}

bool npuzzle::goal_test()  // returns true if the current state is goal
{
	int i,j,val;
	for (i=0;i<nval;i++)
	{
		for (j=0;j<nval;j++)
		{
			val=current_state[i][j];
			if (goal_state[0][val]!= i || goal_state[1][val]!= j)
			{
				return false;
			}


		}
	}
	return true;
}

bool npuzzle::goal_test(int** test)  // returns true if the argument is goal or not
{
	int i,j,val;
	if (this->valid(test)==false)
	{
		return false;
	}
	for (i=0;i<nval;i++)
	{
		for (j=0;j<nval;j++)
		{
			val=test[i][j];
			if (goal_state[0][val]!= i || goal_state[1][val]!= j)
			{
				return false;
			}


		}
	}
	return true;
}


int npuzzle::maxswaphrts()
{
	int row,col,i,j,count =1,val;
	int rowgoal,colgoal;
	
	rowgoal=goal_state[0][0];
	colgoal=goal_state[1][0];

	int **current_loc=new int*[2];
	current_loc[0]=new int[nval*nval];
	current_loc[1]=new int[nval*nval];
	
	
	for (i=0;i<nval;i++)
	{
		for(j=0;j<nval;j++)
		{
			
			current_loc[0][current_state[i][j]]=i;
			current_loc[1][current_state[i][j]]=j;

		}
	}
		
	while ((current_loc[0][0]!=rowgoal) || (current_loc[1][0]!=colgoal))
	{
		val=goal_state_matrix[current_loc[0][0]][current_loc[1][0]];
		row=current_loc[0][val];
		col=current_loc[1][val];
		current_loc[0][val]=current_loc[0][0];
		current_loc[1][val]=current_loc[1][0];
		current_loc[0][0]=row;
		current_loc[1][0]=col;
		count++;
	}


	delete current_loc[0];
	delete current_loc[1];
	delete current_loc;
	return count;
	


}
int npuzzle::manhattan_distance()
{
	int man_dist = 0;
	for(int i = 0; i < nval; i++)
	{
		for(int j = 0; j < nval; j++)
		{
			if(current_state[i][j] != 0)
			{
				if(i > goal_state[0][current_state[i][j]])
					man_dist += i - goal_state[0][current_state[i][j]];
				else
					man_dist += goal_state[0][current_state[i][j]] - i;
				if(j > goal_state[1][current_state[i][j]])
					man_dist += j - goal_state[1][current_state[i][j]];
				else
					man_dist += goal_state[1][current_state[i][j]] - j;			
			}
		}
	}
	return man_dist;
}

int npuzzle::tiles_out_of_pos()
{
	int count = 0;
	for(int i = 0; i < nval; i++)
	{
		for(int j = 0; j < nval; j++)
		{
			if(current_state[i][j] != 0)
			{
				if(i != goal_state[0][current_state[i][j]])
					count++;
				if(j != goal_state[1][current_state[i][j]])
					count++;
			}
		}
	}
	return count;	
}


int main()
{
	int n,val,j,i;
	int **rslt; 
	/*cout<<"Enter the size of n:";
	cin>>n;*/
	n=3;
	rslt=new int*[n];
	for(i=0;i<n;i++)
	{
		rslt[i]=new int[n];
	}
	/*cout <<"Enter the goal_state matrix(0 for blank):";
	for (i=0;i<n;i++)
	{
		cout<<"Enter the "<<n<<" elements of "<<i+1<<"th :";
		for (j=0;j<n;j++)
		{
			cin>>val;
			rslt[i][j]=val;
		}


	}*/
	npuzzle puzzle(n);
	rslt[0][0]=1;
	rslt[0][1]=2;
	rslt[0][2]=3;

	rslt[1][0]=4;
	rslt[1][1]=5;
	rslt[1][2]=6;

	rslt[2][0]=7;
	rslt[2][1]=8;
	rslt[2][2]=0;




	

	puzzle.build_goal_state(rslt);
	/*cout <<"Enter the current matrix(0 for blank):";
	for (i=0;i<n;i++)
	{
		cout<<"Enter the "<<n<<" elements of "<<i+1<<"th :";
		for (j=0;j<n;j++)
		{
			cin>>val;
			rslt[i][j]=val;
		}


	}*/
	rslt[0][0]=2;
	rslt[0][1]=0;
	rslt[0][2]=6;

	rslt[1][0]=1;
	rslt[1][1]=3;
	rslt[1][2]=4;

	rslt[2][0]=7;
	rslt[2][1]=5;
	rslt[2][2]=8;

	

	puzzle.build_initial_state(rslt);
	cout<<"goal state 1"<<endl;
	puzzle.display_goal_state(1);
	cout<<"goal state 2"<<endl;
	puzzle.display_goal_state(2);
	cout<<"initial state "<<endl;
	puzzle.display_initial_state();
	cout<<"current state"<<endl;
	puzzle.display_current_state();
	
	
	cout<<endl<<puzzle.maxswaphrts()<<endl;
	return 0;

}


