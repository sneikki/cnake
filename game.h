#ifndef GAME_H
#define GAME_H

#define ARENA_WIDTH 40
#define ARENA_HEIGHT 40

#define QUIT_KEY 'q'
#define RESTART_KEY 'r'
#define PAUSE_KEY 'p'
// #define UP_KEY 'k'
// #define DOWN_KEY 'j'
// #define LEFT_KEY 'h'
// #define RIGHT_KEY 'l'
#define UP_KEY KEY_UP
#define DOWN_KEY KEY_DOWN
#define LEFT_KEY KEY_LEFT
#define RIGHT_KEY KEY_RIGHT

enum {
    QUIT,
    RESTART,
    PAUSE,
    RUNNING,
    GAME_OVER,
    INTERRUPT
};

int run(void);
int process(void);
int input(void);
void update(void);
void draw(void);

#endif
