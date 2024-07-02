
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"
#include "utils.h"
#include "road.h"

// Function to add a record
void add_record() {
    struct road record;
    FILE *fp = fopen("records.txt", "ab");
    if (fp == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    system("cls");
    box(7, 3, 65, 20);
    gotoxy(10, 5);
    puts("<--:Add Record:-->");
    gotoxy(10, 7);
    printf("Enter Name: ");
    scanf("%s", record.uname);
    gotoxy(10, 8);
    printf("Enter Phone Number: ");
    scanf("%s", record.uphone);
    gotoxy(10, 9);
    printf("Enter User ID: ");
    scanf("%s", record.user_id);
    gotoxy(10, 10);
    printf("Enter Password: ");
    scanf("%s", record.password);

    fwrite(&record, sizeof(struct road), 1, fp);
    fclose(fp);

    gotoxy(10, 14);
    printf("Record added successfully!");
    gotoxy(10, 16);
    printf("Press any key to continue...");
    getch();
}

// Function to search for a record
void search_record() {
    struct road record;
    FILE *fp = fopen("records.txt", "rb");
    char user_id[50];
    int found = 0;

    if (fp == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    system("cls");
    box(7, 3, 65, 20);
    gotoxy(10, 5);
    puts("<--:Search Record:-->");
    gotoxy(10, 7);
    printf("Enter User ID: ");
    scanf("%s", user_id);

    while (fread(&record, sizeof(struct road), 1, fp)) {
        if (strcmp(record.user_id, user_id) == 0) {
            gotoxy(10, 9);
            printf("Name: %s", record.uname);
            gotoxy(10, 10);
            printf("Phone Number: %s", record.uphone);
            gotoxy(10, 11);
            printf("User ID: %s", record.user_id);
            found = 1;
            break;
        }
    }

    if (!found) {
        gotoxy(10, 9);
        printf("Record not found.");
    }

    fclose(fp);
    gotoxy(10, 14);
    printf("Press any key to continue...");
    getch();
}

// Function for admin to add a record
void add_record_admin() {
    struct road record;
    FILE *fp = fopen("records.txt", "ab");
    if (fp == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    system("cls");
    box(7, 3, 65, 20);
    gotoxy(10, 5);
    puts("<--:Admin Add Record:-->");
    gotoxy(10, 7);
    printf("Enter Name: ");
    scanf("%s", record.uname);
    gotoxy(10, 8);
    printf("Enter Phone Number: ");
    scanf("%s", record.uphone);
    gotoxy(10, 9);
    printf("Enter User ID: ");
    scanf("%s", record.user_id);
    gotoxy(10, 10);
    printf("Enter Password: ");
    scanf("%s", record.password);

    fwrite(&record, sizeof(struct road), 1, fp);
    fclose(fp);

    gotoxy(10, 14);
    printf("Record added successfully!");
    gotoxy(10, 16);
    printf("Press any key to continue...");
    getch();
}

// Function to view all records
void view_records() {
    struct road record;
    FILE *fp = fopen("records.txt", "rb");
    if (fp == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    system("cls");
    box(7, 3, 65, 20);
    gotoxy(10, 5);
    puts("<--:View Records:-->");

    int y = 7;
    while (fread(&record, sizeof(struct road), 1, fp)) {
        gotoxy(10, y++);
        printf("Name: %s", record.uname);
        gotoxy(10, y++);
        printf("Phone Number: %s", record.uphone);
        gotoxy(10, y++);
        printf("User ID: %s", record.user_id);
        gotoxy(10, y++);
        printf("--------------------------");
    }

    fclose(fp);
    gotoxy(10, y + 2);
    printf("Press any key to continue...");
    getch();
}

// Function to modify a record
void modify_record() {
    struct road record;
    FILE *fp = fopen("records.txt", "rb+");
    char user_id[50];
    int found = 0;

    if (fp == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    system("cls");
    box(7, 3, 65, 20);
    gotoxy(10, 5);
    puts("<--:Modify Record:-->");
    gotoxy(10, 7);
    printf("Enter User ID: ");
    scanf("%s", user_id);

    while (fread(&record, sizeof(struct road), 1, fp)) {
        if (strcmp(record.user_id, user_id) == 0) {
            gotoxy(10, 9);
            printf("Enter new Name: ");
            scanf("%s", record.uname);
            gotoxy(10, 10);
            printf("Enter new Phone Number: ");
            scanf("%s", record.uphone);
            gotoxy(10, 11);
            printf("Enter new Password: ");
            scanf("%s", record.password);

            fseek(fp, -sizeof(struct road), SEEK_CUR);
            fwrite(&record, sizeof(struct road), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        gotoxy(10, 14);
        printf("Record modified successfully!");
    } else {
        gotoxy(10, 14);
        printf("Record not found.");
    }
    gotoxy(10, 16);
    printf("Press any key to continue...");
    getch();
}

// Function to delete a record
void delete_record() {
    struct road record;
    FILE *fp = fopen("records.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    char user_id[50];
    int found = 0;

    if (fp == NULL || temp == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }

    system("cls");
    box(7, 3, 65, 20);
    gotoxy(10, 5);
    puts("<--:Delete Record:-->");
    gotoxy(10, 7);
    printf("Enter User ID: ");
    scanf("%s", user_id);

    while (fread(&record, sizeof(struct road), 1, fp)) {
        if (strcmp(record.user_id, user_id) != 0) {
            fwrite(&record, sizeof(struct road), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("records.txt");
    rename("temp.txt", "records.txt");

    if (found) {
        gotoxy(10, 10);
        printf("Record deleted successfully!");
    } else {
        gotoxy(10, 10);
        printf("Record not found.");
    }
    gotoxy(10, 12);
    printf("Press any key to continue...");
    getch();
}

void login() {
    char admin_id[20], password[20];
    gotoxy(10, 7);
    printf("Enter Admin Id: ");
    scanf("%s", admin_id);
    gotoxy(10, 8);
    printf("Enter Password: ");
    scanf("%s", password);
    if (strcmp(admin_id, "admin") == 0 && strcmp(password, "admin") == 0) {
        Administration_menu();
    } else {
        gotoxy(10, 10);
        printf("Invalid Id or Password");
        gotoxy(10, 12);
        printf("Press any key to go back...");
        getch();
        Administration();
    }
}
