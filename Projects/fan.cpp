#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define PI 3.14159265

void drawFan(int fanCenterX, int fanCenterY, int angle, int fanspeed) {
    
    line(fanCenterX, 0, fanCenterX, fanCenterY - 12);// rod from ceiling to fan center
    circle(fanCenterX, fanCenterY, 13); // outer cricle

    for (int i = 0; i < 3; i++) { // Draw three blades
        int bladeAngle = angle + i * 120;
        double rad = bladeAngle * PI / 180.0;        
        int bladeLength = 80;
        int xEnd = fanCenterX + (int)(bladeLength * cos(rad));
        int yEnd = fanCenterY + (int)(bladeLength * sin(rad));
        
        line(fanCenterX, fanCenterY, xEnd, yEnd);
    }
    
    // Show control instructions on screen
    char instructions[100];
    int fs = fanspeed; 
    sprintf(instructions, "Fan Speed: %d | 's': Start, 'd': Stop, '+'/'-': Speed, 'm': Move, 'q': Quit", fs);
    outtextxy(10, getmaxy() - 20, instructions);
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int fanCenterX = getmaxx() / 2; // set the initial position near the center of the screen
    int fanCenterY = 120;  
    int fanSpeed = 5;
    int angle = 0;       // Blade angular position(in degrees)
    bool rotating = false; 

    while (true) {
        // Process key events if any
        if (kbhit()) {
            char key = getch();
            if (key == 's' || key == 'S') {
                rotating = true;
            } else if (key == 'd' || key == 'D') {
                rotating = false;
            } else if (key == '+' || key == '=') {
                if (fanSpeed < 40)
                    fanSpeed += 1;
            } else if (key == '-' || key == '_') {
                if (fanSpeed > 1)
                    fanSpeed -= 1;
            } else if (key == 'm' || key == 'M') {                
                fanCenterX += 20;                 
                if(fanCenterX > getmaxx() - 50)//Bounce back if it moves out of the window bounds
                    fanCenterX = 50;
            } else if (key == 'q' || key == 'Q') {
                break;
            }
        }        
        if (rotating) { // Update the rotation if fan is on
            angle = (angle + fanSpeed) % 360;
        }
        cleardevice();
        drawFan(fanCenterX, fanCenterY, angle, fanSpeed);
        
        delay(50);  // pauses execution for 50 milliseconds
    }

    closegraph();
    return 0;
}