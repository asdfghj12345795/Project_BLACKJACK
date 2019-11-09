#include <stdio.h>
#include <stdlib.h>//to use rand function
#include <time.h>

#define N_CARDSET	1
#define N_CARD	52
#define N_MAX_CARDNUM	13
#define N_MAX_USER	5
#define N_MAX_CARDHOLD	10
#define N_MAX_GO	17
#define N_MIN_ENCARD	30

int dollar[N_MAX_USER]; //set the array of dollor by number of user 
int n_user;

int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD]; //setting that the user has 
int cardSum[N_MAX_USER]; //number of cards
int bet[N_MAX_USER]; //players do betting
int gameEnd=0; // flag of end
int PLAY_NUMBER;//fix the play number 
int N_ROUND=1; //represent the count of round
int N_DOLLAR = 50;
int Card_set[N_CARD] = {1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10}; //total card is 52
int Player_Card[N_MAX_USER];
int Dealer_card[N_MAX_CARD]; 

int getIntegerInput(void) // the function that protect to input
 {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}
extern int PLAY_NUMBER;
int PLAY_NUM() // input the sum of players
{	
	
	do{
		printf("Input the number of players (MAX :5) :");
		scanf("%d", &PLAY_NUMBER);
		
		if(PLAY_NUMBER<1)
		{
			printf("too small\n");
		}
		
		else if(PLAY_NUMBER>5)
		{
			printf("too many player\n");
		}

}while(PLAY_NUMBER<0||PLAY_NUMBER>5);

printf("---> card is mixed and put into the tray\n");
return 0;
}
extern int Player_Card[N_MAX_USER];;

int Card_Offer()
{
		int Player_Card[PLAY_NUMBER];
		int i;
		
		do{
		
		for(i=1;i=2;i++)
		{
			Dealer_card[i]=rand()%52;
		}
		
		for(i=1;i<=PLAY_NUMBER;i++) //set the card for player
		{
				Player_Card[i]=rand()%52;
		} 
		
		}while(Dealer_card[1]=Dealer_card[2]||Dealer_card[1]=Player[1]||Dealer_card[1]=Player[2]||Dealer_card[1]=Player[3]||Dealer_card[1]=Player[4]||Dealer_card[1]=Player[5]||Dealer_card[2]=Player[1]
||Dealer_card[2]=Player[2]||Dealer_card[2]=Player[3]||Dealer_card[2]=Player[4]||Dealer_card[2]=Player[5]||Player[1]=Player[2]||Player[1]=Player[3]||Player[1]=Player[4]||Player[1]=Player[5]||Player[2]=Player[3]||Player[2]=Player[4||Player[2]=Player[5]||Player[3]=Player[4]||Player[3]=Player[5]||Player[4]=Player[5]);
		//Player number is limited '5'. So the limination arrary number is '5'. 
		//If the card is set to Player 1, that card can't set to oher players.
		
		

}
