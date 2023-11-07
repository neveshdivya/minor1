#include <stdio.h>
#include <string.h>

// Function prototypes
void adminLogin();
void studentLogin();

// Global variables
char adminUsername[] = "admin";
char adminPassword[] = "admin";
char studentUsername[] = "student";
char studentPassword[] = "student";

// Admin functions
void addBook();
void deleteBook();
void seeNumberOfBooks();
void issueBook();
void resetPassword();

// Student functions
void seeIssuedBooks();

int main()
{
    int choice;
    while (1)
    {
        printf("\nLibrary Management System\n");
        printf("1. Admin Login\n");
        printf("2. Student Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            studentLogin();
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void adminLogin()
{
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, adminUsername) == 0 && strcmp(password, adminPassword) == 0)
    {
        int adminChoice;
        while (1)
        {
            printf("\nAdmin Menu\n");
            printf("1. Add Book\n");
            printf("2. Delete Book\n");
            printf("3. See Number of Books\n");
            printf("4. Issue Book\n");
            printf("5. Reset Password\n");
            printf("6. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &adminChoice);
            printf("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");

            switch (adminChoice)
            {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                seeNumberOfBooks();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                resetPassword();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    else
    {
        printf("Invalid username or password. Please try again.\n");
    }
}

void studentLogin()
{
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n ");

    if (strcmp(username, studentUsername) == 0 && strcmp(password, studentPassword) == 0)
    {
        int studentChoice;
        while (1)
        {
            printf("\nStudent Menu\n");
            printf("1. See Issued Books\n");
            printf("2. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &studentChoice);

            switch (studentChoice)
            {
            case 1:
                seeIssuedBooks();
                break;
            case 2:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    else
    {
        printf("Invalid username or password. Please try again.\n");
    }
}

#define MAX_BOOKS 100

// Structure to hold book information
struct Book
{
    char title[100];
    char author[50];
    int available;
};

// Array to store books
struct Book books[MAX_BOOKS];
int numBooks = 0;

void addBook()
{
    if (numBooks < MAX_BOOKS)
    {
        printf("Enter title: ");
        scanf(" %[^\n]s", books[numBooks].title);
        printf("Enter author: ");
        scanf(" %[^\n]s", books[numBooks].author);
        books[numBooks].available = 1;
        numBooks++;
        printf("Book added successfully!\n");
    }
    else
    {
        printf("Maximum number of books reached!\n");
    }
}

void deleteBook()
{
    char title[100];
    int i, found = 0;

    if (numBooks == 0)
    {
        printf("No books available for deletion.\n");
        return;
    }

    printf("Enter the title of the book you want to delete: ");
    scanf(" %[^\n]s", title);

    for (i = 0; i < numBooks; i++)
    {
        if (strcmp(title, books[i].title) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        // Remove the book by overwriting it with the last book in the array
        books[i] = books[numBooks - 1];
        numBooks--;
        printf("Book '%s' has been deleted.\n", title);
    }
    else
    {
        printf("Book '%s' not found.\n", title);
    }
}

void seeNumberOfBooks()
{
    // Implementation for seeing the number of books
    printf("See Number of Books function is not implemented.\n");
}

void issueBook()
{
    char title[100];
    int i, found = 0;

    if (numBooks == 0)
    {
        printf("No books available for issuing.\n");
        return;
    }

    printf("Enter the title of the book you want to issue: ");
    scanf(" %[^\n]s", title);

    for (i = 0; i < numBooks; i++)
    {
        if (strcmp(title, books[i].title) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        if (books[i].available == 1)
        {
            books[i].available = 0;
            printf("Book '%s' has been issued.\n", title);
        }
        else
        {
            printf("Book '%s' is already issued.\n", title);
        }
    }
    else
    {
        printf("Book '%s' not found.\n", title);
    }
}

void resetPassword()
{
    // Implementation for resetting passwords
    printf("Reset Password function is not implemented.\n");
}

void seeIssuedBooks()
{
    int i, issuedCount = 0;

    printf("Issued Books:\n");
    for (i = 0; i < numBooks; i++)
    {
        if (books[i].available == 0)
        {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("\n");
            issuedCount++;
        }
    }

    if (issuedCount == 0)
    {
        printf("No books have been issued.\n");
    }
}
