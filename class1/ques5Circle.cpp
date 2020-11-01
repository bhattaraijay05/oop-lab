// 5. Create a structure circle, with suitable attributes and functions, assume (functions name only) different colors to draw the circle, and fill the c
#include "msoftcon.h"
struct circle
{
    int xCo, yCo;
    int radius;
    color fillColor;
    fstyle fillstyle;
};

void circ_draw(circle c)
{
    set_color(c.fillColor);
    set_fill_style(c.fillstyle);
    draw_circle(c.xCo, c.yCo, c.radius);
}

int main()
{
    init_graphics();

    circle c1 = {15, 7, 5, cBLUE, X_FILL};
    circle c2 = {15, 7, 5, cRED, 0_FILL};
    circle c3 = {15, 7, 5, cGREEN, MEDIUM_FILL};

    circ_draw(C1);
    circ_draw(C2);
    circ_draw(C3);
    set_cursor_pos(1, 25);
    return 0;
}