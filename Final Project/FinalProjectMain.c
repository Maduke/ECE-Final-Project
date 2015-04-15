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

	FILE *file;
	char word[] = "The quick brown fox jumps over the lazy dog";
	char wordSto[50];
	char clue[50] = "clue";
	char letterGuess[100];
	int i = 0;
	int j = 0;
	char checkChar = ' ';
	int cnt = 0; //number of times letter is found in the search

	file = fopen("fortune_codes.txt", "r");

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

	//for(i=0;i<50;++i) {
		//if(!isalpha(wordSto[i]) && )
		//{



	printf("Hi, let's play Hangman. The clue is: %s\nThe secret puzzle is:\n", clue);
	printf("%s\n", word);//print out the new stuff

	for(i=0;i<52;++i) {
	
	
	printf("Guess a letter: ");
	fflush(stdin);
	scanf("%c", &checkChar);//enter the letter to check
	letterGuess[i] = checkChar;
	
	cnt = find_letter(wordSto, word, checkChar);
	if(cnt == 0) {
		printf("Letter %c is not part of the secret puzzle\n", checkChar);
	}
	else {
	printf("Letter %c was found %d times in the secret puzzle\n\n", checkChar,cnt);
	}
	printf("%s\n", word);//print out the new stuff
	//printf("%s\n", wordSto);
	printf("Letter already guessed: \n");

	printf("\n");

	
	if(strcmp(word,wordSto)== 0) {
		break;
	}
	}

	printf("Congratulations! You solve the puzzle: %s\n", wordSto);
	fclose(file);
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