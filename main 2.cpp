//
//  main.cpp
//  GRID prototype 2
//
//  Created by Andres Vizoso on 4/16/26.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

class Player {
public:
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
    
    int get_keys(){
        return keys;
    }
    
    int get_player_Hearts(){
        return player_Hearts;
    }
    
    int get_player_defense(){
        return player_defense;
    }
    
    int get_player_strength(){
        return player_strength;
    }
    
    void pretty_print_Player(){
            cout << "Meet your Wizard: " << name << endl;
            cout << "Stats: " << endl;
            cout << "Hearts: " << player_Hearts;
            cout << "   Strength: " << player_strength;
            cout << "   Defense: " << player_defense;
            cout << "   Keys: " << keys << endl;
            //cout << "potion of Health: ";
            
        }
    
    
};

class Enemy_RUNT {
    
    
public:
    
    int Enemy_Hearts;
    int Enemy_Strength;
    int Enemy_Defense;
    
    Enemy_RUNT(){
        Enemy_Hearts = 1;
        Enemy_Strength = 1;
        Enemy_Defense = 1;
        
    }
};

class Enemy_GIANT {
    
    
public:
    int GIANT_Hearts;
    int GIANT_Strength;
    int GIANT_Defense;

    Enemy_GIANT(){
            GIANT_Hearts = 3;
            GIANT_Strength = 3;
        GIANT_Defense = 3;
            
        }
};
    
class Enemy_Brute{
public:
        int Brute_Hearts;
        int Brute_Strength;
        int Brute_Defense;

