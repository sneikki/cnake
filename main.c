#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "queue.h"
#include "graphics.h"
#include "game.h"

int main(void)
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    init_graphics();

    run();

    close();
}
