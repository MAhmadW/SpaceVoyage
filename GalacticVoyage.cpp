/*
WRITTEN AND DEVELOPED BY:

MUHAMMAD AHMAD WASEEM [24100090]

QASIM JAVED [24100281]

GROUP 48
CS PROJECT, CS-100 S3 

DATED:
14-12-2020
*/

#include <iostream>  //for input output
#include <Windows.h> //for CLS
#include <stdlib.h>  //for coloured output
#include <conio.h>  //to take input from keyboard
#include <ctime>    // to get the current time in seconds for randomisation
#include <chrono>  //to get the current time in milliseconds for randomisation of real-time processes 


using namespace std::chrono ; //for getting the current time in milliseconds for true randomisation
using namespace std ;


const int H = 20 ;//height of playing screen
const int W = 60 ;//width of playing screen

//The following values correspond to indexes. They are declared here and as global constants for ease of understanding and implementation 

const int FR = 0 ;//first row
const int FPR = 1 ;//first playing screen row
const int FC = 0 ;//first column
const int FPC = 1 ;//first playing screen column
const int LR = H - 1 ;//last row
const int LPR = H - 2 ;//last playing screen row
const int LC = W - 1 ;//last column
const int LPC = W - 2 ;//last playing screen column

const int ENTER = 13 ;
const int KEY_DOWN = 80 ;
const int KEY_UP = 72 ;
const int SPACEBAR = 32 ;
const int ESCAPE = 27 ;

/*
Generates the boundaries and inner region(spaces) of the playing screen.
@param screen[][W] represents the array of playing screen
no return value
*/
void initialiseScreen(char screen[][W])
{
    for (int i = FR ; i <= LR ; i++)    // Iterate through the rows
    {
        for (int j = FC ; j <= LC ; j++ )// Iterate through the columns
        {
            screen[i][j] = ' ' ;        // Make the space character the contents of each element
        }
    }
    for (int i = FR ; i <= LR ; i++)    // Iterate through the rows
    {
        for (int j = FC ; j <= LC ; j++ )// Iterate through the columns
        {
            if((i == FR || i == LR)||(j == FC || j == LC)) //Check criteria if either the row is a boundary row or column is a boundary column 
            {
                screen[i][j] = '#' ; //Assignment of the hashtag character to the element. This way all elements on the edge are set to #
            }
        }
    }
}


/*
Prints the instructions screen for the player's help
no parameter values
no return value
*/
void displayHelp() 
{
    system("cls") ;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x03); // This is how the following text's colour is set. Sets text colour to aqua
    cout <<"Here is some information for the game :\n" << endl ;
    cout <<"1. Use the \"UP\" key to move up and the \"DOWN\" key to move down.\n" << endl ;
    cout <<"2. Use \"spacebar\" to fire the plasma cannon.\n" << endl ;
    cout <<"3. \"+\" denotes the unbreakable walls and \"0\" denotes the asteroid.\n" << endl ;
    cout <<"4. You have three hearts in total. \"Head-on collision\" OR \"Side-on collision\" with either walls will cost you one heart. \n" << endl ;
    cout <<"5. You will receive \"1000\" points if you destroy one asteroid.\n" << endl ;
    cout <<"6. Choose your difficulty wisely. Enjoy playing! :)\n" << endl ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07); // Resets text colour

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F); // Sets text colour to brilliant white
    cout << "Press any key to return to main menu . . . " ; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07); // Resets text colour 

    getch();
}


