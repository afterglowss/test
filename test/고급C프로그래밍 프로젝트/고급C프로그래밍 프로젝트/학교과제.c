#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 100

typedef struct ContactInfo {
    char name[21];
    char phone[16];
    char birth[9];
} Contact;

void printMainMenu();
void swapContact(Contact* contactData, int index1, int index2);
void sortContact(Contact* contactData, int numContact);
void insertContact(Contact* contactData, int* numContact);
void deleteContact(Contact* contactData, int* numContact);
void printAll(Contact* contactData, int numContact);
void findContactByBirth(Contact* contactData, int numContact);

int main()
{
    Contact contactData[MAXCONTACT];
    int numContact = 0;
    int menu;

    while (1) {
        printMainMenu();
        scanf("%d", &menu);

        switch (menu) {
        case 1: insertContact(contactData, &numContact); //등록
            break;
        case 2: printAll(contactData, numContact); // 보기
            break;
        case 3: deleteContact(contactData, &numContact); //삭제
            break;
        case 4: findContactByBirth(contactData, numContact); //생일자 검색
            break;
        case 5:
            return 0;
        }
    }

    return 0;
}

void printMainMenu()
{
    printf("*****Menu*****\n");
    printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
    printf("Enter_the_menu_number:");
}

void swapContact(Contact* contactData, int index1, int index2)
{
    Contact tmp;
    tmp = contactData[index1];
    contactData[index1] = contactData[index2];
    contactData[index2] = tmp;
}

void sortContact(Contact* contactData, int numContact)
{
    for (int i = 0; i < numContact; i++) {
        for (int j = 0; j < numContact; j++) {
            if (strcmp(contactData[j].name, contactData[j + 1].name) < 0)
                swapContact(contactData, j, j + 1);
        }
        
    }
}

void insertContact(Contact* contactData, int* numContact)
{
    if (*numContact >= MAXCONTACT) {
        printf("OVERFLOW\n");
        return;
    }
    printf("Name:");
    scanf("%s", contactData[*numContact].name);
    printf("Phone_number:");
    scanf("%s", contactData[*numContact].phone);
    printf("Birth:");
    scanf("%s", contactData[*numContact].birth);
    *numContact += 1;
    if (*numContact > 1)
        sortContact(contactData, *numContact);
    printf("<<%d>>\n", *numContact);
}

void printAll(Contact* contactData, int numContact)
{
    for (int i = 0; i < numContact; i++) {
        printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
    }
}

void deleteContact(Contact* contactData, int* numContact)
{
    if (*numContact == 0) {
        printf("NO MEMBER\n"); return;
    }
    char* arr;
    arr = (char*)malloc(21 * sizeof(char));
    printf("Name:");
    scanf("%s", arr);
    for (int i = 0; i < *numContact; i++) {
        if (strcmp(arr, contactData[i].name) == 0) {
            for (int j = i + 1; j < *numContact; j++) {
                contactData[j - 1] = contactData[j];
            }
            *numContact -= 1;
        }
    }
    free(arr);
}

void findContactByBirth(Contact* contactData, int numContact)
{
    int birth;
    printf("Birth:");
    scanf("%d", &birth);
    for (int i = 0; i < numContact; i++) {
        if (birth == contactData[i].birth[5] - '0') {
            printf("%s %s %s\n", contactData[i].name, contactData[i].phone, contactData[i].birth);
        }
    }
}