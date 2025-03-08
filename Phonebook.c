#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NameSize 50
#define NumSize 15
#define Size 26

#define Filename "contact.txt"

typedef struct Phonebook
{
    char name[NameSize];
    char number[NumSize];

    struct Phonebook *next;
}Phonebook;

Phonebook *contacts[Size] = {NULL};

int hashfunction(char name[]);
void Insert(char* name, char* number);
Phonebook* Search(char* name, Phonebook **prev);
void Delete(char* name);
void Display();
void SaveContacts();
void LoadContacts();


int main (void)
{
    LoadContacts();
    {
        Display();
        printf("Action? (Search/Add/Delete):\n");

        char name[NameSize],  number[NumSize];
        char answer[7];
        fgets(answer, 7, stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if(strcasecmp(answer, "Add") == 0 || strcasecmp(answer, "add") == 0)
        {
            printf("Enter Name: ");
            fgets(name, NameSize, stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("\n");
            printf("Enter Phone Number: ");
            fgets(number, NumSize, stdin);
            number[strcspn(number, "\n")] = '\0';

            Insert(name, number);
            SaveContacts();
        }

        else if (strcasecmp(answer, "Search") == 0 || strcasecmp(answer, "search") == 0)
        {
            printf("Enter Name: ");
            fgets(name, NameSize, stdin);
            name[strcspn(name, "\n")] = '\0';

            Search(name, NULL);
        }

        else if (strcasecmp(answer, "Delete") == 0 || strcasecmp(answer, "delete") == 0)
        {
            printf("Enter Name: ");
            fgets(name, NameSize, stdin);

            Delete(name);
        }
        else printf("Unidentified Action.\n");
        }
}

int hashfunction(char name[])
{
    char firstLetter = name[0];

    if(islower(firstLetter)) firstLetter = toupper(firstLetter);

    return firstLetter - 'A';
}

void Insert(char* name, char* number)
{
    Phonebook *prev = NULL;

    if(Search(name, &prev))
    {
        printf("\nContact already exists.\n");
        return;
    }


    int index = hashfunction(name);

    Phonebook *newEntry = (Phonebook*) malloc(sizeof(Phonebook));
    if (!newEntry)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);

    newEntry->next = contacts[index];
    contacts[index] = newEntry;
}

Phonebook* Search(char* name, Phonebook **prev)
{
    int index = hashfunction(name);

    Phonebook *temp = contacts[index];
    if (prev!= NULL) *prev = NULL;
    while(temp)
    {
        if(strcmp(temp->name, name) == 0)
        {
            printf("Name : %s\nPhone Number : %s", temp->name, temp->number);
            return temp;
        }
        if(prev!= NULL) *prev = temp;
        temp = temp->next; 
    }
    return NULL;
}

void Delete(char* name)
{
    Phonebook *prev = NULL;
    Phonebook *toDelete = Search(name, &prev);

    if(!toDelete) 
    {
        printf("Couldn't Delete, contact not found.\n");
        return;
    }

    int index = hashfunction(name);

    if (prev == NULL)
    {
        contacts[index] = toDelete->next;
    }

    else 
    {
        prev->next = toDelete->next;
    }

    printf("Contact successfully deleted.\n");
    SaveContacts();
    free(toDelete);
}

void Display()
{
    printf("Contacts.\n    Name:\tPhone Number:\n");

    for (int i = 0; i < Size; i++)
    {
        printf("[%c]:\n", 'A' + i);
        Phonebook *temp = contacts[i];
        
        while(temp)
        {
            printf("    [%s\t%s]\n", temp->name, temp->number);
            temp = temp->next;
        }
    }
    printf("\n");
}

void SaveContacts()
{
    FILE *file = fopen(Filename, "w");

    if(!file)
    {
        printf("Couldn't save contact, try again later.\n");
        return;
    } 

    for (int i = 0; i < Size; i++)
    {
        Phonebook *temp = contacts[i];

        while(temp)
        {
            fprintf(file, "%s,%s\n", temp->name, temp->number);
            temp = temp->next;  
        }
    }

    fclose(file);  
}

void LoadContacts()
{
    FILE *file = fopen(Filename, "r");

    if(!file)
    {
        printf("Couldn't load contact, try again later.\n");
        return;
    } 

    char name[NameSize], number[NumSize];

    while(fscanf(file, "%49[^,],%14[^\n]\n", name, number) == 2)
    {
        Insert(name, number);
    }

    fclose(file);
}