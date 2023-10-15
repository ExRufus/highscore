#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

int SIZE = 4;

int board[4][4];
int score = 0;

struct Game {
    char UserID[6];
    char Username[20];
    int Score;
}; 

void menu();
int readData(struct Game *game, int *highScoreCount);
void writeData(struct Game *game, int highScoreCount);
void addData(struct Game *game, int *highScoreCount);
void waitForEnter();
void viewHighScoreList(struct Game *game, int highScoreCount);
void initBoard();
void displayBoard();
int isBoardFull();
void placeRandom();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
void isExit();
void gamePlay();

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
    score = 0;
}

void displayBoard() {
    system("cls");
    printf("2048 Game\n");
    printf("Score: %d\n\n", score);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf(".\t");
            } else {
                printf("%d\t", board[i][j]);
            }
        }
        printf("\n\n");
    }
}

int isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void bubbleSort(struct Game *game, int highScoreCount) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < highScoreCount - 1; i++) {
            if (game[i].Score < game[i + 1].Score) {
                // Swap game[i] and game[i+1]
                struct Game temp = game[i];
                game[i] = game[i + 1];
                game[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

void placeRandom() {
    int emptyCells[SIZE * SIZE][2];
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }

    if (count > 0) {
        int index = rand() % count;
        int randomValue = (rand() % 2 + 1) * 2; // 2 atau 4
        int x = emptyCells[index][0];
        int y = emptyCells[index][1];
        board[x][y] = randomValue;
    }
}

void moveUp() {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] != 0) {
                int k = i;
                while (k > 0 && board[k - 1][j] == 0) {
                    board[k - 1][j] = board[k][j];
                    board[k][j] = 0;
                    k--;
                }
                if (k > 0 && board[k - 1][j] == board[k][j]) {
                    board[k - 1][j] *= 2;
                    score += board[k - 1][j];
                    board[k][j] = 0;
                }
            }
        }
    }
}



void moveDown() {
    for (int j = 0; j < SIZE; j++) {
        for (int i = SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i;
                while (k < SIZE - 1 && board[k + 1][j] == 0) {
                    board[k + 1][j] = board[k][j];
                    board[k][j] = 0;
                    k++;
                }
                if (k < SIZE - 1 && board[k + 1][j] == board[k][j]) {
                    board[k + 1][j] *= 2;
                    score += board[k + 1][j];
                    board[k][j] = 0;
                }
            }
        }
    }
}

void moveLeft() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != 0) {
                int k = j;
                while (k > 0 && board[i][k - 1] == 0) {
                    board[i][k - 1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
                if (k > 0 && board[i][k - 1] == board[i][k]) {
                    board[i][k - 1] *= 2;
                    score += board[i][k - 1];
                    board[i][k] = 0;
                }
            }
        }
    }
}

void moveRight() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int k = j;
                while (k < SIZE - 1 && board[i][k + 1] == 0) {
                    board[i][k + 1] = board[i][k];
                    board[i][k] = 0;
                    k++;
                }
                if (k < SIZE - 1 && board[i][k + 1] == board[i][k]) {
                    board[i][k + 1] *= 2;
                    score += board[i][k + 1];
                    board[i][k] = 0;
                }
            }
        }
    }

}

