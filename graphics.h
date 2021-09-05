#include "queue.h"

#define MIN_WINDOW_WIDTH 80
#define MIN_WINDOW_HEIGHT 40

void init_graphics(void);
void draw(void);
int check_win_size(void);

void draw_arena(int width, int height);
void draw_apple(int x, int y);
void draw_snake(queue *snake);
void draw_text(char *text);
void color_on(int color);
void color_off(int color);

void close(void);
