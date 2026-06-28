#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
        char name[50];
        int x;
        int y;
        int score;
        int keys;
        int health;
        char symbol; //player symbol

} Player;

char map[15][15];
int hiddenTraps[15][15];
Player players[2]; //array for 2 players

//placing 30 random interior walls
void placeWalls() {
	int wallsPlaced = 0;
	while (wallsPlaced < 30) {
		int randomRow = (rand() % 13) + 1;
                int randomCol = (rand() % 13) + 1;

                if (map[randomRow][randomCol] == ' ') {
                        map[randomRow][randomCol] = '#';
                        wallsPlaced++;
                }
        }
}

//placing 12 random Treasures
void placeTreasures() {
	int treasuresPlaced = 0;
	while (treasuresPlaced < 12) {
		int randomRow = (rand() % 13) + 1;
		int randomCol = (rand() % 13) + 1;
		
		if (map[randomRow][randomCol] == ' ') {
			map[randomRow][randomCol] = 'T';
		        treasuresPlaced++;
		}
	}		
}

//placing 10 random Traps
void placeTraps() {
	int trapsPlaced = 0;
	while (trapsPlaced < 10) {
		int randomRow = (rand() % 13) + 1;
                int randomCol = (rand() % 13) + 1;

                if (map[randomRow][randomCol] == ' ' && hiddenTraps[randomRow][randomCol] == 0) {
                        hiddenTraps[randomRow][randomCol] = 1;
                        trapsPlaced++;
                }
        }
}

//Placing 5 random health packs
void placeHealth() {
        int healthPlaced = 0;
        while (healthPlaced < 5) {
                int randomRow = (rand() % 13) + 1;
                int randomCol = (rand() % 13) + 1;

                if (map[randomRow][randomCol] == ' ') {
                        map[randomRow][randomCol] = 'H';
                        healthPlaced++;
                }
        }
}

//Placing 3 random Keys
void placeKeys() {
        int keysPlaced = 0;
        while (keysPlaced < 3) {
                int randomRow = (rand() % 13) + 1;
                int randomCol = (rand() % 13) + 1;

                if (map[randomRow][randomCol] == ' ') {
                        map[randomRow][randomCol] = 'K';
                        keysPlaced++;
                }
        }
}

//Placing 3 random doors
void placeDoors() {
        int doorsPlaced = 0;
        while (doorsPlaced < 3) {
                int randomRow = (rand() % 13) + 1;
                int randomCol = (rand() % 13) + 1;

                if (map[randomRow][randomCol] == ' ') {
                        map[randomRow][randomCol] = 'D';
                        doorsPlaced++;
                }
        }
}


//print the full map
void printMap() {
	for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 15; j++) {
                        printf("%c ", map[i][j]);
                }
                printf("\n");
        }
}

void placePlayers() {
        //set stats for player 1
        players[0].health = 100;
        players[0].score = 0;
        players[0].keys = 0;
        players[0].symbol = '1';

        //set stats for player 2
        players[1].health = 100;
        players[1].score = 0;
        players[1].keys = 0;
        players[1].symbol = '2';

        //loop 2 times for players
        for (int i = 0; i < 2; i++) {
                int isPlaced = 0;  //1 = placed , 0 = not placed

                while (isPlaced == 0) {
                        int randomRow = (rand() % 13) + 1;
                        int randomCol = (rand() % 13) + 1;
                        
                        //map is empty and no hidden traps?
                        if (map[randomRow][randomCol] == ' ' && hiddenTraps[randomRow][randomCol] == 0) {
                                
                                //save x,y coordinates for each player
                                players[i].y = randomRow;
                                players[i].x = randomCol;

                                //print player symbol
                                map[randomRow][randomCol] = players[i].symbol;

                                //stops the loop and switches to the other player
                                isPlaced = 1;
                        }
                        
                }
        }
}

// Setup exterior walls, interior empty spaces and Traps
void initializeMap() {
        for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 15; j++) {

                        if (i == 0 || i == 14 || j == 0 || j  == 14){
                                map[i][j] = '#';
                        }
                        else {
                                map[i][j] = ' ';
                        }

                        hiddenTraps[i][j] = 0;
                }
        }
	placeWalls();
	placeTreasures();
	placeDoors();
	placeHealth();
	placeTraps();
	placeKeys();
        placePlayers();
}

int main() {
	srand(time(NULL));
	initializeMap();
	printMap();

	return 0;
}
