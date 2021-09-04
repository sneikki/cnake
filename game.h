#ifndef GAME_H
#define GAME_H

#define ARENA_WIDTH 30
#define ARENA_HEIGHT 30

enum {
    QUIT,
    RESTART,
    PAUSE,
    RUNNING
};

int run(void);
int process(void);
int input(void);
void update(void);
void draw(void);

#endif