        Enemy_Brute(){
                Brute_Hearts = 3;
                Brute_Strength = 2;
                Brute_Defense = 2;
                
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
    while (player.get_player_Hearts() > 0 && enemy.Enemy_Hearts > 0) {
        
        
        int damage = player.get_player_strength() - enemy.Enemy_Defense;
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
        
        
        damage = enemy.Enemy_Strength - player.get_player_defense();
        if (damage > 0) {
            int player_hearts = player.get_player_Hearts();
            player_hearts -= damage;
            cout << "Enemy deals " << damage << " damage to you. Your health: " << player.get_player_Hearts() << endl;
        } else {
            cout << "Enemy's attack does no damage." << endl;
        }
        if (player.get_player_Hearts() <= 0) {
            cout << "You were defeated! Game Over." << endl;
            return false;
        }
    }
    return false;
}

bool GIANT_battle(Player player, Enemy_GIANT enemy) {
    cout << "you've encountered an enemy!" << endl;
    while (player.get_player_Hearts() > 0 && enemy.GIANT_Hearts > 0) {
        
        
        int damage = player.get_player_strength() - enemy.GIANT_Defense;
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
        
        
        damage = enemy.GIANT_Strength - player.get_player_defense();
        if (damage > 0) {
            int player_hearts = player.get_player_Hearts();
            player_hearts -= damage;
            cout << "Enemy deals " << damage << " damage to you. Your health: " << player.get_player_Hearts() << endl;
        } else {
            cout << "Enemy's attack does no damage." << endl;
        }
        if (player.get_player_Hearts() <= 0) {
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



class GridGame {
private:
    string name;
    int rows, cols;
    int playerX, playerY;
    vector<vector<char>> grid;

public:
    
    Player P = Player("Henry");
    Enemy_RUNT E;
    Enemy_GIANT EG;
    Enemy_Brute B;
    
    GridGame(int r, int c, string n, int player_place_X, int player_place_Y) {
        rows = r;
        cols = c;
        playerX = player_place_X;
        playerY = player_place_Y;
        name = n;
        grid = vector<vector<char>>(r, vector<char>(c, '-'));
    }
    
    GridGame() {
        
    }
    
    int get_playerX(){
        return playerX;
    }
    
    int get_playerY(){
        return playerY;
    }
    
    string get_Name(){
        return name;
    }
    
    int get_rows(){
        return rows;
    }
    
    int get_cols(){
        return cols;
    }
    
    char get_player_placement() {
        return grid[playerY][playerX];
    }
    
    char get_tile(int r, int c){
        return grid[r][c];
    }
    
    void set_name(const string& n){
        name = n;
    }
    
    void setTile(int r, int c, char type) {
        grid[r][c] = type;
    }
    
    
    Player get_Player_P(){
        return P;
    }
    
    bool move(char direction, string move_choice) {
            int nextX = playerX, nextY = playerY;
        
        if (move_choice == "1" || move_choice == "WASD" || move_choice == "wasd") {
            if (direction == 'w') nextY--;      // Up
                else if (direction == 's') nextY++; // Down
                else if (direction == 'a') nextX--; // Left
                else if (direction == 'd') nextX++; // Right
                else return false; // Invalid input
        }
        
        else if (move_choice == "2" || move_choice == "LRUP" || move_choice == "lrup"){
            if (direction == 'u' || direction == 'U') nextY--;      // Up
                else if (direction == 'd' || direction == 'D') nextY++; // Down
                else if (direction == 'l' || direction == 'L') nextX--; // Left
                else if (direction == 'r' || direction == 'R') nextX++; // Right
                else return false; // Invalid input
        }

            // Determine new potential coordinates
            
        
        if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols) {
            
            if (grid[nextY][nextX] == '#'){
              
            return false;
        }
            
            if(grid[nextY][nextX] == 'E'){
                battle(P, E);
                
            }
            
            if(grid[nextY][nextX] == 'K'){
                P.keys++;
                cout << "Collect one key." << endl;
                
                grid[playerY][playerX] = '-';
                        playerX = nextX;
                        playerY = nextY;
                grid[playerY][playerX] = '$';
                return true;
            }
            
            if(grid[nextY][nextX] == 'L'){
                
                if(P.keys > 0){
                    P.keys--;
                    grid[playerY][playerX] = '-';
                    playerX = nextX;
                    playerY = nextY;
                    grid[playerY][playerX] = '$';
                    
                     return true;
                }
                else{
                    return false;
                }
            }
            
            if(grid[nextY][nextX] == '!'){
            
                GIANT_battle(P, EG);
                
                grid[playerY][playerX] = '-';
                playerX = nextX;
                playerY = nextY;
                grid[playerY][playerX] = '$';
                
                
                return true;
            }
            
            if(grid[nextY][nextX] == 'P'){
                P.player_strength += 5;
                P.player_defense += 5;
                grid[playerY][playerX] = '-';
                playerX = nextX;
                playerY = nextY;
                grid[playerY][playerX] = '$';
                
                return true;
            }
            
            if(grid[nextY][nextX] == 'B'){
                
                Brute_battle(P, B);
                
                grid[playerY][playerX] = '-';
                playerX = nextX;
                playerY = nextY;
                grid[playerY][playerX] = '$';
    
            }
            
            if(grid[nextY][nextX] == 'H'){
                P.player_Hearts += 5;
                Brute_battle(P, B);
                
                grid[playerY][playerX] = '-';
                playerX = nextX;
                playerY = nextY;
                grid[playerY][playerX] = '$';
    
            }
            
            if(grid[nextY][nextX] == 'S'){
                P.player_strength += 5;
                Brute_battle(P, B);
                
                grid[playerY][playerX] = '-';
                playerX = nextX;
                playerY = nextY;
                grid[playerY][playerX] = '$';
    
            }
            
            if(grid[nextY][nextX] == 'D'){
                P.player_defense += 5;
                Brute_battle(P, B);
                
                grid[playerY][playerX] = '-';
                playerX = nextX;
                playerY = nextY;
                grid[playerY][playerX] = '$';
    
            }
            
            if(grid[nextY][nextX] == 'G'){
                cout << "GAME OVER!" << endl;
                grid[playerY][playerX] = '-';
                playerX = nextX;
                playerY = nextY;
                grid[playerY][playerX] = 'G';
                return true;
            }
            
            grid[playerY][playerX] = '-';  // Clear old position
            playerX = nextX;
            playerY = nextY;
            grid[playerY][playerX] = '$';
            
        }//barrier
            return false; // Move out of bounds
    }
    
    
    void display_for_normal() {
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << grid[r][c] << "   ";
            }
            cout << endl;
        }// grid
    }

    
    void display_for_dungeon_creation(){
        
        
        for (int i = 0; i < rows; i++){
            cout << "      " << i;
        }
        
        cout << endl;
        
        string dashes = string(rows + 45, '-');
        
        cout << dashes << endl;
        
        vector<char> cols;
        
        char alphabet_start = '0';
        
        for (vector<char> cols : grid) {
            cout << alphabet_start << '|';
            alphabet_start += 1;
            for (char c : cols) {
                cout << "    " << c << "  " ;
            }
            cout << endl;
        }
    }
    
    
};

GridGame initialization_for_1(){
    GridGame dungeon_1 = GridGame(5, 5, "Dungeon 1", 1, 1);
    dungeon_1.setTile(dungeon_1.get_playerX(), dungeon_1.get_playerY(), '$');
    
    
    dungeon_1.setTile(0, 0, '#');
    dungeon_1.setTile(0, 1, '#');
    dungeon_1.setTile(0, 2, '#');
    dungeon_1.setTile(0, 3, '#');
    dungeon_1.setTile(0, 4, 'G');
    
    dungeon_1.setTile(0, 0, '#');
    dungeon_1.setTile(1, 0, '#');
    dungeon_1.setTile(2, 0, '#');
    dungeon_1.setTile(3, 0, '#');
    dungeon_1.setTile(4, 0, 'P');
    
    dungeon_1.setTile(1, 3, '#');
    dungeon_1.setTile(2, 4, 'L');
    
    dungeon_1.setTile(3, 2, '#');
    dungeon_1.setTile(3, 1, '#');
    
    dungeon_1.setTile(2, 3, '-');
    dungeon_1.setTile(1, 4, '!');
    
    dungeon_1.setTile(4, 4, 'K');
    dungeon_1.setTile(4, 1, 'E');
    
    
    return dungeon_1;
}

GridGame initialization_for_Tutorial(){
    GridGame tutorial = GridGame(7, 7, "Tutorial", 1, 1);
    tutorial.setTile(tutorial.get_playerX(), tutorial.get_playerY(), '$');
    
    tutorial.setTile(0, 0, '#');
    tutorial.setTile(0, 1, '#');
    tutorial.setTile(0, 2, '#');
    tutorial.setTile(0, 3, '#');
    tutorial.setTile(0, 0, 'G');
    
    tutorial.setTile(0, 0, '#');
    tutorial.setTile(1, 0, '#');
    tutorial.setTile(2, 0, '#');
    tutorial.setTile(3, 0, '#');
    tutorial.setTile(4, 0, 'P');
    
    tutorial.setTile(1, 3, '#');
    tutorial.setTile(2, 4, 'L');
    
    tutorial.setTile(3, 2, '#');
    tutorial.setTile(3, 1, '#');
    
    tutorial.setTile(2, 3, '-');
    tutorial.setTile(1, 4, '!');
    
    tutorial.setTile(4, 4, 'K');
    tutorial.setTile(4, 1, 'E');
    
    tutorial.setTile(5, 5, 'B');
    

    return tutorial;
}

void playing_dungeon(GridGame g, string moving_choice){
    

    char userInput;
    
    
    bool playing = true;
    while (playing) {
        cout << "=================================" << endl;
//        cout << g.get_playerX() << endl;
//        cout << g. get_playerY() << endl;
//        cout << g.get_player_placement() << endl;
//        cout << g.get_tile(0,4) << endl;
//        cout << endl;
        
                g.display_for_normal();
        g.get_Player_P().pretty_print_Player();
        
        if(moving_choice == "1" || moving_choice == "WASD" || moving_choice == "wasd"){
            cout << "Enter move (w/a/s/d or q to quit): ";
        }
        
        else if(moving_choice == "2" || moving_choice == "LRUP" || moving_choice == "lrup"){
            cout << "Enter move (U/D/L/R or q to quit): ";
        }
        
        cin >> userInput;
        if (userInput == 'q' || userInput == 'Q') {
            cout << "Exiting game." << endl;
            break;
        }
        
        g.move(userInput, moving_choice);
        
        if(g.get_player_placement() == 'G'){
            
            playing = false;
        }
        

    }
    
}
    
