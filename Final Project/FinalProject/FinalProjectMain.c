#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
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
	char word[] = "The quick brown fox jumps over the lazy dog";
	char wordSto[50];
	int i = 0;
	char checkChar = ' ';
	int cnt = 0; //number of times letter is found in the search

	for (i = 0; word[i] != '\0'; i++)//replace all letters with '_' in the origional array and transfer the words to another array
	{
		if (isspace(word[i]))
		{
			wordSto[i] = word[i];
		}
		if (isalpha(word[i]))
		{
			wordSto[i] = word[i];
			word[i] = '_';
		}
	}

	wordSto[i] = '\0';//add null termination char to end of string

	printf("Hang Man \n\n");
	printf("%s\n", word);//print out the new stuff

	printf("Guess a letter: ");
	scanf("%c", &checkChar);//enter the letter to check
	
	cnt = find_letter(wordSto, word, checkChar);


	printf("%s\n", word);//print out the new stuff
	//printf("%s\n", wordSto);
	printf("Letter was found %d times\n", cnt);

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