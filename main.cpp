// Jalen Veiga and Nicole Rubio
//Project 4

#include <iostream>
#include <string>
#include <iomanip>

//Global Constants
const int ROWS = 10;
const int COLS =10;

//Structure Declaration
struct Treasure {
   std::string chestName;
   int userROW;
   int userCOLS;
   double loot;
   bool found;
};
//Function Prototype
void printIntro();
void fillGrid(char[][COLS], char);
void editGrid(char[][COLS], char);
void printGrid(char[][COLS]);
void inputValidation(int, int);

int main() {
   //Variables and Constants
   const int MAX_GUESS = 3;
   const char GRID_SYM = '-';
   const char CHEST_SYM = 'T';
   const char EMPTY_SYM = 'E';
   const int CHEST_QTY = 3;
   int USER_GUESS = 0;
   int USER_ROWS = 0;
   int USER_COLS = 0;
   int counter = 0;
   double totalLoot = 0;
   char grid[ROWS][COLS];
   char reply = ' ';

   //Structure Members
   Treasure chest1 = {"Pirate's Chest", 2, 4, 145.90, true};
   Treasure chest2 = {"Dragon's Chest", 5, 8, 258.24, true};
   Treasure chest3 = {"Troll's Chest", 3, 1, 203.71, true};
   Treasure chest4 = {"Queen's Chest", 8, 0, 190.15, true};
   Treasure chest5 = {"Thief's Chest", 1, 9, 98.95, true};

   //Fill the 2D grid with the grid symbol
   fillGrid(grid,GRID_SYM);

   //Print Intro
   printIntro();

   //Loop until User stops or reaches MAX guesses
   do{
       printGrid(grid);

       inputValidation(USER_ROWS, USER_COLS);

       std::cout << "Would you like to play again (Y or N)? ";
       std::cin >> reply;
       std::cout << std::endl;

   } while((toupper(reply) == 'Y'));

   return 0;
}
void printIntro(){
   std::cout << "This is a treasure hunt game.\n"
                "You have 3 attempts to find the 5 treasure chests hidden in the grid below.\n" << std::endl;
}
//Create a grid full of default symbol
void fillGrid(char arr[][COLS], const char SYM){
   for (int r = 0; r< ROWS; r++){
       for(int c = 0; c < COLS; c++){
           arr[r][c] = SYM;
       }
   }
}
// Store Treasure Chest Info
void editGrid(char arr[][COLS], const char SYM) {
   int r = 0;
   int c = 0;
   arr[r][c] = SYM;
}
//Print default grid with headings
void printGrid(char arr[][COLS]){
   std::cout << std::fixed << std::setprecision(2);
   std::cout << std::left << std::setw(10) << "  0 1 2 3 4 5 6 7 8 9\n";   //ROWS HEADINGS
   for (int r = 0; r < ROWS; r++) {
       std::cout << r <<  ' ';     // COLS HEADING
       for(int c = 0; c < COLS; c++){
           std::cout << arr[r][c]<< ' ';
       }
       std::cout << std::endl;
   }
   //Print Legend
   std::cout << std::endl;
   std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n" << std::endl;
}
void inputValidation(int userR, int userC){
       // VALIDATE USER'S ROW
       std::cout << "Enter the row #: ";
       std::cin >> userR;
       std::cout << std::endl;

       while (userR > ROWS || userR < 0 || std::cin.fail()) {
           if (std::cin.fail()) {
               std::cin.clear();
               std::cin.ignore(100, '\n');
           }
           std::cout << "That entry is invalid. Please enter a valid integer based on the grid size: ";
           std::cin >> userR;
       }
       //VALIDATE USER'S COLS
       std::cout << "Enter the column #: ";
       std::cin >> userC;
       std::cout << std::endl;

       while (userC > COLS || userC < 0 || std::cin.fail()) {
           if (std::cin.fail()) {
               std::cin.clear();
               std::cin.ignore(100, '\n');
           }
           std::cout << "That entry is invalid. Please enter a valid integer based on the grid size: ";
           std::cin >> userC;
       }
}



*** updated

// Jalen Veiga and Nicole Rubio
//Project 4

#include <iostream>
#include <string>
#include <iomanip>

//Global Constants
const int ROWS = 10;
const int COLS =10;
const int SIZE = 5;

int userRow= 0;
int userCols= 0;
double userWon = 0.00;

