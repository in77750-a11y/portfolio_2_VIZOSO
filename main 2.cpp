//
//  main.cpp
//  Portfolio Dungeon
//
//  Created by Andres Vizoso on 2/9/26.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Player {

    string name = "Henry";
    int player_strength;
    int player_Hearts;
    int player_defense;
    int keys;
    

    Player(string n){
        name = n;
        player_strength = 3;
        player_Hearts = 5;
        player_defense = 3;
        keys = 0;
    }
    
    Player(){
        string n;
        name = n;
        player_strength = 3;
        player_Hearts = 5;
        player_defense = 3;
        keys = 0;
    }
    
};

void pretty_print_Player(const Player p){
        cout << "Meet your Wizard: " << p.name << endl;
        cout << "Stats:  " ;
        cout << "Hearts: " << p.player_Hearts << "  ";
        cout << "Strength: " << p.player_strength << "  ";
        cout << "defense: " << p.player_defense << "  ";
        cout << "Keys: " << p.keys << endl;
        //cout << "potion of Health: ";
        
    }
struct Enemy_RUNT{
    int Enemy_Hearts;
    int Enemy_Strength;
    int Enemy_Defense;

    Enemy_RUNT(){
            Enemy_Hearts = 1;
            Enemy_Strength = 1;
            Enemy_Defense = 1;
            
        }
        
};

struct Enemy_Brute{
    int Brute_Hearts;
    int Brute_Strength;
    int Brute_Defense;

    Enemy_Brute(){
            Brute_Hearts = 3;
            Brute_Strength = 3;
            Brute_Defense = 3;
            
        }
        
};

struct Enemy_GIANT{
    int GIANT_Hearts;
    int GIANT_Strength;
    int GIANT_Defense;

    Enemy_GIANT(){
            GIANT_Hearts = 3;
            GIANT_Strength = 2;
            GIANT_Defense = 2;
            
        }
        
};

void Enemy_print(const Enemy_RUNT enemy){
        
        cout << "Enemy Stats:" << endl;
        cout << "Enemy Health: " << enemy.Enemy_Hearts << endl;
        cout << "Enemy Strength" << enemy.Enemy_Strength << endl;
        cout << "Enemy_Defense: " << enemy.Enemy_Defense << endl;
    }


bool battle(Player player, Enemy_RUNT enemy) {
    cout << "you've encountered an enemy!" << endl;
    while (player.player_Hearts > 0 && enemy.Enemy_Hearts > 0) {
        
        
        int damage = player.player_strength - enemy.Enemy_Defense;
        if (damage > 0) {
            enemy.Enemy_Hearts -= damage;
            cout << "You deal " << damage << " damage to the enemy. Enemy health: " << enemy.Enemy_Hearts << endl;
        } else {
            cout << "Your attack does no damage." << endl;
        }
        if (enemy.Enemy_Hearts <= 0) {
            cout << "You defeated the enemy!" << endl;
            return true;
        }
        
        
        damage = enemy.Enemy_Strength - player.player_defense;
        if (damage > 0) {
            player.player_Hearts -= damage;
            cout << "Enemy deals " << damage << " damage to you. Your health: " << player.player_Hearts << endl;
        } else {
            cout << "Enemy's attack does no damage." << endl;
        }
        if (player.player_Hearts <= 0) {
            cout << "You were defeated! Game Over." << endl;
            return false;
        }
    }
    return false;
}

bool GIANT_battle(Player player, Enemy_GIANT enemy) {
    cout << "you've encountered an enemy!" << endl;
    while (player.player_Hearts > 0 && enemy.GIANT_Hearts > 0) {
        
        
        int damage = player.player_strength - enemy.GIANT_Defense;
        if (damage > 0) {
            enemy.GIANT_Hearts -= damage;
            cout << "You deal " << damage << " damage to the enemy. Enemy health: " << enemy.GIANT_Hearts << endl;
        } else {
            cout << "Your attack does no damage." << endl;
        }
        if (enemy.GIANT_Hearts <= 0) {
            cout << "You defeated the enemy!" << endl;
            return true;
        }
        
        
        damage = enemy.GIANT_Strength - player.player_defense;
        if (damage > 0) {
            player.player_Hearts -= damage;
            cout << "Enemy deals " << damage << " damage to you. Your health: " << player.player_Hearts << endl;
        } else {
            cout << "Enemy's attack does no damage." << endl;
        }
        if (player.player_Hearts <= 0) {
            cout << "You were defeated! Game Over." << endl;
            return false;
        }
    }
    return false;
}

