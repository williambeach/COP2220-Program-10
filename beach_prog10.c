/* William Beach
 * COP2220 Intro to Programming in C
 * user defined struct implementing functions from program 8 and knowledge applied from program 9 - November 15, 2022
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define SIZE 30

typedef struct {
	char word[SIZE];
	char upperCase[SIZE];
	char reverse[SIZE];
	int length, numVowels;
}wordInfo;

void greeting(char name[]); //greets user and stores their name
void getWord(char input[], char copy[]); //gets word from user and stores a copy of the word
void uppercaseWord(char upper[]); //takes in a word and uppercases all of its letters
int countVowels(char upper[]); //displays number of each vowel and its index location, returns total number of vowels
void reverseTheWord(char upper[], char reverse[]); //reverses word
void saveToFile(FILE *outPtr, wordInfo wordList[], int num);

int main() {
    char firstName[30], word[30], copyOfWord[30], upperCase[30], reversed[30], sentinel;
    wordInfo wordList[SIZE];
    int count = 0;
    FILE outPtr;
    greeting(firstName);
    printf("%s, Would you like to enter a word? 'y' (YES) 'n' (NO) ", firstName);
    scanf(" %c", &sentinel);
    while (sentinel != 'n') {
        getWord(word, copyOfWord);
        uppercaseWord(copyOfWord);
        strcpy(upperCase, copyOfWord);
        reverseTheWord(upperCase, reversed);
        printf("Printing the words in the main function:\n");
        printf("original word: %s\n", word);
        printf("uppercase: %s\n", upperCase);
        printf("reverse: %s\n", reversed);
        int totalVowels = countVowels(upperCase);
        printf("The total number of vowels is %d\n", totalVowels);
        printf("----------------------------------------------\n");
        strcpy(wordList[count].word, word);
        strcpy(wordList[count].upperCase, upperCase);
        strcpy(wordList[count].reverse, reversed);
        wordList[count].length = strlen(word);
        wordList[count].numVowels = totalVowels;
        count++;
        printf("%s, Would you like to enter a word? 'y' (YES) 'n' (NO) ", firstName);
        scanf(" %c", &sentinel);
    }
    saveToFile(&outPtr, wordList, count);
    printf("Thank you, %s, have a great day!", firstName);
    return 0;
};


void greeting(char name[]) {
    printf("Hello there, please enter your first name: \n");
    scanf(" %s", name);
    printf("***  Welcome to the character array practice program  ***\n");
    printf("---------------------------------------------------------\n");
};

void getWord(char input[], char copy[]) {
    printf("Please enter a word: ");
    scanf(" %s", input);
    strcpy(copy, input);
};

void uppercaseWord(char upper[]) {
    int i;
    int length = strlen(upper);
    for (i = 0; i < length; i++) {
        upper[i] = toupper(upper[i]);
    }
};

int countVowels(char upper[]) {
    int j;
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    int length = strlen(upper);
    for (j = 0; j < length; j++) {
        switch (upper[j]) {
            case 'A':
                printf("There is an 'A' located at index %d\n", j);
                a += 1;
                break;
            case 'E':
                printf("There is an 'E' located at index %d\n", j);
                e += 1;
                break;
            case 'I':
                printf("There is an 'I' located at index %d\n", j);
                i += 1;
                break;
            case 'O':
                printf("There is an 'O' located at index %d\n", j);
                o += 1;
                break;
            case 'U':
                printf("There is an 'U' located at index %d\n", j);
                u += 1;
                break;
        }
    }
    printf("The total number of A's is %d\n", a);
    printf("The total number of E's is %d\n", e);
    printf("The total number of I's is %d\n", i);
    printf("The total number of O's is %d\n", o);
    printf("The total number of U's is %d\n", u);
    printf("Printing the total number of vowels in the main function: \n");
    return a + e + i + o + u;
};

void reverseTheWord(char upper[], char reverse[]) {
    int i, count = 0;
    int length = strlen(upper);
    for (i = length - 1; i >= 0; i--) {
        reverse[count] = upper[i];
        count++;
    }
    reverse[length] = '\0';
};

void saveToFile(FILE *outPtr, wordInfo wordList[], int num) {
    int i;
    printf("Saving all the information in the word list to the output file\n");
    outPtr = fopen("wordsProg10.txt", "w");
    for (i = 0; i < num; i++) {
        fprintf(outPtr, "Struct %d\n\n", i + 1);
        fprintf(outPtr, "The input word was: %s\n", wordList[i].word);
        fprintf(outPtr, "The input word has %d letters\n", wordList[i].length);
        fprintf(outPtr, "The uppercase version is: %s\n", wordList[i].upperCase);
        fprintf(outPtr, "The reverse is: %s\n", wordList[i].reverse);
        fprintf(outPtr, "The total number of vowels is: %d\n\n", wordList[i].numVowels);
    }
    fclose(outPtr);
};