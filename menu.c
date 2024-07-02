#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "file_operations.h"
#include "utils.h"
#include "road.h"

void menu1() {
    int choice;
    system("cls");
    box(7, 3, 70, 17);
    gotoxy(10, 5);
    printf("<--:Menu:-->");
    gotoxy(10, 7);
    printf("1 : Sign In.");
    gotoxy(10, 8);
    printf("2 : Sign Up.");
    gotoxy(10, 9);
    printf("3 : Administration.");
    gotoxy(10, 10);
    printf("4 : Exit.");
    gotoxy(10, 14);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: sign_in(); break;
        case 2: sign_up(); break;
        case 3: Administration(); break;
        case 4: exit(0); break;
        default: gotoxy(10, 15); printf("Invalid Choice."); getch(); menu1(); break;
    }
}

void menu2() {
    int choice;
    system("cls");
    box(7, 3, 73, 20);
    gotoxy(10, 5);
    printf("<--:MENU:-->");
    gotoxy(10, 7);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10, 9);
    printf("1 : Add Record.");
    gotoxy(10, 10);
    printf("2 : Search Record.");
    gotoxy(10, 11);
    printf("3 : Exit.");
    gotoxy(10, 17);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: add_record(); break;
        case 2: search_record(); break;
        case 3: exit(0); break;
        default: gotoxy(10, 15); printf("Invalid Choice."); getch(); menu2(); break;
    }
}

void Administration_menu() {
    int choice;
    system("cls");
    box(7, 1, 73, 17);
    gotoxy(10, 3);
    printf("<--:Administration Menu:-->");
    gotoxy(10, 5);
    printf("1 : Add.");
    gotoxy(10, 6);
    printf("2 : View.");
    gotoxy(10, 7);
    printf("3 : Modify.");
    gotoxy(10, 8);
    printf("4 : Delete.");
    gotoxy(10, 9);
    printf("5 : Exit.");
    gotoxy(10, 10);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: add_record_admin(); break;
        case 2: view_records(); break;
        case 3: modify_record(); break;
        case 4: delete_record(); break;
        case 5: exit(0); break;
        default: gotoxy(10, 15); printf("Invalid Choice."); getch(); Administration_menu(); break;
    }
}

void Administration() {
    int choice;
    system("cls");
    box(7, 1, 73, 15);
    gotoxy(10, 3);
    printf("<--:Administration:-->");
    gotoxy(10, 5);
    printf("1 : Login.");
    gotoxy(10, 6);
    printf("2 : Exit.");
    gotoxy(10, 12);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: login(); break;
        case 2: exit(0); break;
        default: gotoxy(10, 17); printf("Invalid Choice."); getch(); Administration(); break;
    }
}

void sign_up() {
    struct road std;
    FILE *fp;
    system("cls");
    box(7, 3, 65, 20);
    gotoxy(10, 5);
    puts("<--:Create Account:-->");
    gotoxy(10, 7);
    printf("Enter User Name:  ");
    scanf("%s", std.uname);
    gotoxy(10, 8);
    printf("Enter Phone Number:  ");
    scanf("%s", std.uphone);
    gotoxy(10, 9);
    printf("Enter User Id:  ");
    scanf("%s", std.user_id);
    gotoxy(10, 10);
    printf("Enter Password:  ");
    scanf("%s", std.password);
    fp = fopen("account.txt", "ab");
    if (fp == NULL) {
        printf("\nError opening file\n");
        exit(1);
    }
    fwrite(&std, sizeof(struct road), 1, fp);
    fclose(fp);
    system("cls");
    box(2, 2, 55, 14);
    gotoxy(5, 5);
    printf("Account Created Successfully.");
    gotoxy(5, 11);
    printf("Press any key to continue...");
    getch();
    sign_in();
}

void sign_in() {
    char user_id[50], password[50];
    FILE *fp;
    struct road std;
    system("cls");
    box(7, 3, 70, 17);
    gotoxy(10, 6);
    printf("<--:LOGIN TO YOUR ACCOUNT:-->");
    gotoxy(11, 8);
    printf("Enter User Id: ");
    scanf("%s", user_id);
    gotoxy(11, 9);
    printf("Enter Password: ");
    scanf("%s", password);
    fp = fopen("account.txt", "rb");
    if (fp == NULL) {
        printf("\nFile not found\n");
        gotoxy(11, 14);
        printf("Press any key to go back...");
        getch();
        menu1();
        return;
    }
    while (fread(&std, sizeof(struct road), 1, fp)) {
        if (strcmp(user_id, std.user_id) == 0 && strcmp(password, std.password) == 0) {
            fclose(fp);
            menu2();
            return;
        }
    }
    fclose(fp);
    gotoxy(11, 14);
    printf("Invalid Username or Password");
    box(7, 19, 70, 21);
    gotoxy(10, 20);
    printf("Press any key to go back...");
    getch();
    menu1();
}
