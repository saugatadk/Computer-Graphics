#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    outtextxy(50, 50, "WRC");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(50, 120, "WRC");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(50, 170, "WRC");

    getch();
    closegraph();
    return 0;
}
