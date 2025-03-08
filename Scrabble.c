#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define Size 45

int letterScores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculateScore (char word[]);

int main (void)
{
	int Score1, Score2;
	char word1[Size], word2[Size];
	
	printf("Player 1 : ");
	scanf("%s", word1);
	
	printf("Player 2 : ");
	scanf("%s", word2);
		
	
	Score1 = calculateScore(word1);
	Score2 = calculateScore(word2);	
	
	
	if (Score1 > Score2)
	{
		printf("Player 1 wins\n");
	}
	
	else if (Score1 < Score2)
	{
		printf("Player 2 wins \n");
	}
	
	else 
	{
		printf("Tie !\n");
	}
}


int calculateScore (char word[])
{
	int score = 0;
	
	for (int i = 0; word[i] != '\0'; i++)
	{
		char ch = toupper(word[i]);
		
		score =+ letterScores[ch - 'A'];
	}
	
	return score;
}