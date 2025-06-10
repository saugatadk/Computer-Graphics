#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;

    circle(xc, yc, 90);

    circle(xc, yc, 70);


    getch();
    closegraph();
    return 0;
}