void isExit(){
    	puts("                        .:^:.. ..^^:..												");
    	puts("                      ...   ...:.     .......    .									"); 
        puts("                        .   . ^.   :..:~~77~~~::..::.. ..							"); 
        puts("                      ::::..~..:..:~7~.: :^ ~^:~..:....:^~^:^~^					"); 
        puts("                    ..      .. .^!777^~~!?~^~7:^::.  .5BGB##&#7.					"); 
        puts("                         .:~!!. .:~^.77?P57P7!^::~::?5B&&#GGG5.					"); 
        puts("                      .:^~~^^: YJJGBGP5YY7J7!^^^?7YG##P7^7#&B~:					"); 
        puts("                    .^~~:  ~J55PJ~:.       ..~JPBBBY^. .:.JG!:!!^..				"); 
        puts("                 ..^7~  .::???.         .~!JG&&#J:       .7!:.^77?!^..			"); 
        puts("               .:~7!:. ^Y^.  ..      .!JPB&&#Y:          .  :7!: ~G5?!:.			");
        puts("             .:~7?7..~!!       .:..^?YP&&&G7         .        ~J: .BP7J!:.		"); 
        puts("           .:^777~^::7^          :JB&&#BG^ .                   .J! !YYYJ?^.		"); 
        puts("          .:!JJJJ: :7G.         ?#&&&&B~                         ?5..^!~~!!:.		"); 
        puts("         .:!YYY5~ .J&Y      . .5BBBBBG^                           YP  :?J!~!^.	"); 
        puts("         .:!J?YJ^..P&!        P&&&&&#!             ..              #7 .^55?^~:	"); 
        puts("          .^7!??^..P#? .  .   ~#&&&&&J:..   ...  .   ..  ...     . 5#..:J57~!:.	");  
        puts("          .:!J~~^.?G#5      .:.^JGBBBP5Y!^75GBGP5PJYPGPP5YYJ?!^    !&:.:??~?~:.	");  
        puts("           .^?5^:.JPBP!       .:::.. .!YYY&&&###&&&&YG##&&&&#B5:   !&:.^~!5J~.	");  
        puts("            .^??:.^^?77..                 ^:.  ..P&G:^&&&&&&&&7    PG ~7:JP7:.	");  
        puts("            .:^7? .~~J?7!                 .      7#^ P&&&&&&G^    :&^ 7?5?!:.		");  
        puts("              .^J5.:!JPBBY            .:.       ^5^ 7###&#P^      G7..7G5!:.		");  
        puts("               .^?5~^~:~PBP~.?!~: ^^7~^!^     .7: ~#&&#5~        ~~:.:PY~:.		");  
        puts("                .^!5J7..~!B&PJY?J^J?YGY?7!:..^^:?#@&G7.        .~.::^Y!^.			");  
        puts("                 .:^??J!77JY57 .: :?#BYGG!7~:7G&#5~.           .~^!J5!:.			");  
        puts("                   .:~?JY~..... :.^!J^^!7~7PGPJ~.          ... ^?Y57:.			");      
        puts("                      :~75P~:.  ^^!!^~!JYJ57:..^^....:^!:  ...5GP7^.				");      
        puts("                      ::.:~^7.JY^?77Y5Y7^..::~??5J???5J: :?Y!J5!:.				");      
        puts("                       .  .^.7G&###B5!^:.:.::......~?J?YB#BY7^:.					");      
        puts("                          .^^YJ5###BG5J7!7JYPPGYJ??YPPPY?7~:.						");      
        puts("                          ..:^~^^........^~!~!!!!~^^::...							");      
        puts("																					");      
        puts("																					");      
        puts("                    o---------------------------------------------o				");      
        puts("                    |      Breaking and Overcoming Challenges     |				");      
        puts("                    |    Through Courage Hardwork and Persistence |				");      
        puts("                    |           ~~ Bluejackets 23-1 ~~            |				");      
        puts("                    o---------------------------------------------o				");      
        puts("																					");      
        puts("																					");      
        puts("																					");      
    	
};