    void doing_the_tutorial(GridGame T, string moving_choice){
        
        char userInput;
        
        cout << "=================================" << endl;
        T.display_for_normal();
        T.get_Player_P().pretty_print_Player();
        cout << endl;
        cout << "this is how the board will look like when you choose a dungeon to play" << endl;
        cout << endl;
        cout << endl;
        this_thread::sleep_for(chrono::seconds(5));
        
        if(moving_choice == "1" || moving_choice == "WASD" || moving_choice == "wasd"){
            cout << "Enter move (w/a/s/d or q to quit): ";
            cout << "this is how your input will be for moving the player if you choose wasd" << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << endl;
            cout << "try it: " << endl;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Enter move (w/a/s/d or q to quit): ";
        }
        
        else if(moving_choice == "2" || moving_choice == "LRUP" || moving_choice == "lrup"){
            cout << "Enter move (U/D/L/R or q to quit): ";
            cout << "this is how your input will be for moving the player if you choose wasd" << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << endl;
            cout << "try it: " << endl;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Enter move (U/D/L/R or q to quit): ";
        }
        
        cin >> userInput;
        if (userInput == 'q' || userInput == 'Q') {
            cout << "Exiting game." << endl;
            cout << "This will pop up if you decide to quit, but you still need to know a few things!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
        
        T.move(userInput, moving_choice);
        cout << "=================================" << endl;
        T.display_for_normal();
        T.get_Player_P().pretty_print_Player();
        this_thread::sleep_for(chrono::seconds(2));
        cout << endl;
        cout << "Good job, looks like your getting the hang of it, now here are what the symbols mean on the board:" << endl;
        cout << endl;
        this_thread::sleep_for(chrono::seconds(2));
        
        cout << "#: Wall" << endl;
        cout << "$: Player" << endl;
        cout << "P: Potion that increases strength and defense" << endl;
        cout << "L: Locked door" << endl;
        cout << "K: Key" << endl;
        cout << "E: Enemy" << endl;
        cout << "G: Goal" << endl;
        cout << "!: Giant" << endl;
        cout << "B: Brute" << endl;
        cout << "H: Potion of Health" << endl;
        cout << "S: Potion of Strenght" << endl;
        cout << "D: Potion of Defense" << endl;
        cout << endl;
        cout << "Take your time to memorize what the symbols mean." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        
        cout << endl;
        cout << "Look like you got the hand of it so far, now try it out!" << endl;
        
    }

GridGame editing_dungeon(GridGame Updating_grid){
    
    //Updating_grid.display_for_dungeon_creation();
    bool loop_updating = false;
    bool editing = true;
    while(editing){
        cout << endl;
        Updating_grid.display_for_dungeon_creation();
        cout << endl;
        cout << "Actions:" << endl;
        cout << "1) Add object" << endl;
        cout << "2) Save dungeon" << endl;
        cout << "Select action: ";
        string action;
        getline(cin, action);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(cin.fail() && action != "1" && action != "Add object" && action != "add object" && action != "2" && action != "Save dungeon" && action != "save dungeon"){
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loop_updating = false;
            cout << "invalid input!" << endl;
            cout << endl;
        }
        
        else if(action == "1" || action == "Add object" || action == "add object"){
            
            char object_choosen;
            do {
            cout << endl;
            cout << "Choose what to add for the dungeon:" << endl;
            cout << "1) Empty Space" << endl;
            cout << "2) Wall" << endl;
            cout << "3) Goal" << endl;
            cout << "4) Key" << endl;
            cout << "5) Locked Door" << endl;
            cout << "7) Enemy" << endl;
            cout << "8) Health Potion" << endl;
            cout << "9) Strength Potion" << endl;
            cout << "9) Defense Potion" << endl;
            cout << "Select object by number or name: ";
            string choice;
            getline(cin, choice);
            
            
                if (choice == "1" || choice == "Empty Space"){
                    loop_updating = true;
                    object_choosen = '-';
                }
                else if (choice == "2" || choice == "Wall"){
                    loop_updating = true;
                    object_choosen = '#';
                }
                else if (choice == "3" || choice == "Goal"){
                    loop_updating = true;
                    object_choosen = 'G';
                }
                else if (choice == "4" || choice == "Key"){
                    loop_updating = true;
                    object_choosen = 'K';
                }
                else if (choice == "5" || choice == "Locked Door"){
                    loop_updating = true;
                    object_choosen = 'L';
                }
                else if (choice == "6" || choice == "Enemy"){
                    loop_updating = true;
                    object_choosen = 'E';
                }
                else if (choice == "7" || choice == "Health Potion"){
                    loop_updating = true;
                    object_choosen = 'H';
                }
                else if (choice == "8" || choice == "Strength Potion"){
                    loop_updating = true;
                    object_choosen = 'S';
                }
                else if (choice == "9" || choice == "Defense Potion") {
                    loop_updating = true;
                    object_choosen = 'D';
                }
            else {
                loop_updating = false;
                cout << "Invalid object." << endl;
            }
                
        }while(!loop_updating);
            
            do {
                cout << "Enter the coordinates in (x,y) format: ";
                int x, y;
                char parenth1_for_obj_choosen = '(';
                char parenth2_for_obj_choosen = ')';
                char comma_for_obj_choosen = ',';
                cin >> parenth1_for_obj_choosen >> x >> comma_for_obj_choosen >> y >> parenth2_for_obj_choosen;
                
                if(cin.fail() || x < 0 || y < 0 || x > Updating_grid.get_rows() || y > Updating_grid.get_cols() || parenth1_for_obj_choosen != '(' || parenth2_for_obj_choosen != ')' || comma_for_obj_choosen != ','){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    loop_updating = false;
                    cout << "Invalid coordinates!" << endl;
                    cout << endl;
                }
                else{
                    loop_updating = true;
                Updating_grid.setTile(x, y, object_choosen);
                }
            } while (!loop_updating);

        }
    
        else if (action == "2" || action == "Save dungeon" || action == "save dungeon"){
            
            cout << "Enter dungeon name: ";
            string name;
            getline(cin, name);
            Updating_grid.set_name(name);
            editing = false;
        }
        
    }
    
    return Updating_grid;
}

GridGame creating_a_dungeon(){
    
    int rows_C, cols_C;
    bool loop = false;
    do {
        
        cout << endl;
        cout << "Enter colums: ";
        cin >> rows_C;
        
        if (cin.fail() || rows_C < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loop = false;
            cout << "\nInvalid row. Please enter an integer" << endl;
        }
        else {
            loop = true;
        }
    } while (!loop);
        
    
        cout << endl;
        cout << endl;
        
    do {
        cout << "Enter rows: ";
        cin >> cols_C;

        if (cin.fail()|| cols_C < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loop = false;
            cout << "\nInvalid column. Please enter an integer" << endl;
        }
        else {
            loop = true;
        }
    } while (!loop);
        
    cout << endl;
    cout << endl;
    
    

    int p_x, p_y;
    do {
        cout << "Enter the coordinates in (x,y) format (along with parenthesis) for your player: ";
        char parenth1 = '(';
        char parenth2 = ')';
        char comma = ',';
        cin >> parenth1 >> p_x >> comma >> p_y >> parenth2;
        
        if (cin.fail() || p_x < 0 || p_y < 0 || p_x > rows_C || p_y > cols_C || parenth1 != '(' || parenth2 != ')' || comma != ',') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loop = false;
            cout << "\nInvalid column. Please enter an integer" << endl;
        }
        else {
            loop = true;
            
        }
    } while (!loop);
    
    
    GridGame creating_dungeon = GridGame(rows_C, cols_C, "Custom", p_x, p_y);
    creating_dungeon.setTile(p_x, p_y, '$');
    
    bool editing = true;
    string action;
    while(editing){
        cout << endl;
        creating_dungeon.display_for_dungeon_creation();
        cout << endl;
        cout << "Actions:" << endl;
        cout << "1) Add object" << endl;
        cout << "2) Save dungeon" << endl;
        cout << "Select action: ";
        
        getline(cin, action);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(cin.fail() && action != "1" && action != "Add object" && action != "add object" && action != "2" && action != "Save dungeon" && action != "save dungeon"){
            cin.clear();
            loop = false;
            cout << "invalid input!" << endl;
            cout << endl;
        }
        
        else if(action == "1" || action == "Add object" || action == "add object"){
            
            char object_choosen;
            do {
            cout << endl;
            cout << "Choose what to add for the dungeon:" << endl;
            cout << "1) Empty Space" << endl;
            cout << "2) Wall" << endl;
            cout << "3) Goal" << endl;
            cout << "4) Key" << endl;
            cout << "5) Locked Door" << endl;
            cout << "7) Enemy" << endl;
            cout << "8) Health Potion" << endl;
            cout << "9) Strength Potion" << endl;
            cout << "9) Defense Potion" << endl;
            cout << "Select object by number or name: ";
            string choice;
            getline(cin, choice);
            
            
                if (choice == "1" || choice == "Empty Space"){
                    loop = true;
                    object_choosen = '-';
                }
                else if (choice == "2" || choice == "Wall"){
                    loop = true;
                    object_choosen = '#';
                }
                else if (choice == "3" || choice == "Goal"){
                    loop = true;
                    object_choosen = 'G';
                }
                else if (choice == "4" || choice == "Key"){
                    loop = true;
                    object_choosen = 'K';
                }
                else if (choice == "5" || choice == "Locked Door"){
                    loop = true;
                    object_choosen = 'L';
                }
                else if (choice == "6" || choice == "Enemy"){
                    loop = true;
                    object_choosen = 'E';
                }
                else if (choice == "7" || choice == "Health Potion"){
                    loop = true;
                    object_choosen = 'H';
                }
                else if (choice == "8" || choice == "Strength Potion"){
                    loop = true;
                    object_choosen = 'S';
                }
                else if (choice == "9" || choice == "Defense Potion") {
                    loop = true;
                    object_choosen = 'D';
                }
                
            else {
                loop = false;
                cout << "Invalid object." << endl;
            }
                
        }while(!loop);
            
            do {
                cout << "Enter the coordinates in (x,y) format: ";
                int x, y;
                char parenth1_for_obj_choosen = '(';
                char parenth2_for_obj_choosen = ')';
                char comma_for_obj_choosen = ',';
                cin >> parenth1_for_obj_choosen >> x >> comma_for_obj_choosen >> y >> parenth2_for_obj_choosen;
                
                if(cin.fail() || x < 0 || y < 0 || x > rows_C || y > cols_C || parenth1_for_obj_choosen != '(' || parenth2_for_obj_choosen != ')' || comma_for_obj_choosen != ','){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    loop = false;
                    cout << "Invalid coordinates!" << endl;
                    cout << endl;
                }
                else{
                    loop = true;
                creating_dungeon.setTile(x, y, object_choosen);
                }
            } while (!loop);

        }
    
        else if (action == "2" || action == "Save dungeon" || action == "save dungeon"){
            
            cout << "Enter dungeon name: ";
            string name;
            getline(cin, name);
            creating_dungeon.set_name(name);
            editing = false;
        }
        
    }
    
    return creating_dungeon;
}


int main() {
    
    vector<GridGame> Dungeons;
   
    
    Dungeons.push_back(initialization_for_1());
    Dungeons.push_back(initialization_for_Tutorial());
    
    
    
    
    bool loop_error = false;
    
    do{
        
        do {
            string choice;
            cout << "Welcome to Magic Tower: Revenge of the Warlock Part VII" << endl;
            
            cout << "1) Enter a dungeon" << endl;
            cout << "2) Design a dungeon" << endl;
            cout << "3) Exit" << endl;
            cout << "enter your choice: ";
            getline(cin, choice);
            
            
            if(cin.fail() && choice != "1" && choice != "Enter a dungeon" && choice != "enter a dungeon" && choice != "2" && choice != "Design a dungeon" && choice != "design a dungeon" && choice != "3" && choice != "exit" && choice != "Exit"){
                cin.clear();
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop_error = false;
                cout << "invalid input!" << endl;
                cout << endl;
            }
            //use 0-4
            else if(choice == "1" || choice == "Enter a dungeon" || choice == "enter a dungeon"){
                loop_error = true;
                cout << endl;
                
                string move_choice;
                do {
                    
                    cout << "Choose the movement you would like to use: " << endl;
                    cout << "1) WASD" << endl;
                    cout << "2) LRUP" << endl;
                    cout << "enter your choice: ";
                    getline(cin, move_choice);
                    
                    
                    if(cin.fail() && move_choice == "1" && move_choice == "WASD" && move_choice == "wasd" && move_choice == "2" && move_choice == "LRUP" && move_choice == "lrup"){
                        cin.clear();
                        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        loop_error = false;
                        cout << "invalid input!" << endl;
                        cout << endl;
                    }
                    
                    else if (move_choice == "1" || move_choice == "WASD" || move_choice == "wasd"){
                        loop_error = true;
                        
                        cout << endl;
                        
                    }
                    
                    else if (move_choice == "2" || move_choice == "LRUP" || move_choice == "lrup"){
                        loop_error = true;
                        
                        cout << endl;
                    }
                    
                } while (!loop_error);
                
                
                int choosing_dungeon;
                //string choosing_dungeon;
                do {
                    cout << "Choose the type of dungeon:" << endl;
                    
                    for (int i = 0; i < Dungeons.size() ; i++) {
                        cout << i + 1 << ") " << Dungeons[i].get_Name() << endl;
                    }
                    
                    cout << "Select dungeon: ";
                    //getline(cin, choosing_dungeon);
                    cin >> choosing_dungeon;
                    
                    if(cin.fail() || choosing_dungeon < 1 || choosing_dungeon > Dungeons.size()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        loop_error = false;
                        cout << "invalid input!" << endl;
                        cout << endl;
                    }
                    
                    else if(choosing_dungeon == 2 ){
                        loop_error = true;
                        doing_the_tutorial(initialization_for_Tutorial(), move_choice);
                    }
                    
                    
                    else {
                        loop_error = true;
                        
                        cout << "Starting the Dungeon..." << endl;
                        
                        this_thread::sleep_for(chrono::seconds(5));
                        
                        playing_dungeon(Dungeons[choosing_dungeon - 1], move_choice);
                        cout << endl;
                    }
                    
                }while(!loop_error);
                
            }
            
            else if (choice == "2" || choice == "Design a dungeon" || choice == "design a dungeon"){
                
                loop_error = false;
                
                bool choosing_edit_or_create = false;
                do {
                    cout << endl;
                    cout << "Whould you like to edit or make a new dungeon:" << endl;
                    cout << "1) Make a dungeon" << endl;
                    cout << "2) Update a dungeon" << endl;
                    cout << "Enter your choice: " ;
                    string choice3;
                    getline(cin, choice3);
                    
                    if(cin.fail()){
                        cin.clear();
                        choosing_edit_or_create = false;
                        cout << "invalid input!" << endl;
                        cout << endl;
                    }
                    
                    else if(choice3 == "1" || choice3 == "make a dungeon" || choice3 == "Make a dungeon"){
                        choosing_edit_or_create = true;
                        cout << endl;
                        GridGame custom = creating_a_dungeon();
                        Dungeons.push_back(custom);
                    }
                    
                    else if (choice3 == "2" || choice3 == "update a dungeon" || choice3 == "Update a dungeon"){
                        
                        choosing_edit_or_create = true;
                        
                        cout << "choose which dungeons you would like to update:" << endl;
                        for (int i = 0; i < Dungeons.size() ; i++) {
                            cout << i + 1 << ") " << Dungeons[i].get_Name() << endl;
                        }
                        
                        cout << "Select dungeon: ";
                        int pick;
                        cin >> pick;
                        
                        if (pick > 0 && pick <= Dungeons.size()){
                            GridGame updating = editing_dungeon(Dungeons[pick - 1]);
                            Dungeons.pop_back();
                            
                            Dungeons.push_back(updating);
                        }
                    }
                    
                } while (!choosing_edit_or_create);
            }
            
            else if (choice == "3" || choice == "exit" || choice == "Exit"){
                loop_error = true;
                cout << endl;
                return 0;
            }
            
        } while (!loop_error);
        
        cout << endl;
        cout << "Would you like to keep going or end the game at once?" << endl;
        cout << "Here are your options" << endl;
        cout << "1) Keep going" << endl;
        cout << "2) Quit" << endl;
        cout << "Enter your choice here: ";
        string entire_game;
        getline(cin, entire_game);
        
        if (cin.fail() && entire_game != "1" && entire_game != "Keep going" && entire_game != "keep going" && entire_game != "2" && entire_game != "Quit" && entire_game != "quit" ) {
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loop_error = false;
            cout << "invalid input!" << endl;
            cout << endl;
        }
        
        else if (entire_game == "1" || entire_game == "Keep going" || entire_game == "keep going"){
            loop_error = false;
        }
        else{
            loop_error = true;
        }
        
    }while (!loop_error);
    

    
    
    
}
