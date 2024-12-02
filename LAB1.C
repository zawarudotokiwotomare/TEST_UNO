#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

void scroll(int x1, int y1, int x2, int y2) {
    int height = y2 - y1 + 1;
    char buffer[80 * 25];
    gettext(x1, y1, x2, y2, buffer);
    puttext(x1, y1 - 1, x2, y2 - 1, buffer);
    gotoxy(1, height);
    clreol();
}

void colorInfo(int background, int foreground) {
    char* colors[] = { "BLACK", "BLUE", "GREEN", "CYAN",
        "RED", "MAGENTA", "BROWN", "LIGHTGRAY",
        "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN","LIGHTCYAN",
        "LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE" };
    cprintf("Background: %d; Color: %s", background, colors[background], colors[foreground]);
}

void main() {
    int x1 = 10, y1 = 5, x2 = 70, y2 = 15;
    int background = 0, foreground = 0;
    window(x1, y1, x2, y2);
    clrscr();
    system("cls");
    for (background = 0; background < 8; background++) {
        for (foreground = 0; foreground < 16; foreground++) {
            if (background == foreground) continue;
            textbackground(background);
            textcolor(foreground);
            scroll(x1, y1, x2, y2);
            gotoxy(1, y2 - y1 + 1);
            colorInfo(background, foreground);
            delay(300);
            textbackground(BLACK);
        }
    }
    textbackground(BLACK);
    textcolor(LIGHTGRAY);
    window(1, 1, 80, 25);
    clrscr();
}