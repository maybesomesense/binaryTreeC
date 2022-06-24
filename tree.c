#include "tree.h"

void InitializeTree(Tree * ptree){
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree){
    if(ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree){
    if(ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree){
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree){
    Trnode * new_node;

    if(TreeIsFull(ptree)){
        fprintf(stderr, "The tree is overflowing");
        return false;
    }

    if(SeekItem(pi,ptree).child != NULL){
        fprintf(stderr, "Attempt to add a duplicate element");
        return false;
    }

    new_node = MakeNode(pi);
    if(new_node == NULL){
        fprintf(stderr, "Failed to create new node");
        return false;
    }

    ptree->size++;

    if(ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    return true;
}

bool InTree(const Item * pi, const Tree * ptree){
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree){
    Pair look;
    look = SeekItem(pi, ptree);
    if(look.child == NULL)
        return false;
    if(look.parent == NULL)
        DeleteNode(&ptree->root);
    else if(look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse(const Tree * ptree, void (*pfun) (Item item)){
    if(ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree){
    if(ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

static void InOrder(const Trnode * root, void (*pfun) (Item item)){
    if(root != NULL){
        InOrder(root->left, pfun);
        (*pfun) (root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * root){
    Trnode * pright;
    if(root != NULL){
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Trnode * new_node, Trnode * root){
    if(ToLeft(&new_node->item, &root->item)){
        if(root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);
    }
    else if(ToRight(&new_node->item, &root->item)) {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else{
        fprintf(stderr, "Location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item * i1, const Item * i2){
    int comp1;
    if((comp1 = strcmp(i1->studentName , i2->studentName)) < 0)
        return true;
    else if(comp1 == 0 && strcmp(i1->studentSpecialty, i2->studentSpecialty) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2){
    int comp1;
    if((comp1 = strcmp(i1->studentName, i2->studentName)) > 0)
        return true;
    else if(comp1 == 0 && strcmp(i1->studentSpecialty, i2->studentSpecialty) > 0)
        return true;
    else
        return false;
}

static Trnode * MakeNode(const Item * pi){
    Trnode * new_node;
    new_node = (Trnode*) malloc(sizeof(Trnode));
    if(new_node != NULL){
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree){
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if(look.child == NULL)
        return look;

    while(look.child != NULL){
        if(ToLeft(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->left;
        }

        else if(ToRight(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->right;
        }

        else
            break;
    }
    return look;
}

static void DeleteNode(Trnode **ptr){
    Trnode * temp;

    if((*ptr)->left == NULL){
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }

    else if ((*ptr)->right == NULL){
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }

    else{
        for(temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

char menu(void){
    int ch;
    puts("================================================================================================");
    puts("Dean's office\n");
    puts("a) Add student           b) Show list of students");
    puts("d) Amount of students    c) Find students");
    puts("e) Delete student        q) Exit");
    puts("f) Write info about students to binary file");
    puts("g) Reading info about students from binary file");
    puts("================================================================================================");
    while((ch = getchar()) != EOF){
        while(getchar() != '\n')
            continue;
        ch = tolower(ch);
        if(strchr("abcdefgq", ch) == NULL)
            puts("Enter a, b, c, d, e, f, g or q");
        else
            break;
    }

    if(ch == EOF)
        ch = 'q';

    return ch;
}

void addStudent(Tree * pt){
    Item temp;

    if(TreeIsFull(pt))
        puts("No place to add students");
    else{
        puts("Enter the name, surname and patronymic of the student:");
        s_gets(temp.studentName, 20);
        s_gets(temp.studentSurname, 20);
        s_gets(temp.studentPatronymic, 20);
        puts("Enter the specialty of student");
        s_gets(temp.studentSpecialty, 20);
        uppercase(temp.studentName);
        uppercase(temp.studentSurname);
        uppercase(temp.studentPatronymic);
        uppercase(temp.studentSpecialty);
        AddItem(&temp, pt);
    }
}

void showStudents(const Tree * pt){
    if(TreeIsEmpty(pt))
        puts("No entries");
    else
        Traverse(pt, printItem);
}

void printItem(Item item){
    printf("Student: %-19s %-19s %-19s\nSpecialty of student: %-19s\n", item.studentName, item.studentSurname, item.studentPatronymic, item.studentSpecialty);
}

void findStudent(const Tree * pt){
    Item temp;

    if(TreeIsEmpty(pt)){
        puts("No entries");
        return;
    }

    puts("Enter the name, surname and patronymic of the student you want to find:\n");
    s_gets(temp.studentName,       20);
    s_gets(temp.studentSurname,    20);
    s_gets(temp.studentPatronymic, 20);
    puts("Enter the student's specialty:\n");
    s_gets(temp.studentSpecialty,  20);
    uppercase(temp.studentName);
    uppercase(temp.studentSurname);
    uppercase(temp.studentPatronymic);
    uppercase(temp.studentSpecialty);
    printf("%s by the name %s", temp.studentSpecialty, temp.studentName);
    if(InTree(&temp, pt))
        printf("is a club member.\n");
    else
        printf("isn't a club member\n");
}

void dropStudent(Tree * pt){
    Item temp;

    if(TreeIsEmpty(pt)){
        puts("No entries");
        return;
    }
    puts("Enter the name, surname, patronymic of the student to be excluded from the dean's office:");
    s_gets(temp.studentName,       20);
    s_gets(temp.studentSurname,    20);
    s_gets(temp.studentPatronymic, 20);
    puts("Enter the type of student:");
    s_gets(temp.studentSpecialty,  20);
    uppercase(temp.studentName);
    uppercase(temp.studentSpecialty);
    printf("%s by the name %s", temp.studentSpecialty, temp.studentName);
    if(DeleteItem(&temp, pt))
        printf("Expelled from the dean's office. \n");
    else
        printf("Not listed in the dean's office.\n");
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

void writingInfoToFile(const Tree* students) {     // записываем в бинарный файл
    FILE* output;

    if (!fopen_s(&output, "binaryFile", "w+")) {
        fwrite(students, sizeof(*students), 1, output);
        fclose(output);
    }
    else {
        printf("File corrupted");
        exit(EXIT_FAILURE);
    }
}

void readingInfoToFile(Tree** originalTree) {            // записываем из бинарного файла в структуру
    FILE* output;

    int count;
    if (!fopen_s(&output, "binaryFile", "rb+"))
    {
        fseek(output, 0, SEEK_END);
        count = (ftell(output)) / sizeof(**originalTree);
        fseek(output, 0, SEEK_SET);
        *originalTree = (Tree*)calloc(count, sizeof(Tree));
        int i = 0;
        fread(*originalTree, sizeof(**originalTree), count, output);
        fclose(output);
    }
    else {
        printf("File corrupted");
        exit(EXIT_FAILURE);
    }
}
