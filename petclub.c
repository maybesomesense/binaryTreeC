#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);



int main(void) {
    Tree pets;
    char choice;
    InitializeTree(&pets);
    while((choice = menu()) != 'q'){
        switch (choice) {
            case 'a' : addpet(&pets);
                break;
            case 'l' : showpets(&pets);
                break;
            case 'f' : findpet(&pets);
                break;
            case 'n' : printf("%d animals in the club \n", TreeItemCount(&pets));
                break;
            case 'd' : droppet(&pets);
                break;
            default: puts("Error in switch");
        }
    }
    DeleteAll(&pets);
    puts("Program is end");
    return 0;
}

char menu(void){
    int ch;
    puts("Nerfville Pet Club");
    puts("a) Add animal           1) Show list of animals");
    puts("n) Amount of animals    f) Find animals");
    puts("d) Delete animal        q) Exit");

    while((ch = getchar()) != EOF){
        while(getchar() != '\n')
            continue;
        ch = tolower(ch);
        if(strchr("alrfndq", ch) == NULL)
            puts("Enter a, l, f, n, d or q");
        else
            break;
    }

    if(ch == EOF)
        ch = 'q';

    return ch;
}

void addpet(Tree * pt){
    Item temp;

    if(TreeIsFull(pt))
        puts("There are no more seats in the club");
    else{
        puts("Enter the name of the animal:");
        s_gets(temp.petname, (int)strlen(temp.petname));
        puts("Enter the type of animal");
        s_gets(temp.petkind, (int) strlen(temp.petkind));
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt){
    if(TreeIsEmpty(pt))
        puts("No entries");
    else
        Traverse(pt, printitem);
}

void printitem(Item item){
    printf("Animal: %-19s Type: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree * pt){
    Item temp;

    if(TreeIsEmpty(pt)){
        puts("No entries");
        return;
    }

    puts("Enter the name of the animal you want to find:");
    s_gets(temp.petname, (int)strlen(temp.petname));
    puts("Enter the type of animal:");
    s_gets(temp.petkind, (int) strlen(temp.petkind));
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s by the name %s", temp.petkind, temp.petname);
    if(InTree(&temp, pt))
        printf("is a club member.\n");
    else
        printf("isn't a club member\n");
}

void droppet(Tree * pt){
    Item temp;

    if(TreeIsEmpty(pt)){
        puts("No entries");
        return;
    }
    puts("Enter the name of the animal to be excluded from the club:");
    s_gets(temp.petname, (int) strlen(temp.petname));
    puts("Enter the type of animal:");
    s_gets(temp.petkind, (int) strlen(temp.petkind));
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s by the name %s", temp.petkind, temp.petname);
    if(DeleteItem(&temp, pt))
        printf("Expelled from the club. \n");
    else
        printf("not a club member.\n");
}

void uppercase(char* str){
    while(*str){
        *str = toupper(*str);
        str++;
    }
}

char* s_gets(char* st, int n){
    char* ret_val;
    char* find;

    ret_val = fgets(st, n, stdin);
    if(ret_val){
        find = strchr(st, '\n');
        if(find)
            *find = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}