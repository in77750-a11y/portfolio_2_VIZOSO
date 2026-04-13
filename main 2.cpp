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
        cout << "Stats: " << endl;
        cout << "Hearts: " << p.player_Hearts << endl;
        cout << "Strength: " << p.player_strength << endl;
        cout << "defense: " << p.player_defense << endl;
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



//// Function to get object symbol
//char getObjectSymbol(int choice) {
//    switch (choice) {
//        case 1: return ' ';
//        case 2: return '#';
//        case 3: return '@';
//        case 4: return 'G';
//        case 5: return 'W';
//        case 6: return 'J';
//        case 7: return 'E';
//        case 8: return 'H';
//        case 9: return 'P';
//        case 10: return 'F';
//        case 11: return 'T';
//        default: return ' ';
//    }
//}

class creating_Dungeon {
private:
    string dungeon_name;
    int c_dun_ROW;
    int c_dun_COL;
    vector<vector<char>> creating_grid;
    vector<pair<pair<int, int>, pair<int, int>>> teleporters;
public:
    
    void displayEditorGrid(const vector<vector<char>>& grid, int rows, int cols) {
        cout << "  ";
        for (int c = 1; c <= cols; ++c) {
            cout << c << " ";
        }
        cout << endl;
        for (int r = 0; r < rows; ++r) {
            cout << (r + 1) << " ";
            for (int c = 0; c < cols; ++c) {
                cout << grid[r][c] << " - ";
            }
            cout << endl;
        }
    }
    
};

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