bool Brute_battle(Player player, Enemy_Brute brute) {
    cout << "you've encountered an enemy!" << endl;
    while (player.player_Hearts > 0 && brute.Brute_Hearts > 0) {
        
        
        int damage = player.player_strength - brute.Brute_Defense;
        if (damage > 0) {
            brute.Brute_Hearts -= damage;
            cout << "You deal " << damage << " damage to the enemy. Enemy health: " << brute.Brute_Hearts << endl;
        } else {
            cout << "Your attack does no damage." << endl;
        }
        if (brute.Brute_Hearts <= 0) {
            cout << "You defeated the enemy!" << endl;
            return true;
        }
        
        
        damage = brute.Brute_Strength - player.player_defense;
        if (damage > 0) {
            player.player_Hearts -= damage;
            cout << "Enemy deals " << damage << " damage to you. Your health: " << player.player_Hearts << endl;
        } else {
            cout << "Enemy's attack does no damage." << endl;
        }
        if (player.player_Hearts <= 0) {
            cout << "You were defeated! Game Over." << endl;
            return false;
        }
    }
    return false;
}
//======================================================================================================================

class Dungeon {
    int rows, cols;
    vector<vector<int>> grid;
    
public:
    void display(){
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << grid[r][c] << "   ";
            }
            cout << endl;
        }
        
    }
};

const int ROWS = 5;
const int COLS = 5;

const int ROWS_2 = 8;
const int COLS_2 = 8;

// Function to print the grid
void print_Grid(char grid[ROWS][COLS]) {
    

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            cout << grid[r][c] << "   ";
        }
        cout << endl;
    }
}

void print_new_Grid(char grid[ROWS_2][COLS_2]) {
    

    for (int r = 0; r < ROWS_2; r++) {
        for (int c = 0; c < COLS_2; c++) {
            cout << grid[r][c] << "   ";
        }
        cout << endl;
    }
}


// Function to move the character
bool move_Character(char grid[ROWS][COLS], int& char_X, int& char_Y, string moveInput, Player& P) {
    
    int newX = char_X;
    int newY = char_Y;

    if (moveInput == "w" || moveInput == "Up" || moveInput == "up") newX--; // Up
    else if (moveInput == "s"|| moveInput == "Down" || moveInput == "down") newX++; // Down
    else if (moveInput == "a" || moveInput == "Left" || moveInput == "left") newY--; // Left
    else if (moveInput == "d" || moveInput == "Right" || moveInput == "right") newY++; // Right
    
    char target = grid[newX][newY];

    // Check boundaries
    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
        // Check if the new position is a barrier
        if (target == '#') {
            
            return false; // Cannot move, it's a barrier
            
        }
        else if(target == 'E'){
            Player p = Player("Henry");
            
            
            Enemy_RUNT E = Enemy_RUNT();
            battle(p, E);
            
        }
        
        else if(target == 'K'){
            P.keys++;
            grid[char_X][char_Y] = 'K';
            char_X = newX;
            char_Y = newY;
            grid[char_X][char_Y] = '$';
            grid[4][3] = '-';
            grid[3][4] = '-';
            //grid[4][4] = '-';
            return true;
        }
        
        else if(target == 'L'){
            
            if(P.keys > 0){
                P.keys--;
                grid[char_X][char_Y] = 'L';
                char_X = newX;
                char_Y = newY;
                grid[char_X][char_Y] = '$';
                grid[3][4] = '-';
                grid[2][3] = '-';
                 return true;
            }
            else{
                return false;
            }
        }
        
        else if(target == '!'){
            
            Player p = Player("Henry");
            
            Enemy_GIANT EG = Enemy_GIANT();
            GIANT_battle(p, EG);
            
            grid[char_X][char_Y] = '!';
            char_X = newX;
            char_Y = newY;
            grid[char_X][char_Y] = '$';
            grid[2][4] = '-';
            
            //key.pretty_print(key.get_hearts(), key.get_strength(), key.get_defense(), key.get_keys());
            return true;
        }
        
        else if(target == 'P'){
            P.player_strength += 5;
            P.player_defense += 5;
            grid[char_X][char_Y] = 'P';
            char_X = newX;
            char_Y = newY;
            grid[char_X][char_Y] = '$';
            grid[4][1] = '-';
            
            
            //key.pretty_print(key.get_hearts(), key.get_strength(), key.get_defense(), key.get_keys());
            return true;
        }
        
        grid[char_X][char_Y] = '-';
        char_X = newX;
        char_Y = newY;
        grid[char_X][char_Y] = '$'; // 'C' for Character

        return true; // Can move
    }
    return false; // Out of bounds
    // If movement is invalid, character stays in place
}