/*
Displays the interactive difficulty menu where the difficulty level can be chosen and set.
@param difficulty it is a reference parameter for the variable denoting the difficulty level of the game
returns no value
*/
void displayDifficultyMenu(int& difficulty)
{
    
    int keyhit = 0 ;
    difficulty = 1 ;

    while(1)
    {
        system("cls") ;
        switch(difficulty)
        {
            // inversion of order is due to order of numbering being diff from order
            case 1 : 
            {
                // ASCII art like this is output as raw string to forgo escape sequences
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0A ) ; cout << R"( 
 _______  _______  _______  __   __ 
|       ||   _   ||       ||  | |  |
|    ___||  |_|  ||  _____||  |_|  |
|   |___ |       || |_____ |       |
|    ___||       ||_____  ||_     _|
|   |___ |   _   | _____| |  |   |  
|_______||__| |__||_______|  |___|  
)" << endl ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07) ;
                cout << R"(
.___  ___.  _______  _______   __   __    __  .___  ___. 
|   \/   | |   ____||       \ |  | |  |  |  | |   \/   | 
|  \  /  | |  |__   |  .--.  ||  | |  |  |  | |  \  /  | 
|  |\/|  | |   __|  |  |  |  ||  | |  |  |  | |  |\/|  | 
|  |  |  | |  |____ |  '--'  ||  | |  `--'  | |  |  |  | 
|__|  |__| |_______||_______/ |__|  \______/  |__|  |__| 
                                                         
)" << endl ;
                cout << R"(
 ___   ___      ________       ______        ______      
/__/\ /__/\    /_______/\     /_____/\      /_____/\     
\::\ \\  \ \   \::: _  \ \    \:::_ \ \     \:::_ \ \    
 \::\/_\ .\ \   \::(_)  \ \    \:(_) ) )_    \:\ \ \ \   
  \:: ___::\ \   \:: __  \ \    \: __ `\ \    \:\ \ \ \  
   \: \ \\::\ \   \:.\ \  \ \    \ \ `\ \ \    \:\/.:| | 
    \__\/ \::\/    \__\/\__\/     \_\/ \_\/     \____/_/ 
                                                         
)" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            cout << "Navigate using the up and down arrow keys. Press the enter key to select a difficulty . . . " ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);

            }
            break ;
            case 2 : 
            {
                cout << R"(
 _______  _______  _______  __   __ 
|       ||   _   ||       ||  | |  |
|    ___||  |_|  ||  _____||  |_|  |
|   |___ |       || |_____ |       |
|    ___||       ||_____  ||_     _|
|   |___ |   _   | _____| |  |   |  
|_______||__| |__||_______|  |___|  
)" << endl ;
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x06 ) ; cout << R"(
.___  ___.  _______  _______   __   __    __  .___  ___. 
|   \/   | |   ____||       \ |  | |  |  |  | |   \/   | 
|  \  /  | |  |__   |  .--.  ||  | |  |  |  | |  \  /  | 
|  |\/|  | |   __|  |  |  |  ||  | |  |  |  | |  |\/|  | 
|  |  |  | |  |____ |  '--'  ||  | |  `--'  | |  |  |  | 
|__|  |__| |_______||_______/ |__|  \______/  |__|  |__| 
                                                         
)" << endl ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07) ;
                cout << R"(
 ___   ___      ________       ______        ______      
/__/\ /__/\    /_______/\     /_____/\      /_____/\     
\::\ \\  \ \   \::: _  \ \    \:::_ \ \     \:::_ \ \    
 \::\/_\ .\ \   \::(_)  \ \    \:(_) ) )_    \:\ \ \ \   
  \:: ___::\ \   \:: __  \ \    \: __ `\ \    \:\ \ \ \  
   \: \ \\::\ \   \:.\ \  \ \    \ \ `\ \ \    \:\/.:| | 
    \__\/ \::\/    \__\/\__\/     \_\/ \_\/     \____/_/ 
                                                         
)" <<endl ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            cout << "Navigate using the up and down arrow keys. Press the enter key to select a difficulty . . . " ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
            break ;
            case 3 : 
            {
                cout << R"(
 _______  _______  _______  __   __ 
|       ||   _   ||       ||  | |  |
|    ___||  |_|  ||  _____||  |_|  |
|   |___ |       || |_____ |       |
|    ___||       ||_____  ||_     _|
|   |___ |   _   | _____| |  |   |  
|_______||__| |__||_______|  |___|  
)" << endl ;
                cout << R"(