//======================================================================================================================

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
bool move_Character(char grid[ROWS][COLS], int& char_X, int& char_Y, char moveInput, Player& P) {
    
    int newX = char_X;
    int newY = char_Y;

    if (moveInput == 'w' || moveInput == 'U') newX--; // Up
    else if (moveInput == 's'|| moveInput == 'D') newX++; // Down
    else if (moveInput == 'a' || moveInput == 'L') newY--; // Left
    else if (moveInput == 'd' || moveInput == 'R') newY++; // Right
    
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

bool move_Character_new(char grid[ROWS_2][COLS_2], int& char_X, int& char_Y, char moveInput, Player& P) {
    
    int newX = char_X;
    int newY = char_Y;

    if (moveInput == 'w' || moveInput == 'U') newX--; // Up
    else if (moveInput == 's'|| moveInput == 'D') newX++; // Down
    else if (moveInput == 'a' || moveInput == 'L') newY--; // Left
    else if (moveInput == 'd' || moveInput == 'R') newY++; // Right
    
    char target = grid[newX][newY];

    // Check boundaries
    if (newX >= 0 && newX < ROWS_2 && newY >= 0 && newY < COLS_2) {
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


void Designing_Dungeon(){

//    cout << "Enter number of rows: ";
//            int rows;
//            cin >> rows;
//            cout << "Enter number of columns: ";
//            int cols;
//            cin >> cols;
//    vector<vector<char>> grid(rows, vector<char>(cols, '-'));
//    
//    creating_Dungeon dung;
//
//    bool editing = true;
//    while (editing) {
//        cout << endl;
//        dung.displayEditorGrid(grid, rows, cols);
//        cout << endl;
//        cout << "Actions:" << endl;
//        cout << "1) Add object" << endl;
//        cout << "2) Save dungeon" << endl;
//        cout << "Select action: ";
//        int action;
//        cin >> action;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        
//        if (action == 1) {
//            cout << "Objects:" << endl;
//            cout << "1) Empty Space" << endl;
//            cout << "2) Wall" << endl;
//            cout << "3) Player" << endl;
//            cout << "4) Goal" << endl;
//            cout << "5) Key" << endl;
//            cout << "6) Locked Door" << endl;
//            cout << "7) Enemy" << endl;
//            cout << "8) Health Potion" << endl;
//            cout << "9) Strength Potion" << endl;
//            cout << "10) Defense Potion" << endl;
//            //cout << "11) Teleporter" << endl;
//            cout << "Select object by number or name: ";
//            string objInput;
//            getline(cin, objInput);
//            
//            int objChoice = 0;
//            if (objInput == "1" || objInput == "Empty Space") {
//                objChoice = 1;
//            }
//            else if (objInput == "2" || objInput == "Wall") {
//                objChoice = 2;
//            }
//            else if (objInput == "3" || objInput == "Player") {
//                objChoice = 3;
//            }
//            else if (objInput == "4" || objInput == "Goal") {
//                objChoice = 4;
//            }
//            else if (objInput == "5" || objInput == "Key") {
//                objChoice = 5;
//            }
//            else if (objInput == "6" || objInput == "Locked Door") {
//                objChoice = 6;
//            }
//            else if (objInput == "7" || objInput == "Enemy") {
//                objChoice = 7;
//            }
//            else if (objInput == "8" || objInput == "Health Potion") {
//                objChoice = 8;
//            }
//            else if (objInput == "9" || objInput == "Strength Potion") {
//                objChoice = 9;}
//            else if (objInput == "10" || objInput == "Defense Potion") objChoice = 10;
////            else if (objInput == "11" || objInput == "Teleporter") objChoice = 11;
//            else {
//                cout << "Invalid object." << endl;
//                continue;
//            }
//            
////            if (objChoice == 11) {
////                // Place first teleporter
////                cout << "Enter row and column for first teleporter (1-based): ";
////                int r1, c1;
////                cin >> r1 >> c1;
////                cin.ignore(numeric_limits<streamsize>::max(), '\n');
////                if (r1 < 1 || r1 > rows || c1 < 1 || c1 > cols) {
////                    cout << "Invalid coordinates." << endl;
////                    continue;
////                }
////                grid[r1 - 1][c1 - 1] = 'T';
////                
////                // Place second teleporter
////                cout << "Enter row and column for second teleporter (1-based): ";
////                int r2, c2;
////                cin >> r2 >> c2;
////                cin.ignore(numeric_limits<streamsize>::max(), '\n');
////                if (r2 < 1 || r2 > rows || c2 < 1 || c2 > cols) {
////                    cout << "Invalid coordinates." << endl;
////                    // Remove first if invalid
////                    grid[r1 - 1][c1 - 1] = ' ';
////                    continue;
////                }
////                grid[r2 - 1][c2 - 1] = 'T';
////                teleporters.push_back({{r1 - 1, c1 - 1}, {r2 - 1, c2 - 1}});
//            //}
//        //else {
////                cout << "Enter row and column (1-based): ";
////                int r, c;
////                cin >> r >> c;
////                cin.ignore(numeric_limits<streamsize>::max(), '\n');
////                if (r < 1 || r > rows || c < 1 || c > cols) {
////                    cout << "Invalid coordinates." << endl;
////                    continue;
////                }
////                grid[r - 1][c - 1] = getObjectSymbol(objChoice);
//            //}
//        } else if (action == 2) {
//            cout << "Enter dungeon name: ";
//            string name;
//            getline(cin, name);
//            //creating_Dungeon newDungeon = {name, rows, cols, grid, teleporters};
//            //dungeons.push_back(newDungeon);
//            cout << "Dungeon saved!" << endl;
//            editing = false;
//        } else {
//            cout << "Invalid action." << endl;
//        }
//    }
}


void enter_A_dungeon(){
    
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
    
    char userInput;
    
    grid[4][4] = 'K';
    
    grid[4][1] = 'E';
    
    //==========================================================================
    
    
    
    cout << "=======================================" << endl;
    print_Grid(grid);
    
    
    cout << endl;
    Player P = Player("Henry");
    pretty_print_Player(P);
    cout << endl;
    while (true) {
        cout << "=================================" << endl;
        
        print_Grid(grid);
        pretty_print_Player(P);
        cout << "Enter move (w/a/s/d or q to quit): ";
        cin >> userInput;
        
        if (userInput == 'q') {
            cout << "Exiting game." << endl;
            break;
        }
        
        
        
        move_Character(grid, playerX, playerY, userInput, P);
        
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
                
                
                print_new_Grid(new_grid);
                pretty_print_Player(P);
                
                while (true) {
                    cout << "=================================" << endl;
                    
                    print_new_Grid(new_grid);
                    pretty_print_Player(P);
                    cout << "Enter move (w/a/s/d or q to quit): ";
                    cin >> userInput;
                    
                    if (userInput == 'q') {
                        cout << "Exiting game." << endl;
                        break;
                    }
                    
                    move_Character_new(new_grid, new_playerX, new_playerY, userInput, P);
                }
            }
        }
    }
}


int main() {
    
    srand(time(nullptr));
    
    
    
    bool loop_error = false;
    int choice;
    //string choice;
    
    do {
        cout << "Welcome to Magic Tower: Revenge of the Warlock Part VII" << endl;
         
        cout << "1) Enter a dungeon" << endl;
        cout << "2) Design a dungeon" << endl;
        cout << "3) Exit" << endl;
        cout << "enter your choice (in number): ";
        cin >> choice;
        
        
    if(cin.fail() || choice > 3 || choice < 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        loop_error = false;
        cout << "invalid input!" << endl;
        cout << endl;
    }
    //use 0-4
    else if(choice == 1){
        loop_error = false;
        cout << endl;
        
        bool loop_error2 = false;
        do {
            int choice2;
                    
            cout << "Choose the type of dungeon:" << endl;
            
            cout << "1) regular dungeon" << endl;
            cout << "2) tutorial dungeon" << endl;
            
            cout << "enter your choice (in number): ";
            cin >> choice2;
            
            
            if(cin.fail() || choice2 > 2 || choice2 < 1){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop_error2 = true;
                cout << "invalid input!" << endl;
                cout << endl;
            }
            
            else if (choice2 == 1){
                loop_error2 = false;
                cout << endl;
                enter_A_dungeon();
            }
                
            else if (choice2 == 2){
                loop_error2 = false;
                cout << endl;
                return 0;
            }
            
        } while (loop_error2);
        
    }
        
    else if (choice == 2){
        
        cout << "NOT WORKING!";
        loop_error = false;
        //Designing_Dungeon();
        cout << endl;
    }
        
    else if (choice == 3){
        loop_error = true;
        cout << endl;
        return 0;
    }
    } while (!loop_error);
    //char talking = 34;
    return 0;
    //cout << talking << endl;
    
}
