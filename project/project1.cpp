#include <iostream>
#include <string>
#include <time.h>

using namespace std;
const int ROW = 4, COL = 4; 

// Shows the cards set 
template<typename T>
void display(T const (*card_list)[COL])
{
    for (int i = 0; i < ROW+2; i++){
        for (int j = 0; j < COL+1; j++){
            if (i==0){
                if (j==0) cout << "    ";
                else cout << j << " ";
            }
            else if (i==1){
                if (j==0) cout << "--+";
                else cout << "--";
            }
            else if (j==0) cout << " " << i-1 << "| ";
            else cout << card_list[i-2][j-1] << " ";
        }
        cout << endl;
    }
    return;
}

// Game progress
void pick(string player, int& score, string other, const int other_score, int& remain, string (*card_list)[COL], int (*default_card)[COL])
{
    string card1, card2;
    int card1_row, card1_col, card2_row, card2_col;

    while(true){
        cout << player << "'s turn, choose two cards (" << remain << " turns remain): ";
        cin >> card1 >> card2;

        // Handling errors outside of the coordinate range
        if (card1[0]-'0' > ROW || card1[1]-'0' > COL || card2[0]-'0' > ROW || card2[1]-'0' > COL || card1.size() > 2 || card2.size() > 2){
            cout << "Please reset the coordinate range!!" << endl;
            continue;
        }
        // Resolving an already found card reselection error
        else if (card_list[card1[0]-1-'0'][card1[1]-1-'0'] != "x" || card_list[card2[0]-1-'0'][card2[1]-1-'0'] != "x"){
            cout << "This card has already been found! Please choose again." << endl; 
            continue;
        } 
        
        card_list[card1[0]-1-'0'][card1[1]-1-'0'] = to_string(default_card[card1[0]-1-'0'][card1[1]-1-'0']);
        card_list[card2[0]-1-'0'][card2[1]-1-'0'] = to_string(default_card[card2[0]-1-'0'][card2[1]-1-'0']);

        display(card_list);

        if (default_card[card1[0]-1-'0'][card1[1]-1-'0'] != default_card[card2[0]-1-'0'][card2[1]-1-'0']){
            cout << player << " failed to find a matching pair" << endl;
            card_list[card1[0]-1-'0'][card1[1]-1-'0'] = "x";
            card_list[card2[0]-1-'0'][card2[1]-1-'0'] = "x";
        }
        else {
            if (default_card[card1[0]-1-'0'][card1[1]-1-'0'] == 7) {
                cout << "Congratulations!! you got the bonus points!! :)" << endl;
                score++;
            }
            score++;
            cout << player << " found a matching pair! " 
                        << other << "'s score: " << other_score << ", " << player << "'s score: " << score << endl;
        }
        remain--;
        break;
    }
    return;
}

// Check whether the game ending conditions are satisfied
bool game_finished(const int (*default_card)[COL], const string (*card_list)[COL], const int remain)
{
    bool isFinished = true;
    for (int i=0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            if (card_list[i][j] != to_string(default_card[i][j])){
                isFinished = false;
                break;
            }
        }
    }
    if (remain == 0) isFinished = true;
    return isFinished;
}

// Run at the end of the game --> display the final scores and result
void show_result(const int remain, const string player1, const int score1, const string player2, const int score2)
{
    cout << "\n";
    // When value set to remain(20) turns are over
    if (remain == 0) cout << "Game Finished!! " << remain << " turns remain!" << endl;
    // When all card pairs are found
    else cout << "Game Finished. You found all pairs!! " <<  endl;
    
    cout << "Final scores are " << player1 << " : " << score1 << ", " << player2 << " : " << score2 << endl;
    if (score1 > score2) cout << "The winner is " << player1 << "!! Congratulations ~" << endl;
    else if (score1 < score2) cout << "The winner is " << player2 << "!! Congratulations ~" << endl;
    else cout << "It's a draw!!" << endl;
   
    return;
}

int main()
{
    int default_card[ROW][COL];
    int card_num = 0;
    int P1_score = 0, P2_score = 0, remain = 20;
    string mode;
    string card_list[ROW][COL];
    const string P1 = "P1", P2 = "P2";
    srand(time(NULL));

    cout << "Choose card generation mode (1: Static, 2: Random): ";
    cin >> mode;

    // Set of cards on the table --> Initially, they are all backsides, and then they will be different.
    for (int i=0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            card_list[i][j] = "x";
        }
    }
    display(card_list);

    // mode 1 : Fixed arrangement version --> each number has 2 pairs (MAX : ROW*COL/2 / MIN : 1)
    if (mode == "1"){
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                if (i < ROW/2) card_num++;
                else if (i == ROW/2 && j ==0) card_num+=0;
                else card_num--;
                default_card[i][j] = card_num;
            }
        }
        // display(default_card);
    }
    
    // mode 2: Random placement version --> each number has 2 pairs (MAX : ROW*COL/2 / MIN : 1)
    else if (mode == "2"){
        for (int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++){
                default_card[i][j] = rand()%(ROW*COL/2) + 1;    // For (ROW : 4, COL : 4), it means "rand()%8 + 1"
            }
        }
        // display(default_card);
    }

    while(true){
        pick(P1, P1_score, P2, P2_score, remain, card_list, default_card);
        if (game_finished(default_card, card_list, remain) == true) {
            show_result(remain, P1, P1_score, P2, P2_score);
            break;
        }
        
        pick(P2, P2_score, P1, P1_score, remain, card_list, default_card);
        if (game_finished(default_card, card_list, remain) == true) {
            show_result(remain, P1, P1_score, P2, P2_score);
            break;
        }
    }
    return 0;
}