.___  ___.  _______  _______   __   __    __  .___  ___. 
|   \/   | |   ____||       \ |  | |  |  |  | |   \/   | 
|  \  /  | |  |__   |  .--.  ||  | |  |  |  | |  \  /  | 
|  |\/|  | |   __|  |  |  |  ||  | |  |  |  | |  |\/|  | 
|  |  |  | |  |____ |  '--'  ||  | |  `--'  | |  |  |  | 
|__|  |__| |_______||_______/ |__|  \______/  |__|  |__| 
                                                         
)" << endl ;
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x04 ) ; cout << R"(
 ___   ___      ________       ______        ______      
/__/\ /__/\    /_______/\     /_____/\      /_____/\     
\::\ \\  \ \   \::: _  \ \    \:::_ \ \     \:::_ \ \    
 \::\/_\ .\ \   \::(_)  \ \    \:(_) ) )_    \:\ \ \ \   
  \:: ___::\ \   \:: __  \ \    \: __ `\ \    \:\ \ \ \  
   \: \ \\::\ \   \:.\ \  \ \    \ \ `\ \ \    \:\/.:| | 
    \__\/ \::\/    \__\/\__\/     \_\/ \_\/     \____/_/ 
                                                         
)" << endl ;SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07) ;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            cout << "Navigate using the up and down arrow keys. Press the enter key to select a difficulty . . . " ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
            break ;                
        }

        keyhit = getch() ;

        if ((keyhit == KEY_DOWN) && (difficulty < 3) )
        {
            difficulty++ ;
        }
        if ((keyhit == KEY_UP) && (difficulty > 1) )
        {   
            difficulty-- ;
        }
        if (keyhit == ENTER)
        {
            return ;
        }
    }
}


/*
Prints the title screen with the game's name
no parameter values
no return value
*/
void displayTitle()
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x05 ); 
    cout << R"(
 _______  _______  _        _______  _______ __________________ _______             _______           _______  _______  _______ 
(  ____ \(  ___  )( \      (  ___  )(  ____ \\__   __/\__   __/(  ____ \  |\     /|(  ___  )|\     /|(  ___  )(  ____ \(  ____ \
| (    \/| (   ) || (      | (   ) || (    \/   ) (      ) (   | (    \/  | )   ( || (   ) |( \   / )| (   ) || (    \/| (    \/
| |      | (___) || |      | (___) || |         | |      | |   | |        | |   | || |   | | \ (_) / | (___) || |      | (__    
| | ____ |  ___  || |      |  ___  || |         | |      | |   | |        ( (   ) )| |   | |  \   /  |  ___  || | ____ |  __)   
| | \_  )| (   ) || |      | (   ) || |         | |      | |   | |         \ \_/ / | |   | |   ) (   | (   ) || | \_  )| (      
| (___) || )   ( || (____/\| )   ( || (____/\   | |   ___) (___| (____/\    \   /  | (___) |   | |   | )   ( || (___) || (____/\
(_______)|/     \|(_______/|/     \|(_______/   )_(   \_______/(_______/     \_/   (_______)   \_/   |/     \|(_______)(_______/
                                                                                                                                
)" ;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0F ) ;
    cout << "Press any key to continue to the main menu... " ;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 ) ;
    getch() ;
}


/*
Displays the menu of game.
@param difficulty represents the difficulty level chosen by the player
no return value
*/
void displayMenu(int& difficulty)
{
    int keyhit = 0 ;
    int choice = 1 ;

    while(1)
    {
        system("cls") ;
        switch(choice)
        {
            // inversion of order is due to order of numbering being diff from order
            case 1 : 
            {
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x01 ) ; cout << R"(
   _____   _                    _        _____                            
  / ____| | |                  | |      / ____|                           
 | (___   | |_    __ _   _ __  | |_    | |  __    __ _   _ __ ___     ___ 
  \___ \  | __|  / _` | | '__| | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
  ____) | | |_  | (_| | | |    | |_    | |__| | | (_| | | | | | | | |  __/
 |_____/   \__|  \__,_| |_|     \__|    \_____|  \__,_| |_| |_| |_|  \___|
                                                                          
                                                                          
)" << endl ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07) ;
                cout << R"(
   _____   _                                      _____    _    __    __   _                  _   _           
  / ____| | |                                    |  __ \  (_)  / _|  / _| (_)                | | | |          
 | |      | |__     ___     ___    ___    ___    | |  | |  _  | |_  | |_   _    ___   _   _  | | | |_   _   _ 
 | |      | '_ \   / _ \   / _ \  / __|  / _ \   | |  | | | | |  _| |  _| | |  / __| | | | | | | | __| | | | |
 | |____  | | | | | (_) | | (_) | \__ \ |  __/   | |__| | | | | |   | |   | | | (__  | |_| | | | | |_  | |_| |
  \_____| |_| |_|  \___/   \___/  |___/  \___|   |_____/  |_| |_|   |_|   |_|  \___|  \__,_| |_|  \__|  \__, |
                                                                                                         __/ |
                                                                                                        |___/ 
)" << endl ;
cout << R"(
  _    _          _         
 | |  | |        | |        
 | |__| |   ___  | |  _ __  
 |  __  |  / _ \ | | | '_ \ 
 | |  | | |  __/ | | | |_) |
 |_|  |_|  \___| |_| | .__/ 
                     | |    
                     |_|    
)" << endl ; 
                cout << R"(
  ______          _   _        _____                            
 |  ____|        (_) | |      / ____|                           
 | |__    __  __  _  | |_    | |  __    __ _   _ __ ___     ___ 
 |  __|   \ \/ / | | | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
 | |____   >  <  | | | |_    | |__| | | (_| | | | | | | | |  __/
 |______| /_/\_\ |_|  \__|    \_____|  \__,_| |_| |_| |_|  \___|
)" << endl ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            cout << "Navigate using the up and down arrow keys. Press the enter key to select an option . . . " ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
            break ;
            case 2 : 
            {
                cout << R"(
   _____   _                    _        _____                            
  / ____| | |                  | |      / ____|                           
 | (___   | |_    __ _   _ __  | |_    | |  __    __ _   _ __ ___     ___ 
  \___ \  | __|  / _` | | '__| | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
  ____) | | |_  | (_| | | |    | |_    | |__| | | (_| | | | | | | | |  __/
 |_____/   \__|  \__,_| |_|     \__|    \_____|  \__,_| |_| |_| |_|  \___|
                                                                          
                                                                          
)" << endl ; // font used is big
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x01 ) ; cout << R"(
   _____   _                                      _____    _    __    __   _                  _   _           
  / ____| | |                                    |  __ \  (_)  / _|  / _| (_)                | | | |          
 | |      | |__     ___     ___    ___    ___    | |  | |  _  | |_  | |_   _    ___   _   _  | | | |_   _   _ 
 | |      | '_ \   / _ \   / _ \  / __|  / _ \   | |  | | | | |  _| |  _| | |  / __| | | | | | | | __| | | | |
 | |____  | | | | | (_) | | (_) | \__ \ |  __/   | |__| | | | | |   | |   | | | (__  | |_| | | | | |_  | |_| |
  \_____| |_| |_|  \___/   \___/  |___/  \___|   |_____/  |_| |_|   |_|   |_|  \___|  \__,_| |_|  \__|  \__, |
                                                                                                         __/ |
                                                                                                        |___/ 
)" << endl ;
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07) ;
cout << R"(
  _    _          _         
 | |  | |        | |        
 | |__| |   ___  | |  _ __  
 |  __  |  / _ \ | | | '_ \ 
 | |  | | |  __/ | | | |_) |
 |_|  |_|  \___| |_| | .__/ 
                     | |    
                     |_|    
)" << endl ;
                cout << R"(
  ______          _   _        _____                            
 |  ____|        (_) | |      / ____|                           
 | |__    __  __  _  | |_    | |  __    __ _   _ __ ___     ___ 
 |  __|   \ \/ / | | | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
 | |____   >  <  | | | |_    | |__| | | (_| | | | | | | | |  __/
 |______| /_/\_\ |_|  \__|    \_____|  \__,_| |_| |_| |_|  \___|
)" << endl ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            cout << "Navigate using the up and down arrow keys. Press the enter key to select an option . . . " ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
            break ;
            case 3 : 
            {
                cout << R"(
   _____   _                    _        _____                            
  / ____| | |                  | |      / ____|                           
 | (___   | |_    __ _   _ __  | |_    | |  __    __ _   _ __ ___     ___ 
  \___ \  | __|  / _` | | '__| | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
  ____) | | |_  | (_| | | |    | |_    | |__| | | (_| | | | | | | | |  __/
 |_____/   \__|  \__,_| |_|     \__|    \_____|  \__,_| |_| |_| |_|  \___|
                                                                          
                                                                          
)" << endl ;
                cout << R"(
   _____   _                                      _____    _    __    __   _                  _   _           
  / ____| | |                                    |  __ \  (_)  / _|  / _| (_)                | | | |          
 | |      | |__     ___     ___    ___    ___    | |  | |  _  | |_  | |_   _    ___   _   _  | | | |_   _   _ 
 | |      | '_ \   / _ \   / _ \  / __|  / _ \   | |  | | | | |  _| |  _| | |  / __| | | | | | | | __| | | | |
 | |____  | | | | | (_) | | (_) | \__ \ |  __/   | |__| | | | | |   | |   | | | (__  | |_| | | | | |_  | |_| |
  \_____| |_| |_|  \___/   \___/  |___/  \___|   |_____/  |_| |_|   |_|   |_|  \___|  \__,_| |_|  \__|  \__, |
                                                                                                         __/ |
                                                                                                        |___/ 
)" << endl ;
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x01) ; 
cout << R"(
  _    _          _         
 | |  | |        | |        
 | |__| |   ___  | |  _ __  
 |  __  |  / _ \ | | | '_ \ 
 | |  | | |  __/ | | | |_) |
 |_|  |_|  \___| |_| | .__/ 
                     | |    
                     |_|    
)" << endl ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 ) ; cout << R"(
  ______          _   _        _____                            
 |  ____|        (_) | |      / ____|                           
 | |__    __  __  _  | |_    | |  __    __ _   _ __ ___     ___ 
 |  __|   \ \/ / | | | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
 | |____   >  <  | | | |_    | |__| | | (_| | | | | | | | |  __/
 |______| /_/\_\ |_|  \__|    \_____|  \__,_| |_| |_| |_|  \___|
)" << endl; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            cout << "Navigate using the up and down arrow keys. Press the enter key to select an option . . . " ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
            break ;
            case 4 : 
            {
                cout << R"(
   _____   _                    _        _____                            
  / ____| | |                  | |      / ____|                           
 | (___   | |_    __ _   _ __  | |_    | |  __    __ _   _ __ ___     ___ 
  \___ \  | __|  / _` | | '__| | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
  ____) | | |_  | (_| | | |    | |_    | |__| | | (_| | | | | | | | |  __/
 |_____/   \__|  \__,_| |_|     \__|    \_____|  \__,_| |_| |_| |_|  \___|
                                                                          
                                                                          
)" << endl ; 
                cout << R"(
   _____   _                                      _____    _    __    __   _                  _   _           
  / ____| | |                                    |  __ \  (_)  / _|  / _| (_)                | | | |          
 | |      | |__     ___     ___    ___    ___    | |  | |  _  | |_  | |_   _    ___   _   _  | | | |_   _   _ 
 | |      | '_ \   / _ \   / _ \  / __|  / _ \   | |  | | | | |  _| |  _| | |  / __| | | | | | | | __| | | | |
 | |____  | | | | | (_) | | (_) | \__ \ |  __/   | |__| | | | | |   | |   | | | (__  | |_| | | | | |_  | |_| |
  \_____| |_| |_|  \___/   \___/  |___/  \___|   |_____/  |_| |_|   |_|   |_|  \___|  \__,_| |_|  \__|  \__, |
                                                                                                         __/ |
                                                                                                        |___/ 
)" << endl ; 
cout << R"(
  _    _          _         
 | |  | |        | |        
 | |__| |   ___  | |  _ __  
 |  __  |  / _ \ | | | '_ \ 
 | |  | | |  __/ | | | |_) |
 |_|  |_|  \___| |_| | .__/ 
                     | |    
                     |_|    
)" << endl ;
 SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x01) ;
                cout << R"(
  ______          _   _        _____                            
 |  ____|        (_) | |      / ____|                           
 | |__    __  __  _  | |_    | |  __    __ _   _ __ ___     ___ 
 |  __|   \ \/ / | | | __|   | | |_ |  / _` | | '_ ` _ \   / _ \
 | |____   >  <  | | | |_    | |__| | | (_| | | | | | | | |  __/
 |______| /_/\_\ |_|  \__|    \_____|  \__,_| |_| |_| |_|  \___|
)" << endl ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07) ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
            cout << "Navigate using the up and down arrow keys. Press the enter key to select an option . . . " ; 
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
            }
        }
                        

        keyhit = getch() ;

        if ((keyhit == KEY_DOWN) && (choice < 4) ) // to validate any change upon pressing the down key when in main menu
        {
            choice++ ;
        }
        if ((keyhit == KEY_UP) && (choice > 1) ) // to validate any change upon pressing the up key when in main menu
        {   
            choice-- ;
        }
        if (keyhit == ENTER)
        {
            switch(choice) 
            {
                case 1 : 
                {
                    return ;
                }
                break ;
                case 2 :
                {
                    displayDifficultyMenu(difficulty) ;
                }
                break ;
                case 3 : 
                {
                    displayHelp() ;
                }
                break ;
                case 4 : 
                {
                    exit(0) ;
                }
            }
        }
    }

}
        
        
/*
Sets the spaceship's position in the array
@param screen is the array that represents the playing screen
@param c is the center of the spaceship
no return value
*/
void wipeSpaceship(char screen[][W],int c)
{ 
    screen[(c - 1)][FPC] = ' ' ; screen[(c - 1)][FPC + 1] = ' ' ;
    screen[(c)][FPC] = ' ' ; screen[(c)][FPC + 2] = ' ' ;
    screen[(c + 1)][FPC] = ' '; screen[(c + 1)][FPC + 1] = ' ' ;   
}