bool move_Character_new(char grid[ROWS_2][COLS_2], int& char_X, int& char_Y, string moveInput, Player& P) {
    
    int newX = char_X;
    int newY = char_Y;

    if (moveInput == "w" || moveInput == "Up" || moveInput == "up") newX--; // Up
    else if (moveInput == "s"|| moveInput == "Down" || moveInput == "down") newX++; // Down
    else if (moveInput == "a" || moveInput == "Left" || moveInput == "left") newY--; // Left
    else if (moveInput == "d" || moveInput == "Right" || moveInput == "right") newY++; // Right
    
    char target = grid[newX][newY];

    // Check boundaries
    if (newX >= 0 && newX < ROWS_2 && newY >= 0 && newY < COLS_2) {
        // Check if the new position is a barrier
        if (target == '#') {
            
            return false; // Cannot move, it's a barrier
            
        }
        else if(target == 'E'){
            
            
            
            Enemy_RUNT E = Enemy_RUNT();
            battle(P, E);
            
        }
        
        else if(target == 'K'){
            P.keys++;
            grid[char_X][char_Y] = 'K';
            char_X = newX;
            char_Y = newY;
            grid[char_X][char_Y] = '$';
            grid[6][3] = '-';
            grid[5][2] = '-';
            return true;
        }
        
        else if(target == 'L'){
            
            if(P.keys > 0){
                P.keys--;
                grid[char_X][char_Y] = 'L';
                char_X = newX;
                char_Y = newY;
                grid[char_X][char_Y] = '$';
                
                grid[2][4] = '-';
                 return true;
            }
            else{
                return false;
            }
        }
        
        else if(target == '!'){
            
            
            
            Enemy_GIANT EG = Enemy_GIANT();
            GIANT_battle(P, EG);
            
            grid[char_X][char_Y] = '!';
            char_X = newX;
            char_Y = newY;
            grid[char_X][char_Y] = '$';
            grid[2][4] = '-';
            
            return true;
        }
        
        else if(target == 'P'){
            P.player_strength += 5;
            P.player_defense += 5;
            grid[char_X][char_Y] = 'P';
            char_X = newX;
            char_Y = newY;
            grid[char_X][char_Y] = '$';
            grid[4][1] = '-';
        
            return true;
        }
        
        else if(target == 'B'){
            Enemy_Brute b = Enemy_Brute();
            Brute_battle(P, b);
            
            grid[char_X][char_Y] = 'B';
            char_X = newX;
            char_Y = newY;
            grid[char_X][char_Y] = '$';
            
            grid[4][2] = '-';
            grid[2][2] = '-';
            grid[1][1] = '-';
            grid[5][3] = '-';
            grid[6][4] = '-';
            
        }
        
        grid[char_X][char_Y] = '-';
        char_X = newX;
        char_Y = newY;
        grid[char_X][char_Y] = '$'; // 'C' for Character

        return true; // Can move
    }
    return false; // Out of bounds
    // If movement is invalid, character stays in place
}

