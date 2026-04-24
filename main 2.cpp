//
//  main.cpp
//  GRID prototype 2
//
//  Created by Andres Vizoso on 4/16/26.
//

#include <iostream>
#include <vector>

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
    };
    
    int get_player_defense(){
        return player_defense;
    }
    
    int get_player_strength(){
        return player_strength;
    };
    
    void pretty_print_Player(){
            cout << "Meet your Wizard: " << name << endl;
            cout << "Stats: " << endl;
            cout << "Hearts: " << player_Hearts << endl;
            cout << "Strength: " << player_strength << endl;
            cout << "defense: " << player_defense << endl;
            cout << "Keys: " << keys << endl;
            //cout << "potion of Health: ";
            
        }
    int getting_one_key(){
        return ++keys;
        }
    
};


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



class GridGame {
private:
    string name;
    int rows, cols;
    int playerX, playerY;
    vector<vector<char>> grid;

public:
    
    Player P = Player("Henry");
    Enemy_RUNT E;
    
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
    
    void set_name(const string& n){
        name = n;
    }
    
    void setTile(int r, int c, char type) {
        grid[r][c] = type;
    }
    
    void initialize(){
        setTile(playerX, playerY, '$');
        
        //grid[3][3] = '#';
        setTile(3, 3, '#');
       
        setTile(4, 3, 'K');
    }
    
    Player get_Player_P(){
        return P;
    }
    
    bool move(char direction) {
            int nextX = playerX, nextY = playerY;

            // Determine new potential coordinates
            if (direction == 'w') nextX--;      // Up
            else if (direction == 's') nextX++; // Down
            else if (direction == 'a') nextY--; // Left
            else if (direction == 'd') nextY++; // Right
            else return false; // Invalid input
        
        if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols) {
            
            
            if (grid[nextX][nextY] == '#'){
              
            return false;
        }
            
            if(grid[nextX][nextY] == 'K'){
                P.keys++;
                cout << "Collect one key." << endl;
                
                grid[playerX][playerY] = '-';
                        playerX = nextX;
                        playerY = nextY;
                grid[playerX][playerY] = '$';
                return true;
            }
            grid[playerX][playerY] = '-';  // Clear old position
            playerX = nextX;
            playerY = nextY;
            grid[playerX][playerY] = '$';
            
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
        
        
        for (int i = 1; i <= rows; i++){
            cout << "      " << i;
        }
        
        cout << endl;
        
        string dashes = string(rows + 45, '-');
        
        cout << dashes << endl;
        
        
        
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
    
    
};

GridGame initialization_for_1(){
    GridGame dungeon_1 = GridGame(5, 5, "Dungeon 1", 1, 1);
    dungeon_1.setTile(dungeon_1.get_playerX(), dungeon_1.get_playerY(), '$');
    
    
    dungeon_1.setTile(3, 3, '#');
   
    dungeon_1.setTile(4, 3, 'K');
    return dungeon_1;
}

GridGame initialization_for_Tutorial(){
    GridGame dungeon_1 = GridGame(5, 5, "Tutorial", 1, 1);
    dungeon_1.setTile(dungeon_1.get_playerX(), dungeon_1.get_playerY(), '$');
    
    
    dungeon_1.setTile(3, 3, '#');
   
    dungeon_1.setTile(4, 3, 'K');
    return dungeon_1;
}

void playing_dungeon(GridGame g){
    

    char userInput;
    
    while (true) {
        cout << "=================================" << endl;
        
                g.display_for_normal();
        g.get_Player_P().pretty_print_Player();
        
        
        cout << "Enter move (w/a/s/d or q to quit): ";
        cin >> userInput;
        
        if (userInput == 'q') {
            cout << "Exiting game." << endl;
            break;
        }
        
        g.move(userInput);
    }
    
}

GridGame editing_dungeon(GridGame Updating_grid){
    
    Updating_grid.display_for_dungeon_creation();
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
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cout << "10) Player" << endl;
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
                else if (choice == "10" || choice == "Player"){
                    loop_updating = true;
                    object_choosen = '$';
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
                
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    loop_updating = false;
                    cout << "Invalid coordinates!" << endl;
                    cout << endl;
                }
                else{
                    loop_updating = true;
                Updating_grid.setTile(x-1, y-1, object_choosen);
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
        cout << "Enter rows: ";
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
        cout << "Enter colums: ";
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
        
        if (cin.fail()|| p_x < 1 || p_y < 1 || p_x > rows_C || p_y > cols_C) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loop = false;
            cout << "\nInvalid column. Please enter an integer" << endl;
        }
        else {
            loop = true;
            
        }
    } while (!loop);
    
    
    GridGame creating_dungeon = GridGame(rows_C, cols_C, "Custom", p_x - 1, p_y - 1);
        creating_dungeon.setTile(p_x - 1, p_y - 1, '$');
    
    bool editing = true;
    while(editing){
        cout << endl;
        creating_dungeon.display_for_dungeon_creation();
        cout << endl;
        cout << "Actions:" << endl;
        cout << "1) Add object" << endl;
        cout << "2) Save dungeon" << endl;
        cout << "Select action: ";
        string action;
        getline(cin, action);
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cout << "10) Player" << endl;
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
                else if (choice == "10" || choice == "Player"){
                    loop = true;
                    object_choosen = '$';
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
                
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    loop = false;
                    cout << "Invalid coordinates!" << endl;
                    cout << endl;
                }
                else{
                    loop = true;
                creating_dungeon.setTile(x-1, y-1, object_choosen);
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
    string choice;
    
    
    do {
        cout << "Welcome to Magic Tower: Revenge of the Warlock Part VII" << endl;
         
        cout << "1) Enter a dungeon" << endl;
        cout << "2) Design a dungeon" << endl;
        cout << "3) Exit" << endl;
        cout << "enter your choice: ";
        getline(cin, choice);
        
        cout << endl;
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
            
            for (int i = 0; i < Dungeons.size() ; i++) {
                cout << i + 1 << ") " << Dungeons[i].get_Name() << endl;
            }
        
            cout << "Select dungeon: ";
            int pick;
            cin >> pick;
        
            if (pick > 0 && pick <= Dungeons.size()){
                playing_dungeon(Dungeons[pick - 1]);
            }
            
            cout << "enter your choice (in number): ";
            getline(cin, choice2);
            
            cout << endl;
            
            if(cin.fail() ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                loop_error2 = false;
                cout << "invalid input!" << endl;
                cout << endl;
            }
            
            else if (choice2 == "1" || choice2 == "regular dungeon"){
                loop_error2 = true;
                cout << endl;
                
            }
                
            else if (choice2 == "2" || choice2 == "tutorial dungeon"){
                
                loop_error2 = false;
                cout << "still working on it" << endl;
                cout << endl;
                
            }
            
        } while (!loop_error2);
        
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                choosing_edit_or_create = false;
                cout << "invalid input!" << endl;
                cout << endl;
            }
            
            else if(choice3 == "1"){
                choosing_edit_or_create = true;
                cout << endl;
                GridGame custom = creating_a_dungeon();
                Dungeons.push_back(custom);
            }
            
            else if (choice3 == "2"){
                
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
    //char talking = 34;
    return 0;
    //cout << talking << endl;
    

    
    
    
}