/*
Sets the spaceship into the playing screen array
@param screen[][W] represents the array of playing screen
@param c is the center of spaceship
no return value
*/
void setSpaceship(char screen[][W] ,int c ) //Sets spaceship into playing screen and detects side-on collision
{
    screen[(c - 1)][FPC] = '|' ; screen[(c - 1)][FPC + 1] = '\\' ;
    screen[(c)][FPC] = '|' ; screen[(c)][FPC + 3] = '>' ;
    screen[(c + 1)][FPC] = '|'; screen[(c + 1)][FPC + 1] = '/' ;
}


/*
Displays the crash animation
@param screen[][W] represents the playing screen
@param c represents the center of spaceship
@param " represents the lives
no return value
*/
void collision(char screen[][W] , int c, int& l)
{
    screen[(c - 1)][FPC] = 'C' ; screen[(c - 1)][FPC + 1] = 'R' ;
    screen[(c)][FPC] = ' ' ; screen[(c)][FPC + 3] = 'A' ;
    screen[(c + 1)][FPC] = 'S'; screen[(c + 1)][FPC + 1] = 'H' ;
    l-- ;
}


/*
Sets the spaceship after a new prospective centre is tested to detect side-on collision
@param screen[][W] represents array of the playing screen
@param c represents the original y-coordinate of the centre of spaceship 
@param nc denotes new prospective center of spaceship
@param l represents the lives.
no return value
*/
void updateSpaceship(char screen[][W] ,int& c, int& nc, int& l ) //Sets spaceship into playing screen and detects side-on collision
{
    if ((screen[(nc - 1)][1] == '0') || (screen[(nc - 1)][1] == '+')) { collision(screen, c , l) ; }  
    else if ((screen[(nc - 1)][2] == '0') || (screen[(nc - 1)][2] == '+')) { collision(screen, c , l) ; }
    else if ((screen[(nc)][1] == '0') || (screen[(nc)][1] == '+')) { collision(screen, c , l) ; }
    else if ((screen[(nc)][3] == '0') || (screen[(nc)][3] == '+')) { collision(screen, c , l) ; }
    else if ((screen[(nc + 1)][1] == '0') || (screen[(nc + 1)][1] == '+')) { collision(screen, c , l) ; }
    else if ((screen[(nc + 1)][2] == '0') || (screen[(nc + 1)][2] == '+')){ collision(screen, c , l) ; }

    else 
    {
        c = nc ;
        setSpaceship(screen, c) ;
    }
}


