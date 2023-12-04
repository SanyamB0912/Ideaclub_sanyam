#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct dictionary {
    char word[50];    // stores the word
    char meaning[200]; // stores the meaning
};

// Global declarations
struct dictionary *d = NULL; // global declaration of the structure as a pointer
int num = 0;                 // counts the number of words in the dictionary
int i;                       // Variable for loop

// Function to compare two words for qsort
int compareWords(const void *a, const void *b) {
    return strcmp(((struct dictionary *)a)->word, ((struct dictionary *)b)->word);
}

// Function to add words and meanings into the dictionary
void addintodict() {
    struct dictionary *temp = realloc(d, (num + 1) * sizeof(struct dictionary)); // adding values into the dict

    if (temp == NULL) { // if memory allocation fails
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    d = temp; // assignment
    char wordintodict[50];
    char meaningofword[200];
    // Now you can add the new entry to the dictionary
    printf("Enter the word:\n");

    fgets(wordintodict, sizeof(wordintodict), stdin);
    wordintodict[strcspn(wordintodict, "\n")] = '\0'; // Remove newline character

    for (i = 0; i < strlen(wordintodict); i++) {
        if (i == 0) {
            d[num].word[i] = toupper(wordintodict[0]);
        } else {
            d[num].word[i] = tolower(wordintodict[i]);
        }
    }
    printf("Enter the meaning:\n");
    fgets(meaningofword, sizeof(meaningofword), stdin);
    meaningofword[strcspn(meaningofword, "\n")] = '\0'; // Remove newline character

    for (i = 0; i < strlen(meaningofword); i++) {
        if (i == 0) {
            d[num].meaning[i] = toupper(meaningofword[0]);
        } else {
            d[num].meaning[i] = tolower(meaningofword[i]);
        }
    }
    printf("Added word into the dictionary\n");

    // Sort the dictionary to maintain the order
    qsort(d, num + 1, sizeof(struct dictionary), compareWords);

    num++;
}

// to display entire set of words and meanings from the dictionary
void displaydict() {
    if (num == 0) {
        printf("The Dictionary is empty\n");
    } else {
        printf("The words in the given dictionary\n\n");
        printf("WORD\t\tMEANING\n");
        for (i = 0; i < num; i++) {
            printf("%s", d[i].word);
            printf("\t\t\t");
            printf("%s", d[i].meaning);
            printf("\n");
        }
    }
}


//to display words that start only with the specified character
void displaywithstartchar(){
    char firstchr;int count=0;
    printf("Please enter the first character of the word:\n");
    scanf(" %c",&firstchr);printf("\n");
    printf("WORD\t\tMEANING\n");
    for (i=0;i<num;i++){
        if (((d[i].word)[0])==toupper(firstchr)){
             printf("%s",d[i].word);printf("\t\t\t");
            printf("%s",d[i].meaning);printf("\n");
            
            count++;
            
        }
    }
    if (count==0){
        printf("No word starting with the given character found\n");
    }
}

//function to display only words in the function
void dispwords(){
    int p=0;
    if (num==0){
        printf("Empty dictionary\n");
    }
    else{
        printf("\n");
        printf("WORDS\n");
        for (i=0;i<num;i++){
            printf("%s",d[i].word);printf("\n");
            p=1;
        }
    }
    if (p==0){
        printf("WORD NOT FOUND");
    }
}

//to display meaning of entered word
void dispmeaning(){
    char wordtofind[50];
    printf("Please enter the word whose meaning to be found:\n");
    int p=0;
    scanf("%s",wordtofind);
    wordtofind[0]=toupper(wordtofind[0]);
   
    for (i=0;i<num;i++){
       
        
        if (strcmp(wordtofind,d[i].word)==0){
            printf("Meaning:");printf("%s",d[i].meaning);printf("\n");
            p=1;
        }
    }
    if (p==0){
        printf("NO such word found!\n");
    }
    
}

//function to update meaning
void updatemeaning(){
    char wordtoupdate[50];
    int p=0;
    printf("Please enter the word whose meaning has to be changed:\n");
    scanf("%s",wordtoupdate);
    wordtoupdate[0]=toupper(wordtoupdate[0]);
    
    
    for (i=0;i<num;i++){
        if (strcmp(d[i].word,wordtoupdate)==0){
            printf("Enter new meaning:\n");
            scanf("%s",&d[i].meaning);
            printf("Meaning updated\n");
            p=1;
            break;
        }
    }
    if (p==0){
        printf("NO SUCH WORD FOUND!\n");
    }
}

//function to delete a given word
void deleteword() {
    char wordtodel[50];
    int j;
    int p = 0;

    printf("Enter the word that has to be deleted:\n");
    scanf("%s", wordtodel);
    wordtodel[0]=toupper(wordtodel[0]);

    for (int i = 0; i < num; i++) {
        if (strcmp(d[i].word, wordtodel) == 0) {
            
            for (j = i; j < num - 1; j++) {
                d[j] = d[j + 1];
            }
            
            printf("Entered word has been deleted from the dictionary\n");
            p = 1;num--;
            break;
        }
    }

    if (p == 0) {
        printf("Sorry, no such word found!\n");
    }
}







int main() {
    int choice;
    char choice_tocontinue;

    while (1) {
        printf("Enter 1 to add words into the dictionary\n");
        printf("Enter 2 to  view all words and their meanings from the dictionary\n");
        printf("Enter 3 to find words that starts with a given character\n");
        printf("Enter 4 to view all words from the dictionary\n");
        printf("Enter 5 to find meaning of a word\n");
        printf("Enter 6 to update meaning of a given word\n");
        printf("Enter 7 to delete elements from the dictionary\n");
        printf("Enter choice: ");
        scanf("%d", &choice);  

        if (choice == 1) {
            addintodict(num);
            num++;  
        }
        else if (choice==2){
            displaydict();
        }
        else if (choice==3){
            displaywithstartchar();
        }
        else if (choice==4){
            dispwords();
        }
        else if (choice==5){
            dispmeaning();
        }
        else if (choice==6){
            updatemeaning();
        }
        else if (choice==7){
            deleteword();
        }
        else{
            break;
        }
        printf("Do you wish to continue?(Y/N)\n");
        scanf(" %c",&choice_tocontinue);
        if (choice_tocontinue=='N' || choice_tocontinue=='n'){
            printf("Thank you!\n");printf("OUT OF DICTIONARY\n");break;
        }
        else if (choice_tocontinue=='Y' || choice_tocontinue=='y'){
            printf(" ");
        }
        
        else{
            printf("INVALID INPUT\n");printf("OUT OF DICTIONARY\n");
            break;
        }
    }

    
    

    return 0;
}