//Structure Declaration
struct Treasure {
   std::string chestName;
   int userROW;
   int userCOLS;
   double loot;
   bool found;
};
//Function Prototype
void printIntro();
void fillGrid(char[][COLS], char);
double editGrid(Treasure[],int,int,char,char[][COLS], double);
void printGrid(char[][COLS]);
void inputValidation(int, int);
void endGrid(char[][COLS],char);



int main() {
   //Variables and Constants
   const int MAX_GUESS = 3;
   const char GRID_SYM = '-';
   const char CHEST_SYM = 'T';

   Treasure treasure[SIZE] ;
   int UserGuess = 0;
   int counter = 0;
   double totalLoot = 0.0;
   char grid[ROWS][COLS];
   char reply = ' ';

   //Structure Members
   Treasure chest1 = {"Pirate's Chest", 2, 4, 145.90, true};
   Treasure chest2 = {"Dragon's Chest", 5, 8, 258.24, true};
   Treasure chest3 = {"Troll's Chest", 3, 1, 203.71, true};
   Treasure chest4 = {"Queen's Chest", 8, 0, 190.15, true};
   Treasure chest5 = {"Thief's Chest", 1, 9, 98.95, true};

   //Fill the 2D grid with the grid symbol
   fillGrid(grid,GRID_SYM);

   //Print Intro
   printIntro();

   //Loop until User stops or reaches MAX guesses
   do{
       printGrid(grid);

       inputValidation(userRow, userCols);

       editGrid (treasure,userRow,userCols,GRID_SYM,grid, totalLoot);

       std::cout << "Would you like to play again (Y or N)? ";
       std::cin >> reply;
       std::cout << std::endl;

   } while((toupper(reply) == 'Y'));

   endGrid(grid,CHEST_SYM);

   return 0;
}
void printIntro(){
   std::cout << "This is a treasure hunt game.\n"
                "You have 3 attempts to find the 5 treasure chests hidden in the grid below.\n" << std::endl;
}
//Create a grid full of default symbol
void fillGrid(char arr[][COLS], const char SYM){
   for (int r = 0; r< ROWS; r++){
       for(int c = 0; c < COLS; c++){
           arr[r][c] = SYM;
       }
   }
}
// Store Treasure Chest Info
double editGrid(Treasure tr[], const int rows, const int cols,char SYM, char arr[][COLS], double totalLoot) {
   double amountLooted = 0.0;
   for(int i = 0; i < SIZE; i++) {
       if(arr[rows][cols] != SYM && !tr[i].found) {
           std::cout << "You already found the treasure at this location. "
                     << "Your stupidity has cost you a guess.\n"<< std::endl;
           arr[rows][cols] = 'E';
           return amountLooted;
       }else if(rows == tr[i].userROW && cols == tr[i].userCOLS) {
           std::cout << "You have found the " << tr[i].chestName << "!\n"
                     << "Inside you find $" << tr[i].loot << " worth of valuables.\n" << std::endl;
           arr[rows][cols] = 'T';
           amountLooted += tr[i].loot;
           tr[i].found = false;
           totalLoot = totalLoot + amountLooted;
           return amountLooted;
       }
   }
   arr[rows][cols] = 'E';
   std::cout << "Sorry, there is no treasure at those coordinates." << std::endl;
   return amountLooted;
}
//Print default grid with headings
void printGrid(char arr[][COLS]){
   std::cout << std::fixed << std::setprecision(2);
   std::cout << std::left << std::setw(10) << "  0 1 2 3 4 5 6 7 8 9\n";   //ROWS HEADINGS
   for (int r = 0; r < ROWS; r++) {
       std::cout << r <<  ' ';     // COLS HEADING
       for(int c = 0; c < COLS; c++){
           std::cout << arr[r][c]<< ' ';
       }
       std::cout << std::endl;
   }
   //Print Legend
   std::cout << std::endl;
   std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n" << std::endl;
}
void inputValidation(int userR, int userC){
   // VALIDATE USER'S ROW
   std::cout << "Enter the row #: ";
   std::cin >> userR;
   std::cout << std::endl;

   while (userR > ROWS || userR < 0 || std::cin.fail()) {
       if (std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore(100, '\n');
       }
       std::cout << "That entry is invalid. Please enter a valid integer based on the grid size: ";
       std::cin >> userR;
   }
   //VALIDATE USER'S COLS
   std::cout << "Enter the column #: ";
   std::cin >> userC;
   std::cout << std::endl;

   while (userC > COLS || userC < 0 || std::cin.fail()) {
       if (std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore(100, '\n');
       }
       std::cout << "That entry is invalid. Please enter a valid integer based on the grid size: ";
       std::cin >> userC;
   }
}