/*
Detects the head-on collision and shifts all elements to the left with the exception of the spaceship and a crash animation. Gives the illusion of motion
@param "screen[][W]"denotes the array of playing screen
@param "cen" represents the center of spaceship
@param "l" represents the lives
no return value
*/
void updateScreen(char screen[][W] , int cen , int& l )
{
    if ((screen[(cen - 1)][3] == '0') || (screen[(cen - 1)][3] == '+')) { collision(screen, cen , l) ; }
    else if ((screen[(cen)][5] == '0') || (screen[(cen)][5] == '+')) { collision(screen, cen , l) ; }
    else if ((screen[(cen + 1)][3] == '0') || (screen[(cen + 1)][3] == '+')){ collision(screen, cen , l) ; }

    for (int i = FPR ; i <= LPR ; i++)
    {
        for (int j = FPC ; j <= (LPC-1) ; j++)
        {
            if (!((screen[i][j] == '|') || (screen[i][j] == '\\') || (screen[i][j] == '/')  ||  (screen[i][j] == '>') || (screen[i][j] == 'C') || (screen[i][j] == 'R')  ||  (screen[i][j] == 'A') ||  (screen[i][j] == 'S') ||  (screen[i][j] == 'H')))
            {
            screen[i][j] = screen[i][j+1] ;
            screen[i][j+1] = ' ' ;
            }
        }
    }
}