int main() {
    srand(time(NULL));
    initBoard();
    placeRandom();
    placeRandom();
    
    struct Game game[25];
    int menuNum;
    int highScoreCount = 0;
    
    do {
        menu();
        printf("Main Menu:\n");
        printf("1. New Game\n");
        printf("2. Highscore\n");
        printf("3. Exit\n");
        scanf("%d", &menuNum);
        fflush(stdin); 
            
        switch (menuNum) {
            case 1: 
                gamePlay();
                while (1) {
                    displayBoard();



                    if (isBoardFull()) {
                        break;
                    }

                    char move = getch();
                    switch (move) {
                        case 'w':
                            moveUp();
                            break;
                        case 's':
                            moveDown();
                            break;
                        case 'a':
                            moveLeft();
                            break;
                        case 'd':
                            moveRight();
                            break;
                        case 13:
                            printf("Press Enter To Continue...\n");
                            waitForEnter();
                            break;
                    }

                    placeRandom();
                }
                printf("Save Data...");
                addData(game, &highScoreCount);
                break;
            case 2:
                readData(game, &highScoreCount);
                bubbleSort(game, highScoreCount);
                viewHighScoreList(game, highScoreCount);
                waitForEnter();
                break;
            case 3:
                isExit();
                printf("Exiting the application. Press any key to exit...");
                waitForEnter();
                exit(0);
                return 0;
        }
    } while (menuNum < 1 || menuNum > 3);

    return 0;
}

    void menu(){
    	puts("  ______             __            __    __ ");
    	puts(" /      \\           /  |          /  |  /  |");
    	puts("/$$$$$$  |  ______  $$ | __    __ $$ |  $$ |");
    	puts("$$ |  $$/  /      \\ $$ |/  |  /  |$$  \\/$$/ ");
    	puts("$$ |       $$$$$$  |$$ |$$ |  $$ | $$  $$<  ");
    	puts("$$ |   __  /    $$ |$$ |$$ |  $$ |  $$$$  \\ ");
    	puts("$$ \\__/  |/$$$$$$$ |$$ |$$ \\__$$ | $$ /$$  |");
    	puts("$$    $$/ $$    $$ |$$ |$$    $$ |$$ |  $$ |");
    	puts(" $$$$$$/   $$$$$$$/ $$/  $$$$$$$ |$$/   $$/ ");
    	puts("                        /  \\__$$ |");
    	puts("                        $$    $$/");
    	puts("                         $$$$$$/");
    	printf(">> ");
    	
    }
    
    

    int readData(struct Game *game, int *highScoreCount){
    	FILE *file = fopen("highscore.txt", "r");
    	if (file == NULL) {
    	    printf("Failed to open the file highscore.txt\n");
    	    return 0;
    	}
        
        *highScoreCount = 0;
        while (fscanf(file, " %10[^#]#%20[^#]#%d\n", game[*highScoreCount].UserID, game[*highScoreCount].Username, &game[*highScoreCount].Score) == 3) {
            (*highScoreCount)++;
        }
        
    	fclose(file); 
    	return 1;
    }

    void writeData(struct Game *game, int highScoreCount) {
        FILE *file = fopen("highscore.txt", "w");
        if (file == NULL) {
    	    printf("Failed to open the file highscore.txt\n");
    	    return;
    	}
    
    	for (int i = 0; i < highScoreCount; i++) {
            fprintf(file, "%s#%s#%d\n", game[i].UserID ,game[i].Username, game[i].Score);
            }
            
    	fclose(file);
    }
    
    void gamePlay() {
        int boardSize;
        
        while (1) {
            printf("Input Grid Size [4 or 6]: ");
            if (scanf("%d", &boardSize) != 1) {
                printf("Invalid input. Please enter 4 or 6.\n");
                while (getchar() != '\n');
                continue;
            }
            if (boardSize != 4 && boardSize != 6) {
                printf("Invalid input. Please enter 4 or 6.\n");
                continue;
            }
            
            SIZE = boardSize;
            
            initBoard();
            break;
        }
    }

    void addData(struct Game *game, int *highScoreCount){
        
        char username[20];
        while (1) {
            printf("Input Name [name length must be between 3-15]: ");
            fgets(username, sizeof(username), stdin);
            username[strcspn(username, "\n")] = '\0';
            
            if (strlen(username) >= 3 && strlen(username) <= 15) {
                break;
            } else {
                printf("Input Name [name length must be between 3-15]: ");
            }
        }
        
        int randomDigits = (rand() % 9) + 1;
        char id[6];
        snprintf(id, sizeof(id), "%c%c%03d", username[1], username[2], randomDigits);
        
        for (int i = 0; i < *highScoreCount; i++) {
        for (int j = i + 1; j < *highScoreCount; j++) {
            if (game[i].Score < game[j].Score) {
                struct Game temp = game[i];
                game[i] = game[j];
                game[j] = temp;
                }
            }
        }

        if (*highScoreCount > 25) {
            (*highScoreCount) = 25;
        }
        
        struct Game newGame;
        strcpy(newGame.UserID, id);
        strcpy(newGame.Username, username);
        newGame.Score = score;
        
        game[*highScoreCount] = newGame;
        (*highScoreCount)++;
    
        writeData(game, *highScoreCount);
    }
    
    void waitForEnter() {
        printf("Press Enter to Continue...");
        while (getchar() != '\n');
    }
    
    void viewHighScoreList(struct Game *game, int highScoreCount) {
        printf("%-6s %-8s %-10s %-6s\n", "Rank", "ID", "Username", "Score");
        for (int i = 0; i < highScoreCount; i++) {
            printf("%-6d %-8s %-10s %-6d\n", i + 1, game[i].UserID, game[i].Username, game[i].Score);
        }
        
    }