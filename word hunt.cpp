# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <windows.h> 
# include <algorithm>
using namespace std;

class Word_hunt
{
	private:
		
		int count = 0;
		int random_col[6];
		int random_row[6];
		int len;
		int row = 0;
		int col = 0;
		char grid[20][30];
		bool occupied[20][30];
		string check_array[10];
		string words[35] = 
		{
   		"APPLE", "BANANA", "CHOCOLATE", "ELEPHANT", "GUITAR", "OCEAN", "MOUNTAIN", "SUNSHINE",
	    "LAPTOP", "KEYBOARD", "NOTEBOOK", "WINDOW", "UMBRELLA", "JOURNEY", "BUTTERFLY", "DIAMOND",
	    "WHISPER", "GALAXY", "PENCIL", "LIBRARY", "SUNSET", "HAPPINESS", "VOLCANO", "TREASURE",
	    "ADVENTURE", "RAINBOW", "MARATHON", "MIRROR", "PUZZLE", "ISLAND", "FRIENDSHIP",
	    "WATERFALL", "MOONLIGHT", "PARADISE", "STORM"
		};
		char Alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};                    
	public:
		Word_hunt()
		{
			srand(time(0));
			for(int i = 0; i < 20; i++)
			{
				for(int j = 0; j < 30; j++)
				{
					occupied[i][j] = false;
				}
			}
		}
		//To Set color
		void setColor(int color)
		{
		   	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		    SetConsoleTextAttribute(hConsole, color);
		}

		//To set timer
	    void timer() 
		{
	        int seconds = 60;
	        setColor(2);
	        cout << endl;
	        for (int i = seconds; i >= 0; --i) 
			{
	            cout << "\t\t\t\t\tTime remaining: 00:00:" << i << " seconds\r" << flush;
	            Sleep(1000);  
	        }
			cout << "\n\n\n";
	        setColor(15);
	    }
	    //to assign random place
	    void assign_random_no(int arr[], int size, int no_of_rows)
		{
		 	for(int i = 0; i < size; i++)
		 	{
		 		int random = (rand() % no_of_rows);
		 		arr[i] = random;
			}
		 	
		}
		//to sort an array
		void sortArray(int arr[], int size) 
		{
		    sort(arr, arr + size);
		}
		void fill_words(int no_of_words, int no_of_rows, int no_of_cols)
		{
			int ioi = 0;  
			for(int j = 0; j < no_of_words; j++)
			{
					string random_word;
					bool duplicate = false;
					
					do {
						int random = (rand() % 35);
						random_word = words[random];
						duplicate = false;
						
						for(int i = 0; i < ioi; i++)
						{
							if(random_word == check_array[i])
							{
								duplicate = true;
								break;
							}
						}
					}while(duplicate); 
					
					check_array[ioi++] = random_word;
					len = random_word.length();
					bool empty = false;
					do
					{
						int rows = rand() % no_of_rows;
            			int cols = rand() % (no_of_cols - len);
            			empty = true;
					    // Check if the space is empty
			            for(int i = 0; i < len; i++)
			            {
			                if(occupied[rows][cols + i]) 
							{
			                    empty = false;
			                    break;
			                }
			            }
			            if(empty)
			            {
			            	for(int i = 0; i < len; i++)
							{
								grid[rows][cols + i] = random_word[i];
								occupied[rows][cols + i] = true;
							}
						}
					}while(!empty);
			}
		}

		void fill_grid(int no_of_rows, int no_of_cols, int no_of_words)
		{
			fill_words(no_of_words, no_of_rows, no_of_cols);
			for(int i = 0; i < no_of_rows; i++)
			{
				for(int j = 0; j < no_of_cols; j++)
				{
					if(!occupied[i][j])
					{
						int r = (rand() % 26);
						grid[i][j] = Alphabets[r]; 
					}
				}
			}
		}	
	    //to display the board
		void display_board(int no_of_rows, int no_of_cols, int no_of_words, int no_of_lines)
		{
			fill_grid(no_of_rows, no_of_cols, no_of_words);
			cout << " \t\t\t " ;
			for(int i = 0; i < no_of_lines; i++)
			{
				cout << "-";
			}
			cout << endl;
			for(int i = 0; i < no_of_rows; i++)
			{
				cout << "\t\t\t |  ";
				for(int j = 0; j < no_of_cols; j++)
				{
					cout << grid[i][j] << " ";
				}
				cout << " | " << endl;
			}
			cout << " \t\t\t " ;
			for(int i = 0; i < no_of_lines; i++)
			{
				cout << "-";
			}
			cout << endl;	
		}
		//to display the board coloured
		void display_board_end(int no_of_rows, int no_of_cols, int no_of_lines)
		{
			cout << " \t\t\t " ;
			for(int i = 0; i < no_of_lines; i++)
			{
				cout << "-";
			}
			cout << endl;
			for(int i = 0; i < no_of_rows; i++)
			{
				cout << "\t\t\t |  ";
				for(int j = 0; j < no_of_cols; j++)
				{
					if(occupied[i][j])
					{
						setColor(2);
						cout << grid[i][j] << " ";
						setColor(15);
						continue;	
					}
					cout << grid[i][j] << " ";
				}
				cout << " | " << endl;
			}
			cout << " \t\t\t ";
			for(int i = 0; i < no_of_lines; i++)
			{
				cout << "-";
			}
			cout << endl;
		}
		void check_word(int &count, int trys)
		{
		    string ans;
		    count = 0;
		    while (trys > 0) // Loop until timer expires
		    {
		        cout << "\nEnter a word: ";
		        cin >> ans;
				transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
		        bool correct = false;
		        for (int i = 0; i < 35; i++)
		        {
		            if (ans == words[i])
		            {
		                cout << "Correct!" << endl;
		                count++;
		                correct = true;
		                break;
		            }
		        }
		        if (!correct)
		        {
		            cout << "\aIncorrect!" << endl;
		            trys--;
		        }
		        if(count == trys)
		        {
		        	return;
				}

		    }
		
		}
		void display_winner(int count, int no) 
		{
		    cout << "========================================== \n";
		    
		    if (count >= no) 
			{
		        cout << "\a"; // Beep sound
		        Sleep(500);   // Small delay for effect
		        cout << "Y   O   U      W   I   N   ! \n";
		    } 
			else 
			{
		        cout << "\a"; // Beep sound
		        Sleep(500);
		        cout << "Y   O   U      L   O   S   E   ! \n";
		    }
		    
		    cout << "==========================================\n";
		}
	
};


 
int main()
{
	Word_hunt w;
	int choice;
	int count = 0;
	w.setColor(15);
	cout << "\n\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << "\t\t\t\t W   W  OOO  RRRR   DDDD      H   H  U   U  N   N  TTTTT" << endl;
    cout << "\t\t\t\t W   W O   O R   R  D   D     H   H  U   U  NN  N    T  " << endl;
    cout << "\t\t\t\t W W W O   O RRRR   D   D     HHHHH  U   U  N N N    T  " << endl;
    cout << "\t\t\t\t W W W O   O R  R   D   D     H   H  U   U  N  NN    T  " << endl;
    cout << "\t\t\t\t  W W   OOO  R   R  DDDD      H   H  UUUUU  N   N    T  " << endl;
    cout << "\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    cout << endl;
    cout << endl;
	while(true)
	{
		cout << endl;
    	cout<< "--------------------------------------\n"
            << "|          Choose a Level            |\n"
            << "--------------------------------------\n"
            << "|  1. Easy                           |\n"
            << "|  2. Medium                         |\n"
            << "|  3. Hard                           |\n"
            << "|  4. Exit                           |\n"
            << "--------------------------------------\n"
            << "Enter your choice: ";
            cin>>choice;	
            
            switch(choice)
            {
            	case 1:
            		{
            			w.display_board(10, 15, 2, 35);
						w.timer();
//						cout << "You Have 2 Life: " << endl;
//						w.check_word(count, 2);
//						w.display_winner(count, 1);
						w.display_board_end(10, 15, 35);
            			break;	
					}
				case 2:
            		{
            			w.display_board(15, 20, 4, 45);
						w.timer();
//						cout << "You Have 5 Life: " << endl;
//						w.check_word(count, 5);
//						w.display_winner(count, 3);
						w.display_board_end(15, 20, 45);
            			break;	
					}
				case 3:
            		{
            			w.display_board(20, 30, 6, 65);
						w.timer();
//						cout << "You Have 8 Life: " << endl;
//						w.check_word(count, 8);
//						w.display_winner(count, 5);
						w.display_board_end(20, 30, 65);
            			break;	
					}
				case 4:
            		{
            			cout << "\t==============================================" << endl;
				        cout << "\t                    Exiting!                  " << endl;
				        cout << "\t==============================================" << endl;
				        return 0;
					}
			}
	}
}