/*
Generates the walls/hurdles represented by '+'
@param "screen [][W]" represents the array of playing screen
@param minfreespace represents free space available for a particular difficulty level
no return value
*/
void generateWalls(char screen[][W] , int minfreespace)
{
    milliseconds ms = duration_cast< milliseconds >( // Here the current time in milliseconds is generated and then stored into ms, a chrono library variable 
    system_clock::now().time_since_epoch()
    );
    int tms = ms.count(); // The value in ms is converted to a fundamental data type here to be stored into an int variable
    srand(tms) ; //The seed then is the current precise time, different with every call

    int upperwallstart = 1 ; //2 - 1
    int upperwallend , lowerwallstart , freespace = 0 ;
    int lowerwallend = LPR ; //(H-1) - 1
    
    while (freespace < minfreespace) 
    {
        // For generation of a random number x, with range: a <= x <= b
        // x = (rand()% (b - a - 1) ) + a
        
        upperwallend = ((rand() % (H - 2)) - 1 - 1) + 1 ;  //yields a possibe index of the end of the upper wall [a = (2) - 1 b = (H - 1) -1]
        lowerwallstart = ((rand()%(H-2))-1-1) + 1  ;  //yields a possible index of the start of the lower wall [a = (2) - 1 b = (H - 1) -1]
        freespace = lowerwallstart - upperwallend - 1 ; //validate the random numbers generated a- Make sure lower end is at a higher index and hence at a lower position in the array b- There is enough room for the spaceship
    }

    for (int i = upperwallstart ; i <= upperwallend ; i++ )
    {
        screen[i][LPC] = '+' ;
    }
    
    for (int i = lowerwallstart ; i <= lowerwallend ; i++ )
    {
        screen[i][LPC] = '+' ;
    }
}

/*
Randomly generates an asteroid within bounds
@param "screen [][W]" denotes the array of playing screen
no return value
*/
void setAsteroid(char screen [][W])
{
    milliseconds ms = duration_cast< milliseconds >( // Here the current time in milliseconds is generated and then stored into ms, a chrono library variable
    system_clock::now().time_since_epoch()
    );
    int tms = ms.count(); // The value in ms is converted to a fundamental data type here to be stored into an int variable
    srand(tms) ; //The seed then is the current precise time, different with every call

    int ypos = 0 ;
    int xpos = W - 2 ;

    while(screen[ypos][xpos] != ' ') 
    {
        ypos = (rand()%(H-1-1+1))+1 ;
    }
    
    screen[ypos][xpos] = '0' ;    
} 


/*
Makes the cursor invisible in the terminal
no parameter value
no return value
*/
void hideCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false ; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);

}


/*
Display the score at the top of terminal
@param "s" represents the score
no return value
*/
void printScore(int s)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x02 ); cout << "SCORE: " << s << "\t \t \t \t" << endl << flush ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
}


