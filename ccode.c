#include<stdio.h>
#include<string.h>  
#include<ctype.h>

struct dictionary {
    char word[50];  
    char meaning[100];  
};

//global declarations
struct dictionary d[100];
int num = 0; 
int i;// variable for loop



//to add words and meanings into the dictionary
void addintodict(){
    printf("Enter the word:\n");
    scanf("%s", d[num].word);
    printf("Enter the meaning:\n ");
    scanf("%s", d[num].meaning);
    printf("Added word into the dictionary\n");
}
// to display entire set of words and meanings from the dictionary
void displaydict(){
    
    if (num==0){
        printf("The Dictionary is empty\n");
    }
    else{
    printf("The words in the given dictionary\n\n");
    printf("WORD\t\tMEANING\n");
    for (i=0;i<num;i++){
        printf("%s",d[i].word);printf("\t\t\t");
        printf("%s",d[i].meaning);printf("\n\n");}
    }
}

//to display words that start only with the specified character
void displaywithstartchar(){
    char firstchr;int count=0;
    printf("Please enter the first character of the word:\n");
    scanf(" %c",&firstchr);printf("\n");
    printf("WORD\t\tMEANING\n");
    for (i=0;i<num;i++){
        if (((d[i].word)[0])==firstchr){
             printf("%s",d[i].word);printf("\t\t\t");
            printf("%s",d[i].meaning);printf("\n\n");
            num++;
            
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
    scanf("%s",wordtofind);
    for (i=0;i<num;i++){
        if (strcmp(d[i].word,wordtofind)==0){
            printf("Meaning:");printf("%s",d[i].meaning);printf("\n");
        }
    }
    
}

//function to update meaning
void updatemeaning(){
    char wordtoupdate[50];
    int p=0;
    printf("Please enter the word whose meaning has to be changed:\n");
    scanf("%s",wordtoupdate);
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

    for (int i = 0; i < num; i++) {
        if (strcmp(d[i].word, wordtodel) == 0) {
            for (j = i; j < num - 1; j++) {
                strcpy(d[j].word, d[j + 1].word);
                strcpy(d[j].meaning, d[j + 1].meaning);
            }
            p = 1;
            printf("Entered word has been deleted from the dictionary\n");
            num--;  // Decrement the number of words after deletion
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
