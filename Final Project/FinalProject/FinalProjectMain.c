//Authors: David Rosman and Matthew Meschberger
//Date Created: April 14th, 2015

//This program is a hangman game in which the player guesses letters until the initialized puzzle
//is revealed after all of the letters that it contains have been guessed.

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int find_letter(char Storage[], char Displayword[], char input)
{
	int count = 0;
	int i;

	for (i = 0; Storage[i] != '\0'; i++)//check for the letter and write it back into the origional array
	{
		if (Storage[i] == input)//check exact match
		{
			Displayword[i] = Storage[i]; count++;
		}
		else if (isupper(Storage[i]))//check upper
		{
			if (Storage[i] == toupper(input))
			{
				Displayword[i] = Storage[i]; count++;
			}
		}
		else if (islower(Storage[i]))//check lower
		{
			if (Storage[i] == tolower(input))
			{
				Displayword[i] = Storage[i]; count++;
			}
		}
	}

	return count;
}

int main(void)
{

	
	char word[] = "CHEESE AND CRACKERS";
	char wordSto[50];
	char clue[50] = "clue";
	char letterList[28] = "";//list of guessed letters
	int i = 0;
	int j = 0;
	char checkChar = ' ';
	int goodInput = 0;
	int cnt = 0; //number of times letter is found in the search

	//FILE *file;

	//file = fopen("fortune_codes.txt", "r");

	//fclose(file);

	for (i = 0; word[i] != '\0'; i++)//replace all letters with '_' in the origional array and transfer the words to another array
	{
		if (isspace(word[i]))
		{
			wordSto[i] = word[i];
		}
		else if (isalpha(word[i]))
		{
			wordSto[i] = word[i];
			word[i] = '_';
		}
		else if(isprint(word[i]))
		{
			wordSto[i] = word[i];
		}
			
	}
	wordSto[i] = '\0';//add null termination char to end of string



	printf("Hi, let's play Hangman. The clue is: %s\nThe secret puzzle is:\n", clue);//start hangman
	printf("%s\n", word);//print out the new stuff

	
	
	while (strcmp(wordSto, word) != 0)//iterate until the the whole word is found
	{
		while (goodInput == 0)
		{
			printf("Guess a letter: ");
			fflush(stdin);
			scanf("%c", &checkChar);//enter the letter to check

			if (isprint(checkChar))
			{
				if ((strchr(letterList, checkChar) == NULL))//if letter is not in list
				{
					goodInput = 1;
				}
				else
				{
					printf("This letter has already been guessed.\n");
				}
			}
			else
			{
				printf("Please enter a proper character.\n");
			}
		}
		goodInput = 0;
	
		cnt = find_letter(wordSto, word, checkChar);//run the function to find each letter

		if(cnt == 0) //if the letter did not appear
		{
			printf("Letter %c is not part of the secret puzzle\n", checkChar);//notify player
		}
		else 
		{
			printf("Letter %c was found %d times in the secret puzzle\n\n", checkChar,cnt);//otherwise print number of occurences
		}

		printf("%s\n", word);//print out the new stuff
		
		
		letterList[strlen(letterList)] = checkChar;
		letterList[strlen(letterList) + 1] = '\0';
		
		printf("Letters already guessed: ");
		for (i = 0; i < strlen(letterList); i++)
		{
			printf("%c ", letterList[i]);
		}
		

		printf("\n\n");
	}

	printf("Congratulations! You solved the puzzle: %s\n", wordSto);
	
	return 0;
}


/*


for (i = 0; wordSto[i] != '\0'; i++)//check for the letter and write it back into the origional array
{
if (wordSto[i] == checkChar)//check exact match
{
word[i] = wordSto[i]; cnt++;
}
else if (isupper(wordSto[i]))//check upper
{
if (wordSto[i] == toupper(checkChar))
{
word[i] = wordSto[i]; cnt++;
}
}
else if (islower(wordSto[i]))//check lower
{
if (wordSto[i] == tolower(checkChar))
{
word[i] = wordSto[i]; cnt++;
}
}
}

*/