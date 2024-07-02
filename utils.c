#include <windows.h>
#include "utils.h"

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void box(int a, int b, int c, int d) {
    int i, j;
    for (i = a; i < c; i++) {
        gotoxy(i, b); printf("\xcd");
        gotoxy(i, d); printf("\xcd");
    }
    for (j = b; j < d; j++) {
        gotoxy(a, j); printf("\xba");
        gotoxy(c, j); printf("\xba");
    }
    gotoxy(a, b); printf("\xc9");
    gotoxy(c, b); printf("\xbb");
    gotoxy(a, d); printf("\xc8");
    gotoxy(c, d); printf("\xbc");
}

void road_title() {
    system("cls");
    box(7, 6, 73, 22);
    gotoxy(15, 8);
    printf("      ::::::::::  ::::::::      :::     ::::::::::");
    gotoxy(15, 9);
    printf("     :+:    :+: :+:    :+:   :+: :+:   :+:    :+: ");
    gotoxy(15, 10);
    printf("    +:+    +:+ +:+    +:+  +:+   +:+  +:+    +:+  ");
    gotoxy(15, 11);
    printf("   +#++:++#+  +#+    +:+ +#++:++#++: +#+    +:+   ");
    gotoxy(15, 12);
    printf("  +#+    +#+ +#+    +#+ +#+     +#+ +#+    +#+    ");
    gotoxy(15, 13);
    printf(" #+#    #+# #+#    #+# #+#     #+# #+#    #+#     ");
    gotoxy(15, 14);
    printf("#########   ########  ###     ### #########       ");
    gotoxy(22, 18);
    printf("TRAFFIC RECORD MANAGEMENT SYSTEM");
    gotoxy(22, 20);
    printf("Press any key to continue...");
    getch();
}

