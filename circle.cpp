#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200, yc = 300;

    circle(xc, yc, 100);

    // circle(xc, yc, 90);
    // circle(xc, yc, 70);

    getch();
    closegraph();
    return 0;
}