void endGrid(char arr[][COLS],const char CHEST_SYM) {
   std:: cout <<"The game is now over. You looted $" << userWon << " worth of valuables from chests." << std:: endl;
   std:: cout <<"The grid below shows the position of all treasure chests: " << std:: endl;
   std:: cout << std:: endl;
   std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
   for (int r = 0; r < ROWS; r++) {
       std::cout << r << ' ';
       for (int c = 0; c < COLS; c++) {
           std::cout << arr[r][c] << ' ';
           arr[2][4] = CHEST_SYM;
           arr[5][8] = CHEST_SYM;
           arr[3][1] = CHEST_SYM;
           arr[8][0] = CHEST_SYM;
           arr[1][9] = CHEST_SYM;
       }
       std::cout << std::endl;
   }
   std::cout << std::endl;
   std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n";
   std::cout << std::endl;
}


// Jalen Veiga and Nicole Rubio
//Project 4

#include <iostream>
#include <string>
#include <iomanip>

//Global Constants
const int ROWS = 10;
const int COLS =10;
const int SIZE = 5;

int userRow= 0;
int userCols= 0;
double userWon = 0.00;

//Structure Declaration
struct Treasure {
   std::string chestName;
   int userROW;
   int userCOLS;
   double loot;
   bool found;
};
//Function Prototype
void printIntro();
void TreasureArray(Treasure[]);
void fillGrid(char[][COLS], char);
double editGrid(Treasure[],int,int,char,char[][COLS], double);
void printGrid(char[][COLS]);
bool inputValidation(int);
void endGrid(char[][COLS],char);

int main() {
   //Variables and Constants
   const int MAX_GUESS = 3;
   const char GRID_SYM = '-';
   const char CHEST_SYM = 'T';

   Treasure treasure[SIZE];
   int counter = 0;
   double totalLoot = 0.0;
   char grid[ROWS][COLS];
   char reply = ' ';

   //Print Intro
   printIntro();


   //Fill the 2D grid with the grid symbol
   TreasureArray(treasure);
   fillGrid(grid,GRID_SYM);
   std:: cout << std::fixed << std::setprecision(2);

   //Loop until User stops or reaches MAX guesses
   do{
       printGrid(grid);
       std::cout << "Enter the row #: ";
       std::cin >> userRow;
       std::cout << std::endl;
       while (inputValidation(userRow) == false) {
           std::cin >> userRow;
       }
       std::cout << "Enter the column #: ";
       std::cin >> userCols;
       std::cout << std::endl;
       while (inputValidation(userCols) == false) {
           std::cin >> userCols;
       }
       editGrid(treasure,userRow,userCols,GRID_SYM,grid,totalLoot);

       std::cout << "Would you like to play again (Y or N)? ";
       std::cin >> reply;
       std::cout << std::endl;
       counter++;

   } while(counter != MAX_GUESS && (toupper(reply) == 'Y'));

   endGrid(grid,CHEST_SYM);

   return 0;
}
void printIntro(){
   std::cout << "This is a treasure hunt game.\n"
                "You have 3 attempts to find the 5 treasure chests hidden in the grid below.\n" << std::endl;
}
void TreasureArray(Treasure tr[]){
   tr[0] = {"Pirate's Chest", 2, 4, 145.90, true};
   tr[1]= {"Dragon's Chest", 5, 8, 258.24, true};
   tr[2]= {"Troll's Chest", 3, 1, 203.71, true};
   tr[3] = {"Queen's Chest", 8, 0, 190.15, true};
   tr[4] = {"Thief's Chest", 1, 9, 98.95, true};
}
//Create a grid full of default symbol
void fillGrid(char arr[][COLS], const char SYM){
   for (int r = 0; r< ROWS; r++){
       for(int c = 0; c < COLS; c++){
           arr[r][c] = SYM;
       }
   }
}
// Store Treasure Chest Info
double editGrid(Treasure tr[], const int rows, const int cols,char SYM, char arr[][COLS], double totalLoot) {
   double amountLooted = 0.0;
   for(int i = 0; i < SIZE; i++) {
       if(arr[rows][cols] != SYM && !tr[i].found) {
           std::cout << "You already found the treasure at this location. "
                     << "Your stupidity has cost you a guess.\n"<< std::endl;
           arr[rows][cols] = 'E';
           return amountLooted;
       }else if(rows == tr[i].userROW && cols == tr[i].userCOLS) {
           std::cout << "You have found the " << tr[i].chestName << "!\n"
                     << "Inside you find $" << tr[i].loot << " worth of valuables.\n" << std::endl;
           arr[rows][cols] = 'T';
           amountLooted += tr[i].loot;
           tr[i].found = false;
           totalLoot = totalLoot + amountLooted;
           return amountLooted;
       }
   }
   arr[rows][cols] = 'E';
   std::cout << "Sorry, there is no treasure at those coordinates." << std::endl;
   return amountLooted;
}
//Print default grid with headings
void printGrid(char arr[][COLS]){
   std::cout << std::fixed << std::setprecision(2);
   std::cout << std::left << std::setw(10) << "  0 1 2 3 4 5 6 7 8 9\n";   //ROWS HEADINGS
   for (int r = 0; r < ROWS; r++) {
       std::cout << r <<  ' ';     // COLS HEADING
       for(int c = 0; c < COLS; c++){
           std::cout << arr[r][c]<< ' ';
       }
       std::cout << std::endl;
   }
   //Print Legend
   std::cout << std::endl;
   std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n" << std::endl;
}
bool inputValidation(int userInput){
   while (userInput > 9 || userInput < 0 || std::cin.fail()) {
       if (std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore();
       }
       std::cout << "That entry is invalid. Please enter a valid integer based on the grid size: " << std::endl;
       return false;
   }
   return true;
}


