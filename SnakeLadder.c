#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN 100 // Winning position

// Function to roll dice
int rollDice() {
    return rand() % 6 + 1; // 1 to 6
}

// Function to check snakes, ladders, and hurdles
int checkPosition(int pos) {
    // Ladders
    if(pos == 4) return 14;
    if(pos == 9) return 31;
    if(pos == 20) return 38;
    if(pos == 28) return 84;
    if(pos == 40) return 59;
    if(pos == 51) return 67;
    if(pos == 63) return 81;
    
    // Snakes
    if(pos == 17) return 7;
    if(pos == 54) return 34;
    if(pos == 62) return 19;
    if(pos == 64) return 60;
    if(pos == 87) return 24;
    if(pos == 93) return 73;
    if(pos == 95) return 75;
    if(pos == 99) return 78;

    // Hurdles (if landed, player dies and goes back to start)
    if(pos == 11 || pos == 36 || pos == 70) {
        printf("💀 HURDLE! You fell and back to start!\n");
        return 0; // reset position
    }

    return pos;
}

// Function to print ASCII board (simplified)
void printBoard(int p1, int p2) {
    printf("\n------------------------------------------\n");
    for(int i = 1; i <= 100; i++){
        if(i == p1 && i == p2) printf("[B]");
        else if(i == p1) printf("[1]");
        else if(i == p2) printf("[2]");
        else if(i==4||i==9||i==20||i==28||i==40||i==51||i==63) printf("[L]"); // ladder
        else if(i==17||i==54||i==62||i==64||i==87||i==93||i==95||i==99) printf("[S]"); // snake
        else if(i==11||i==36||i==70) printf("[H]"); // hurdle
        else printf("[ ]");

        if(i%10==0) printf("\n");
    }
    printf("------------------------------------------\n");
}

int main() {
    int player1=0, player2=0;
    int dice;
    srand(time(NULL));
    char ch;

    printf("🎮 SNAKE & LADDER WITH HURDLE 🎮\n");
    printf("Two Players: Player 1 and Player 2\n");
    printf("L = Ladder, S = Snake, H = Hurdle (back to start)\n");

    while(player1<WIN && player2<WIN){
        // Player 1
        printf("\nPlayer 1, press Enter to roll dice...");
        getchar();
        dice = rollDice();
        printf("Player 1 rolled: %d\n", dice);
        player1 += dice;
        if(player1>WIN) player1 = WIN;
        player1 = checkPosition(player1);
        printf("Player 1 is now at: %d\n", player1);

        printBoard(player1, player2);
        if(player1>=WIN) break;

        // Player 2
        printf("\nPlayer 2, press Enter to roll dice...");
        getchar();
        dice = rollDice();
        printf("Player 2 rolled: %d\n", dice);
        player2 += dice;
        if(player2>WIN) player2 = WIN;
        player2 = checkPosition(player2);
        printf("Player 2 is now at: %d\n", player2);

        printBoard(player1, player2);
    }

    if(player1>=WIN) printf("\n Player 1 Wins! Congratulations!\n");
    else printf("\n Player 2 Wins! Congratulations!\n");

    return 0;
}