void display_for_dungeon_creation(int r, int c){
    vector<vector<char>> grid (r, vector<char> (c, '-'));
    
    for (int i = 1; i <= r; i++){
        cout << "      " << i;
    }
    
    cout << endl;
    
    string dashes = string(r + 40, '-');
    
    cout << dashes << endl;
    
    //string letters = "";
    
    vector<char> row;
    
    char alphabet_start = '1';
    
    for (vector<char> row : grid) {
        cout << alphabet_start << '|';
        alphabet_start += 1;
        for (char c : row) {
            cout << "    " << c << "  " ;
        }
        cout << endl;
    }
}


void Designing_Dungeon(){

    cout << "Enter number of rows: ";
            int rows;
            cin >> rows;
            cout << "Enter number of columns: ";
            int cols;
            cin >> cols;
            cout << endl;
    
    bool editing = true;
    while (editing) {
        cout << endl;
        display_for_dungeon_creation(rows, cols);
        cout << endl;
        cout << "Actions:" << endl;
        cout << "1) Add object" << endl;
        cout << "2) Save dungeon" << endl;
        cout << "Select action: ";
        string action;
        cin >> action;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(action == "1" || action == "add object" || action == "Add object"){
            cout << "Objects:" << endl;
            cout << "1) Empty Space" << endl;
            cout << "2) Wall" << endl;
            cout << "3) Player" << endl;
            cout << "4) Goal" << endl;
            cout << "5) Key" << endl;
            cout << "6) Locked Door" << endl;
            cout << "7) Enemy" << endl;
            cout << "8) Health Potion" << endl;
            cout << "9) Strength Potion" << endl;
            cout << "10) Defense Potion" << endl;
            cout << "Choose what you want to place" << endl;

        }
        
        
    }
    
    
    


}


void enter_A_dungeon(){
    //================================================================ dungeon 1 beginning
    char grid[ROWS][COLS];
    
    for(int i = 0; i < ROWS; i++){
        for (int i2 = 0; i2 < COLS; i2++) {
            grid[i][i2] = '-';
        }
    }
    
    // Initial character position
    
    int playerX = 1;
    int playerY = 1;
    
    
    //to the right
    grid[playerX][playerY] = '$';
    grid[0][0] = '#';
    grid[0][1] = '#';
    grid[0][2] = '#';
    grid[0][3] = '#';
    grid[0][4] = 'G';
    //==============================
    //down
    grid[0][0] = '#';
    grid[1][0] = '#';
    grid[2][0] = '#';
    grid[3][0] = '#';
    grid[4][0] = 'P';
    //===============================
    
    grid[1][3] = '#';
    grid[2][4] = 'L';
    
    
    grid[3][2] = '#';
    grid[3][1] = '#';
    grid[2][3] = '-';
    grid[1][4] = '!';
    
    string userInput;
    
    grid[4][4] = 'K';
    
    grid[4][1] = 'E';
    
    //==========================================================================
    
    
    
    //cout << "=======================================" << endl;
    //print_Grid(grid);
    
    
    cout << endl;
    Player P = Player("Henry");
    //pretty_print_Player(P);
    cout << endl;
    while (true) {
        cout << "=================================" << endl;
        
        print_Grid(grid);
        pretty_print_Player(P);
        cout << "Enter move (w/a/s/d or q to quit): ";
        cin >> userInput;
        
        if (userInput == "q") {
            cout << "Exiting game." << endl;
            break;
        }
        
        move_Character(grid, playerX, playerY, userInput, P);
        //===========================================================================dungeon 1 end
        
        if(grid[playerX][playerY] == grid[0][4]){
            
            {//cout << "GAME END!" << endl;
                char new_grid[ROWS_2][COLS_2];
                
                for(int r = 0; r < ROWS_2; r++){
                    for (int r2 = 0; r2 < COLS_2; r2++) {
                        new_grid[r][r2] = '-';
                    }
                }
            
                int new_playerX = 7;
                int new_playerY = 0;
                
                new_grid[new_playerX][new_playerY] = '$';
                
                new_grid[3][0] = '#';
                new_grid[2][0] = '#';
                new_grid[1][0] = '#';
                new_grid[0][0] = '#';
                
                new_grid[7][1] = '#';
                new_grid[6][1] = '#';
                new_grid[5][1] = '#';
                
                new_grid[7][2] = '#';
                new_grid[7][3] = '#';
                new_grid[7][4] = '#';
                new_grid[7][5] = '#';
                new_grid[7][6] = '#';
                new_grid[7][7] = '#';
                
                new_grid[7][7] = '#';
                new_grid[6][7] = '#';
                new_grid[5][7] = '#';
                new_grid[4][7] = '#';
                new_grid[3][7] = '#';
                new_grid[2][7] = '#';
                
                new_grid[1][7] = '#';
                new_grid[0][7] = '#';
                
                new_grid[0][1] = '#';
                new_grid[0][2] = '#';
                new_grid[0][3] = '#';
                new_grid[0][4] = 'G';
                new_grid[1][4] = 'L';
                new_grid[0][5] = '#';
                new_grid[0][6] = '#';
                
                new_grid[6][2] = 'K';
                
                new_grid[1][3] = '#';
                new_grid[1][5] = '#';
                new_grid[2][3] = '#';
                new_grid[2][5] = '#';
                
                new_grid[6][3] = 'B';
                new_grid[5][2] = 'B';
                
                
                
                //print_new_Grid(new_grid);
                //pretty_print_Player(P);
                
                while (true) {
                    cout << "=================================" << endl;
                    
                    print_new_Grid(new_grid);
                    pretty_print_Player(P);
                    cout << "Enter move (w/a/s/d or q to quit): ";
                    cin >> userInput;
                    
                    if (userInput == "q") {
                        cout << "Exiting game." << endl;
                        break;
                    }
                    
                    move_Character_new(new_grid, new_playerX, new_playerY, userInput, P);
                    
                    if(new_grid[new_playerX][new_playerY] = new_grid[0][4]){
                        cout << "GAME END!" << endl;
                        break;
                    }
                }//new grid playing
            }
        }
    }
}


