#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void createfile();
void readfile();
void writefile();
void appendfile();
void deletefile();
void listoffiles();
void menu();

int main()
{
    int choice;

    printf("FILE MANAGEMENT SYSTEM:\n");

    do
    {
        menu();
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createfile();
            break;

        case 2:
            readfile();
            break;

        case 3:
            writefile();
            break;

        case 4:
            appendfile();
            break;

        case 5:
            deletefile();
            break;

        case 6:
            listoffiles();
            break;

        case 7:
            menu();
            break;

        case 8:
            printf("Exiting the system...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 8);

    return 0;
}

// MENU
void menu()
{
    printf("\n==============================\n");
    printf("1. Create File\n");
    printf("2. Read File\n");
    printf("3. Write into File\n");
    printf("4. Append into File\n");
    printf("5. Delete File\n");
    printf("6. Display List of Files\n");
    printf("7. Display Menu\n");
    printf("8. Exit\n");
    printf("==============================\n");
}

// CREATE FILE
void createfile()
{
    char filename[300];

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *pointer = fopen(filename, "w");

    if (pointer == NULL)
    {
        printf("File not created!\n");
        return;
    }

    printf("File '%s' created successfully.\n", filename);

    fclose(pointer);
}

// READ FILE
void readfile()
{
    char filename[300];
    int ch;

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("File not found!\n");
        return;
    }

    printf("\n----- File Content -----\n");

    while ((ch = fgetc(fptr)) != EOF)
    {
        putchar(ch);
    }

    printf("\n------------------------\n");

    fclose(fptr);
}

// WRITE FILE
void writefile()
{
    char filename[250];
    char datawritten[2000];

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *fptr = fopen(filename, "w");

    if (fptr == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    getchar(); // Remove newline left by scanf

    printf("Enter data:\n");
    fgets(datawritten, sizeof(datawritten), stdin);

    fprintf(fptr, "%s", datawritten);

    fclose(fptr);

    printf("Data written successfully.\n");
}

// APPEND FILE
void appendfile()
{
    char filename[250];
    char datawritten[2000];

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *fptr = fopen(filename, "a");

    if (fptr == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    getchar(); // Remove newline left by scanf

    printf("Enter data:\n");
    fgets(datawritten, sizeof(datawritten), stdin);

    fprintf(fptr, "%s", datawritten);

    fclose(fptr);

    printf("Data appended successfully.\n");
}

// DELETE FILE
void deletefile()
{
    char filename[250];

    printf("Enter the file name: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("File could not be deleted.\n");
    }
}

// DISPLAY FILES
void listoffiles()
{
    struct dirent *entry;
    DIR *dr = opendir(".");

    if (dr == NULL)
    {
        printf("Could not open current directory.\n");
        return;
    }

    printf("\nFiles in current directory:\n\n");

    while ((entry = readdir(dr)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dr);
}