void endGrid(char arr[][COLS],const char CHEST_SYM) {
   std:: cout <<"The game is now over. You looted $" << userWon << " worth of valuables from chests." << std:: endl;
   std:: cout <<"The grid below shows the position of all treasure chests: " << std:: endl;
   std:: cout << std:: endl;
   std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
   for (int r = 0; r < ROWS; r++) {
       std::cout << r << ' ';
       for (int c = 0; c < COLS; c++) {
           std::cout << arr[r][c] << ' ';
           arr[2][4] = CHEST_SYM;
           arr[5][8] = CHEST_SYM;
           arr[3][1] = CHEST_SYM;
           arr[8][0] = CHEST_SYM;
           arr[1][9] = CHEST_SYM;
       }
       std::cout << std::endl;
   }
   std::cout << std::endl;
   std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n";
   std::cout << std::endl;
}


*************************FINAL************************

// Jalen Veiga and Nicole Rubio
//Project 4

#include <iostream>
#include <string>
#include <iomanip>

//Global Constants
const int ROWS = 10;
const int COLS =10;
const int SIZE = 5;

int userRow= 0;
int userCols= 0;
double userWon = 0.00;

//Structure Declaration
struct Treasure {
   std::string chestName;
   int userROW;
   int userCOLS;
   double loot;
   bool found;
};
//Function Prototype
void printIntro();
void TreasureArray(Treasure[]);
void fillGrid(char[][COLS], char);
double editGrid(Treasure[],int,int,char,char[][COLS], double);
void printGrid(char[][COLS]);
bool inputValidation(int);
void endGrid(char[][COLS],char);