/*
Display the lives at the top of terminal
@param l represents the lives
no return value
*/
void printLives(int l)
{
    if(l == 3)
        {
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x04 ); cout << "<3 <3 <3" << flush ;
        }
        else if(l == 2)
        {
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x08 ); cout << "</3" << flush ;
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x04 ); cout << "<3 <3" << flush ;
        }
        else if (l == 1)
        {
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x08 ); cout << "</3 </3" << flush ;
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x04 ); cout << "<3" << flush ;
        }
        else
        {
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x08 ); cout << "</3 </3 </3" << flush ;
        }
        
        cout << endl << endl << flush ;
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 ); // Reset the colour scheme
}

/*
Prints the playing screen
no paramater values
no return value
*/
void printPlayingscreen(char screen[][W])
{
    for (int i = 0 ; i <= LR ; i++)
        {
            for (int j = 0 ; j <= LC ; j++ )
            {
                if(screen[i][j] == '-' )
                {
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x01 );
                    cout << screen[i][j] << flush ;
                    screen[i][j] = ' ' ;
                }
                else if ((screen[i][j] == 'C') || (screen[i][j] == 'R') || (screen[i][j] == 'A') || (screen[i][j] == 'S') || (screen[i][j] == 'H'))
                {
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x04 );
                    cout << screen[i][j] << flush ;
                }
                else 
                {
                    cout << screen[i][j] << flush ;
                }
                SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
            }
            cout << "\n" ;
        }
} 


/*
Displays the game-over screen and print the final score
@param s represents the final score
no return value
*/
void gameOver(int s)
{
    int keyhit = 0 ;

    system("cls") ;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x03 );
    cout << R"(
 _______  _______  _______  _______    _______           _______  _______ 
