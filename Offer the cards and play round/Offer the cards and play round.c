hynhjh#include <stdio.h>
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
int Card_set[N_CARD] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52}; //total card is 52
int Dollar[N_MAX_USER];
int Round_B_price[N_MAX_GO][N_MAX_USER]; //The betting amount variable of the player in the field.
int Player_Card[N_MAX_GO][N_MAX_USER]; // [i][j] : ith card of j player
int Dealer_card[N_MAX_GO]; //[j] : jth card of dealer


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


int Matching_the_card_number(int number_array) // decide the number (1~K,Q,J) of cards
{
	int Card_set[number_array];
	int check; // Variable being able to through the division.
	int confirm =13; /// Number of confirmation.
	int number; // variable of the card number
	
	check = number_array%13;
	
	switch(chack){
		
		case 0:
			printf("1");
			break;
		
		case 1:
			printf("2");
			break;
		
		case 2:
			printf("3");
			break;
		
		case 3:
			printf("4");
			break;
		
		case 4:
			printf("5");
			break;

		case 5:
			printf("6");
			break;

		case 6:
			printf("7");
			break;

		case 7:
			printf("8");
			break;

		case 8:
			printf("9");
			break;

		case 9:
			printf("10");
			break;
	
		case 10:
			printf("king");
			break;

		case 11:
			printf("Queen");
			break;

		case 12:
			printf("Jack");
			break;
			
	}

	return 0;

}
	

int Matching_the_card_shape(int number_array)//decide the shape of card like ��������.
{
	int Card_set[number_array];
	int check; // Variable being able to through the division.
	int confirm =13; /// Number of confirmation.
	char shape; // express the shape
	char HEA, SPA, CLV, DIA;
	
	check = number_array/confirm;
	
	switch(check)
	{
		case 0:
			shape = HEA; 
			break;
		
		case 1:
			shape = SPA;
			break;
		
		case 2:
			shape = CLV;
			break;
			 
		case 3:
			shape = DIA;	 		
			break;	
	}
	
	return (shape);		
} 


extern int Player_Card[N_MAX_GO][N_MAX_USER];

extern int Dealer_card[N_MAX_GO]; 


int Card_Offer_1()//Give the card each player.
{
		int Player_Card[N_MAX_GO][N_MAX_USER];
		int Dealer_card[N_MAX_GO];
		int i;
		int j;
		int h;//function that set for player to give two cards. 
		do{
		for(i=1;i<3;i++)
		{
			srand((unsigned)time(NULL));
			Dealer_card[i]=rand()%52;
		} } while(Dealer_card[1]=Dealer_card[2]);
		
		do
		{	
			for(h=1;h<3;h++) //function that set for player to give two cards.
			{
				for(j=1;j<PLAY_NUMBER;j++)
			{
				srand((unsigned)time(NULL));
				Player_Card[h][j]=rand()%52;
			}
		}
		
		}while(Dealer_card[1]=Dealer_card[2]||Dealer_card[1]=Player[1]||Dealer_card[1]=Player[2]||Dealer_card[1]=Player[3]||Dealer_card[1]=Player[4]||Dealer_card[1]=Player[5]||Dealer_card[2]=Player[1]
||Dealer_card[2]=Player[2]||Dealer_card[2]=Player[3]||Dealer_card[2]=Player[4]||Dealer_card[2]=Player[5]||Player[1]=Player[2]||Player[1]=Player[3]||Player[1]=Player[4]||Player[1]=Player[5]||Player[2]=Player[3]||Player[2]=Player[4||Player[2]=Player[5]||Player[3]=Player[4]||Player[3]=Player[5]||Player[4]=Player[5]);
		//Player number is limited '5'. So the limination arrary number is '5'. 
		//If the card is set to Player 1, that card can't set to oher players.
			
		return 0;
}

int Card_SHOW_1() // card showing on the first game set.
{
	int i;
	Card_Offer_1();
	
	printf("------------- CARD OFFERING ---------------\n");


	printf(" delear : X %c%d", Matching_the_card_shape(Dealer_card[2]), Matching_the_card_number(Dealer_card[2]));
	printf(" -> you : %c%d %c%d", Matching_the_card_shape(Player_Card[1][1]), Matching_the_card_number(Player_Card[1][1]), Matching_the_card_shape(Player_Card[2][1]), Matching_the_card_number(Player_Card[2][1]));	
	
	
	for(i=2;i<=PLAY_NUMBER;i++)
		{
		printf(" -> player %d : %c%d %c%d", i, Matching_the_card_shape(Player_Card[1][i]), Matching_the_card_number(Player_Card[1][i]), Matching_the_card_shape(Player_Card[2][i]), Matching_the_card_number(Player_Card[2][i]));
		
		}
	return 0;
}
