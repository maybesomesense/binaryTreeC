#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXITEMS 100

typedef struct item{
    char studentName[20];
    char studentSurname[20];
    char studentPatronymic[20];
    char studentSpecialty[20];
}Item;

typedef struct trnode{
    Item item;
    struct trnode* left;
    struct trnode* right;
}Trnode;

typedef struct tree{
    Trnode * root;
    int size;
}Tree;

typedef struct pair{
    Trnode * parent;
    Trnode * child;
}Pair;

void InitializeTree(Tree * ptree);
bool TreeIsEmpty(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
int TreeItemCount(const Tree* ptree);
bool AddItem(const Item * pi, Tree * ptree);
bool InTree(const Item * pi, const Tree * ptree);
bool DeleteItem(const Item * pi, Tree * ptree);
void Traverse(const Tree * ptree, void (*pfun) (Item item));
void DeleteAll(Tree * ptree);
//
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Trnode * new_code, Trnode * root);
static void InOrder(const Trnode * root, void (*pfun) (Item item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode ** ptr);
static void DeleteAllNodes(Trnode * ptr);
//
char menu(void);
void addStudent(Tree *pt);
void dropStudent(Tree *pt);
void showStudents(const Tree * pt);
void findStudent(const Tree * pt);
void printItem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

void writingInfoToFile(const Tree*);
void readingInfoToFile(Tree**);