(  ____ \(  ___  )(       )(  ____ \  (  ___  )|\     /|(  ____ \(  ____ )
| (    \/| (   ) || () () || (    \/  | (   ) || )   ( || (    \/| (    )|
| |      | (___) || || || || (__      | |   | || |   | || (__    | (____)|
| | ____ |  ___  || |(_)| ||  __)     | |   | |( (   ) )|  __)   |     __)
| | \_  )| (   ) || |   | || (        | |   | | \ \_/ / | (      | (\ (   
| (___) || )   ( || )   ( || (____/\  | (___) |  \   /  | (____/\| ) \ \__
(_______)|/     \||/     \|(_______/  (_______)   \_/   (_______/|/   \__/
                                                                          
)" << endl ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x0F ); cout << "YOUR SCORE IS: "<< s << endl << endl ; SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
    Sleep(5000) ;

    while(kbhit()) getch();

    cout << "Press escape to exit, press any key to play again . . . " ;

    keyhit = getch() ;
    system("cls") ;
    if (keyhit == ESCAPE)
    {
        exit (0) ;
    }
    else
    {
        return ;
    }
}

int main()
{
    char playingscreen[H][W] = {} ; //This the actual array in which all the animations and gameplay occurs

    int cen , newcen , score , minfreespace , freepercentage = 0 ;

    /*cen is a variable storing the row number and hence height of the spaceship in the array. It corresponds to the spaceship centre
    newcen is a variable storing a prospective new height which needs to be checked for collisions before being implemented
    freepercentage stores a value denoting the percentage of free vertical space 
    minfreespace is a variable representing the minimum vertical free space that would be left during random wall generation. It is calculated by the use of difficulty and minfreepercentage during the program run 
    */

    int lives = 3 ;                 //This is the number of lives. Each collision decrements this variable by 1
    int difficulty = 1;             //This variable represents the difficulty level chosen. 1 corresponds to easy, 2 to medium, 3 to hard
    int cannonpenetration = 8 ;     //This variable, along with difficulty level, determine the number of asteroids the cannon can destroy via piercing through as well
    score = 0 ;                     //This variable keeps a count of the score accumulated in a specific game, finally being output once it ends
    
    cen = H/2 ; //Yields height upon which centre of the centre of the spacehsip would lie. It is half of the total height

    hideCursor() ;  //Called to hide the cursor for aesthetic purposes

    displayTitle() ; //Called to show the title screen

    displayMenu(difficulty) ; //Called to initiate the Main menu, difficulty is passed as a reference parameter so that any change in the difficulty selected would 

    switch (difficulty) 
    {
        case 1 : //Easy
        {
            freepercentage = 80 ; //At least about 80% of the total height of the playable area would be empty on each wall generation
        }
        break ;
        case 2 :  //Medium
        {
            freepercentage = 65 ;  //At least about 65% of the total height of the playable area would be empty on each wall generation
        }
        break ;
        case 3 :  //Hard
        {
            freepercentage = 50 ;  //At least about 50% of the total height of the playable area would be empty on each wall generation
        }
        break ;
    }

    minfreespace = ((H - 2) * freepercentage) / 100 ; //Calculation of minfreespace once freepercentage has been set according to difficulty

    initialiseScreen(playingscreen) ; //The screen is initialised

    while (lives > 0) //Here the actual game begins. It terminates once the lives go down to zero
    {
        wipeSpaceship(playingscreen, cen) ; //Clears the previous position of the spaceship to ensure no residual contents stay on screen 

        generateWalls(playingscreen , minfreespace) ; //Randomly generates walls in the last playingscreen column, before the hash boundary

        for (int i = 0 ; i < difficulty ; i++ )  //Iterates 'difficulty' number of times
        {
            setAsteroid(playingscreen) ; //Randomly generate an asteroid in the last playing screen column, before the hash boundary
        }

        if(_kbhit()) // If a key on the keyboard is pressed, execute the following code
        {
            newcen = cen ;  //The current position of the spaceship is assigned to new centre 
            switch(_getch()) //Select a a certain action for a specific key entered
            {
                case SPACEBAR: 
                {
                    setSpaceship(playingscreen , cen) ; //The spaceship doesn't move so its position remains the same. It is set into the array
                    cannonpenetration = 8 - (2 * difficulty) ; // The number of asteroids the cannon destroys. 6 in easy mode, 4 in medium, 2 in hard
                    for(int i = 5 ; i <= LPC ; i++ ) //Iterate to set elements in front of the spaceship centre to show the cannon beam
                    {
                        if (playingscreen[cen][i] == '0') //If the beam hits an asteroid, decrement the penetration 
                        {
                            if (cannonpenetration == 0) //If the penetration has reached 0, stop the cannon's beam
                            {
                                break ;
                            }
                            playingscreen[cen][i] = '-' ; //Sets the elements to hyphen to represent cannon beam
                            score += 1000 ;               //Upon each successful asteroid hit, increments the score by 1000  
                            cannonpenetration-- ;         //Decrements penetration with each successful asteroid hit 
                        }
                        else if (playingscreen[cen][i] == '+') //Check if the beam has hit a wall
                        {
                            break ; //If it has, stop th cannon beam
                        }
                        playingscreen[cen][i] = '-' ; //Here in the case of the only remainin space character, simply overwrite 
                    }
                }
                break ;
                case KEY_DOWN : //Upon the down arrow key being pressed, the following code is executed
                {
                    if (cen < (H-3)) //This checks to make sure the spaceship doesn't collide with the lower hash boundary
                    {
                        newcen = cen + 1; //The prospective new position of the centre of the spaceship. It is incremented even though the down arrow key is pressed since the row number increases downwards 
                        updateSpaceship(playingscreen , cen , newcen , lives ) ; //The spaceship's new position is checked to see if it yields a collision. If it it doesn't, the position is updated. If it does, the collsion sequence is executed
                    }
                    else {collision(playingscreen ,cen, lives );} //If the spaceship collides with the lower hash boundary, the collision sequence is executed
                }
                break;
                case KEY_UP : //Upon the up arrow key being pressed, the following code is executed
                {
                    if(cen > 2 ) //This checks to make sure the spaceship doesn't collide with the upper hash boundary
                    {
                        newcen = cen - 1 ; //The prospective new position of the centre of the spaceship. It is decremented even though the up arrow key is pressed since the row number decreases upwards
                        updateSpaceship(playingscreen , cen , newcen , lives ) ; //The spaceship's new position is checked to see if it yields a side-on collision. If it it doesn't, the position is updated. If it does, the collsion sequence is executed
                    }
                    else {collision(playingscreen,cen , lives);} //If the spaceship collides with the upper hash boundary, the collision sequence is executed
                }
                break;
                case ESCAPE : 
                {
                    exit(0) ; // Upon pressing the escape key terminate the program, exiting the game
                }
                break ;
                default : 
                {
                    setSpaceship(playingscreen , cen) ; //Upon pressing any other key, the spaceship is still set into the array
                }
            }
        } 
        else
        {
        setSpaceship(playingscreen , cen) ; //Even if no keyboard button is pressed, the spaceship is set into the array
        }

        updateScreen(playingscreen , cen , lives) ; //The array elements are moved left to give an illusion of motion of the spaceship. This function is also responsible for detecting head-on collisions

        score += 100 ; //Upon each iteration covered by the spaceship, the score is incremented by 100
        
        /*Printing*/ 

        printScore(score) ; //Outputs the player's current score

        printLives(lives) ; //Outputs the lives remaining as well as lost 

        printPlayingscreen(playingscreen) ; //Outputs the playingscreen
        
        Sleep(5) ; //The program is paused after every iteration to give a semblance of smoothness and so that the output is visible and comprehensible enough
        system ("CLS") ; // The printed array and other output are all completely erased and the screen is cleared before the next iteration
                
    }

    gameOver(score); //Show the game over screen upon the end of the game. Here the user can choose to terminate the program and exit the game as well

    main () ; //Restart the whole program and hence the game
    
    return 0 ;
}
