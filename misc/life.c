#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_WIDTH 500
#define GRID_HEIGHT 200
#define VIEWPORT_WIDTH  80
#define VIEWPORT_HEIGHT 24

#define LIVE_CELL "█"
#define DEAD_CELL " "

typedef struct {
    bool alive;
    bool next;
} Cell;

Cell grid[GRID_HEIGHT][GRID_WIDTH];
int offsetX = 0, offsetY = 0;

void draw_grid() {
    for (int y = 0; y < VIEWPORT_HEIGHT; y++) {
        for (int x = 0; x < VIEWPORT_WIDTH; x++) {
            int gx = x + offsetX;
            int gy = y + offsetY;
            if (gx >= 0 && gx < GRID_WIDTH && gy >= 0 && gy < GRID_HEIGHT) {
                mvaddstr(y, x, grid[gy][gx].alive ? LIVE_CELL : DEAD_CELL);
            } else {
                mvaddstr(y, x, DEAD_CELL);
            }
        }
    }
    refresh();
}

void update_grid() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            int neighbors = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < GRID_WIDTH && ny >= 0 && ny < GRID_HEIGHT)
                        neighbors += grid[ny][nx].alive;
                }
            }
            if (grid[y][x].alive)
                grid[y][x].next = (neighbors == 2 || neighbors == 3);
            else
                grid[y][x].next = (neighbors == 3);
        }
    }

    for (int y = 0; y < GRID_HEIGHT; y++)
        for (int x = 0; x < GRID_WIDTH; x++)
            grid[y][x].alive = grid[y][x].next;
}

void seed_grid() {
    srand(time(NULL));
    int seed_x = GRID_WIDTH / 2;
    int seed_y = GRID_HEIGHT / 2;
    int count = 0;
    while (count < 30) {
        int x = seed_x - 10 + rand() % 21; // within 21x21 area around center
        int y = seed_y - 10 + rand() % 21;
        if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT && !grid[y][x].alive) {
            grid[y][x].alive = true;
            count++;
        }
    }
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(50);

    seed_grid();

    while (1) {
        draw_grid();
        update_grid();

        int ch = getch();
        if (ch == 'q') break;
        else if (ch == KEY_UP && offsetY > 0) offsetY--;
        else if (ch == KEY_DOWN && offsetY < GRID_HEIGHT - VIEWPORT_HEIGHT) offsetY++;
        else if (ch == KEY_LEFT && offsetX > 0) offsetX--;
        else if (ch == KEY_RIGHT && offsetX < GRID_WIDTH - VIEWPORT_WIDTH) offsetX++;
    }

    endwin();
    return 0;
}