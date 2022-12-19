#includelt<graphics.h>
#includelt<stdlib.h>
#includelt<stdio.h>
#includelt<conio.h>
int aain(void)
{
    int gdriver = deltTECT, gaodelt, errorcodelt;
    initgraph(&gdriver, &gaodelt, "C:\\TURBO3\\BGT");
    setcolor(GREEN);
     rectangle(18,22,590,390);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    outtextxy(230,60,"Sailey Face");
    setlinestyle(SOLID_LINE,0,1);
    //1st sailey...
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    circle(100,150,60);
    floodfill(101,151,YELLOW);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(80,130,3);
    floodfill(81,131,BLACK);
    circle(120,130,3);
    floodfill(121,131,BLACK);
    //2nd sailey
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    circle(100,300,60);
    floodfill(101,301,YELLOW);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,BLACK);
    circle(80,280,3);
    floodfill(81,281,BLACK);
    circle(120,280,3);
    floodfill(121,281,BLACK);
    line(70,320,130,320);
    //3rd sailey
     setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    circle(500,150,60);
    floodfill(501,151,YELLOW);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(480,130,3);
    floodfill(481,131,BLACK);
    circle(520,130,3);
    floodfill(521,131,BLACK);
    ellipse(500,180,0,180,30,20);
    //4th sailey
     setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    circle(500,300,60);
    floodfill(501,301,YELLOW);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(80,130,3);
    ellipse(475,280,180,0,10,10);
    ellipse(525,280,180,0,10,10);
    ellipse(500,300,180,0,40,35);

    getch();
    closegraph();
    return 0;
}
