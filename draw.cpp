#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    line(50, 75, 480, 570);
    line(0, 0, 250, 250);

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    putpixel(centerX, centerY, WHITE);
    getch();

    closegraph();
    return 0;
}
