#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int line_count = 0;

typedef struct bookdata
{
    int no_of_copies;
    int book_id;
    char name_of_book[50];
}book; 

void return_book(book *b, int book_id)
    {
        int i, flag = 0;
        for(i = 0 ; i < line_count ; i++)
            {
                if(b[i].book_id == book_id)
                    {
                        flag = 1;
                        printf("Thankyou customer. Please place the book on the shelf.\n\n");
                        b[i].no_of_copies++;
                        break;
                    }
            }
        if(!flag)
            {
                printf("Book id is not correct. Please try again\n\n");
                return;
            }
    }

void borrow_book(book *b, int book_id)
    {
        int i, flag = 0;
        for(i = 0 ; i < line_count ; i++)
            {
                if(b[i].book_id == book_id)
                    {
                        flag = 1;
                        if(b[i].no_of_copies > 0)
                            {
                                printf("Congratulations customer your book is allocated. Please collect it from the shelf\n\n");
                                b[i].no_of_copies--;
                                break;
                            }
                        else
                            {
                                printf("This book is presently not on our shelf. Please try later\n\n");
                                break;
                            }
                    }
            }
        if(!flag)
            {
                printf("Book id is not correct. Please try again\n\n");
                return;
            }
    }

void display_book_shelf(book *b)
{
    printf("#no_of_copies_available\t book_id \t name_of_book \n\n");
    for(int i = 0 ; i < line_count ; i++)
        printf("\t%d\t\t    %d\t    %s\n", b[i].no_of_copies, b[i].book_id, b[i].name_of_book);
    printf("\n");
}

void read_db(book *b)
    {
        FILE *db;
        db = fopen("books_database.txt","r");
        int i = 0;
        char line[50];
        while(!feof(db))
            {
                fscanf(db, "%d %d", &b[i].no_of_copies, &b[i].book_id);
                fgets(line, 50, db);
                strcpy(b[i].name_of_book, line);
                i++;
            }
        line_count = i;
        fclose(db);               
    }

void write_db(book *b)
    {
        FILE *db;
        db = fopen("books_database.txt","w");

        int i = 0;

        while(i < line_count)
            {
                fprintf(db, "%d  %d", b[i].no_of_copies, b[i].book_id);
                fprintf(db, "%s",  b[i].name_of_book);
                i++;
            }
        fclose(db);
    }

int main()
{
    fflush(stdin);
    book b[100];
    int option = 0, book_id = 0;
    char search_name[20];

    read_db(b);

    while(option < 4 || !option)
    {
        printf("-------------- MENU -------------- \n\n");
        printf("1. View list of books on our shelves\n");
        printf("2. Request for a new book\n");
        printf("3. Return a book\n");
        printf("4. EXIT\n");
        scanf("%d",&option);
        getchar();
        switch(option)
        {
            case 1: printf("---- List of Books ----\n\n");
                    display_book_shelf(b);
                    break;
            case 2: printf("\n---- Borrow Book ----\n\n");
                    printf("Enter book id of the book you want to borrow: ");
                    scanf("%d", &book_id);
                    printf("\n");
                    borrow_book(b, book_id);
                    break;
            case 3: printf("\n---- Return Book ----\n\n");
                    printf("Enter book id of the book you want to return: ");
                    scanf("%d", &book_id);
                    printf("\n");
                    return_book(b, book_id);
                    break;
            case 4: write_db(b);
                    exit(0);
                    break;
            default: printf("\nWrong input! Try again\n\n");
                     break;
        }
    }
    
    return 0;
}