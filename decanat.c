#include "tree.h"

int main() {
    Tree* info;
    Tree students;
    char choice;
    InitializeTree(&students);
    while((choice = menu()) != 'q'){
        switch (choice) {
            case 'a' :
                addStudent(&students);           //
                break;
            case 'b' :
                showStudents(&students);         //
                break;
            case 'c' :
                findStudent(&students);          //
                break;
            case 'd' : printf("%d student in dean's office \n", TreeItemCount(&students));
                break;
            case 'e' :
                dropStudent(&students);          //
                break;
            case 'f' :
                writingInfoToFile(&students);    //
                break;
            case 'g' :
                readingInfoToFile(&info);    //
                showStudents(info);
                break;
            default: puts("Error in switch\n");
        }
    }
    DeleteAll(&students);                        //
    puts("Program is end");
    return 0;
}