int main() {
    
    srand(time(nullptr));
    
    vector<Dungeon>
    
    bool loop_error = false;
    string choice;
    //string choice;
    
    do {
        cout << "Welcome to Magic Tower: Revenge of the Warlock Part VII" << endl;
         
        cout << "1) Enter a dungeon" << endl;
        cout << "2) Design a dungeon" << endl;
        cout << "3) Exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;
        
        
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        loop_error = false;
        cout << "invalid input!" << endl;
        cout << endl;
    }
    //use 0-4
    else if(choice == "1" || choice == "Enter a dungeon" || choice == "enter a dungeon"){
        loop_error = false;
        cout << endl;
        
        bool loop_error2 = false;
        do {
            string choice2;
                    
            cout << "Choose the type of dungeon:" << endl;
            
            cout << "1) regular dungeon" << endl;
            cout << "2) tutorial dungeon" << endl;
            
            cout << "enter your choice (in number): ";
            cin >> choice2;
            
            cout << endl;
            
            if(cin.fail() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop_error2 = true;
                cout << "invalid input!" << endl;
                cout << endl;
            }
            
            else if (choice2 == "1" || choice2 == "regular dungeon"){
                loop_error2 = true;
                cout << endl;
                enter_A_dungeon();
            }
                
            else if (choice2 == "2" || choice2 == "tutorial dungeon"){
                cout << "still working on it" << endl;
                loop_error2 = false;
                cout << endl;
                
            }
            
        } while (!loop_error2);
        
    }
        
    else if (choice == "2" || choice == "Design a dungeon" || choice == "design a dungeon"){
        
        //cout << "NOT WORKING!" << endl;
        loop_error = false;
        Designing_Dungeon();
        cout << endl;
    }
        
    else if (choice == "3" || choice == "exit" || choice == "Exit"){
        loop_error = true;
        cout << endl;
        return 0;
        }
        
    } while (!loop_error);
    //char talking = 34;
    return 0;
    //cout << talking << endl;
    
}
