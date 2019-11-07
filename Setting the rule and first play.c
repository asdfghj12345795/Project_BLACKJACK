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

int CardTray[N_CARDSET*N_CARD]; //mix the cards and set the array of cards
int cardIndex=0;
int RE_START_ROUND() //say that the game is restarting 
{

printf("-----------------------------------------\n-----------ROUND %d(CardIndex : %d)---------------------\n", N_ROUND, cardIndex);

} 


int RANDOM_B_PLAYER() // Ramdom betting system for other players
{
	int B_max = N_DOLLAR; //setting the definition to bet
	int B_price;
	
	srand((unsigned)time(NULL));
	B_price = 1+rand()%B_max;
	
	return (B_price);
}

int BETTING_SET() //Betting for play
{
	int bet_user; // betting price for user
	int i;
	int bet[N_MAX_USER];//array the betting pricce for other players
	
	printf("-----betting step-----\n");
	printf("   -> your betting (total : %d) : ", N_DOLLAR);
	scanf("%d", &bet_user);

	for(i=1;i<=PLAY_NUMBER-1;i++)
	{
		bet[i]= RANDOM_B_PLAYER();
		printf("   -> player %d bets $%d (out of $%d)\n", i, bet[i], N_DOLLAR);
	}
	
	printf("---------------------\n");	 
}

int main()
{
	PLAY_NUM();
	RE_START_ROUND();
	BETTING_SET();
	
	return 0;
}