int main() {
   //Variables and Constants
   const int MAX_GUESS = 3;
   const char GRID_SYM = '-';
   const char CHEST_SYM = 'T';

   Treasure treasure[SIZE];
   int counter = 0;
   double totalLoot = 0.0;
   char grid[ROWS][COLS];
   char reply = ' ';

   //Print Intro
   printIntro();


   //Fill the 2D grid with the grid symbol
   TreasureArray(treasure);
   fillGrid(grid,GRID_SYM);
   std:: cout << std::fixed << std::setprecision(2);

   //Loop until User stops or reaches MAX guesses
   do{
       printGrid(grid);
       std::cout << "Enter the row #: ";
       std::cin >> userRow;
       std::cout << std::endl;
       while (inputValidation(userRow) == false) {
           std::cin >> userRow;
       }
       std::cout << "Enter the column #: ";
       std::cin >> userCols;
       std::cout << std::endl;
       while (inputValidation(userCols) == false) {
           std::cin >> userCols;
       }
       editGrid(treasure,userRow,userCols,GRID_SYM,grid,totalLoot);

       std::cout << "Would you like to play again (Y or N)? ";
       std::cin >> reply;
       std::cout << std::endl;
       counter++;

   } while(counter != MAX_GUESS && (toupper(reply) == 'Y'));

   endGrid(grid,CHEST_SYM);

   return 0;
}
void printIntro(){
   std::cout << "This is a treasure hunt game.\n"
                "You have 3 attempts to find the 5 treasure chests hidden in the grid below.\n" << std::endl;
}
void TreasureArray(Treasure tr[]){
   tr[0] = {"Pirate's Chest", 2, 4, 145.90, true};
   tr[1]= {"Dragon's Chest", 5, 8, 258.24, true};
   tr[2]= {"Troll's Chest", 3, 1, 203.71, true};
   tr[3] = {"Queen's Chest", 8, 0, 190.15, true};
   tr[4] = {"Thief's Chest", 1, 9, 98.95, true};
}
//Create a grid full of default symbol
void fillGrid(char arr[][COLS], const char SYM){
   for (int r = 0; r< ROWS; r++){
       for(int c = 0; c < COLS; c++){
           arr[r][c] = SYM;
       }
   }
}
// Store Treasure Chest Info
double editGrid(Treasure tr[], const int rows, const int cols,char SYM, char arr[][COLS], double totalLoot) {
   double amountLooted = 0.0;
   for(int i = 0; i < SIZE; i++) {
       if(arr[rows][cols] != SYM && !tr[i].found) {
           std::cout << "You already found the treasure at this location. "
                     << "Your stupidity has cost you a guess.\n"<< std::endl;
           arr[rows][cols] = 'E';
           return amountLooted;
       }else if(rows == tr[i].userROW && cols == tr[i].userCOLS) {
           std::cout << "You have found the " << tr[i].chestName << "!\n"
                     << "Inside you find $" << tr[i].loot << " worth of valuables.\n" << std::endl;
           arr[rows][cols] = 'T';
           amountLooted += tr[i].loot;
           tr[i].found = false;
           userWon =  userWon + amountLooted;
           return amountLooted;
       }
   }
   arr[rows][cols] = 'E';
   std::cout << "Sorry, there is no treasure at those coordinates." << std::endl;
   return amountLooted;
}
//Print default grid with headings
void printGrid(char arr[][COLS]){
   std::cout << std::fixed << std::setprecision(2);
   std::cout << std::left << std::setw(10) << "  0 1 2 3 4 5 6 7 8 9\n";   //ROWS HEADINGS
   for (int r = 0; r < ROWS; r++) {
       std::cout << r <<  ' ';     // COLS HEADING
       for(int c = 0; c < COLS; c++){
           std::cout << arr[r][c]<< ' ';
       }
       std::cout << std::endl;
   }
   //Print Legend
   std::cout << std::endl;
   std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n" << std::endl;
}
bool inputValidation(int userInput){
   while (userInput > 9 || userInput < 0 || std::cin.fail()) {
       if (std::cin.fail()) {
           std::cin.clear();
           std::cin.ignore();
       }
       std::cout << "That entry is invalid. Please enter a valid integer based on the grid size: " << std::endl;
       return false;
   }
   return true;
}


void endGrid(char arr[][COLS],const char CHEST_SYM) {
   std:: cout <<"The game is now over. You looted $" << userWon << " worth of valuables from chests." << std:: endl;
   std:: cout <<"The grid below shows the position of all treasure chests: " << std:: endl;
   std:: cout << std:: endl;
   std::cout << "  0 1 2 3 4 5 6 7 8 9\n";
   for (int r = 0; r < ROWS; r++) {
       std::cout << r << ' ';
       for (int c = 0; c < COLS; c++) {
           std::cout << arr[r][c] << ' ';
           arr[2][4] = CHEST_SYM;
           arr[5][8] = CHEST_SYM;
           arr[3][1] = CHEST_SYM;
           arr[8][0] = CHEST_SYM;
           arr[1][9] = CHEST_SYM;
       }
       std::cout << std::endl;
   }
   std::cout << std::endl;
   std::cout << "Legend: - (Unknown); E (Empty); T (Treasure)\n";
   std::cout << std::endl;
}
