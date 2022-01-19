#include <ncurses.h>

int main(int argc, char **argv)
{
    initscr();
    int row = 25, col = 80;
    // creating a window;
    // with height = 25 and width = 80
    // also with start x axis = 2 and start y axis = 10
    WINDOW *win = newwin(25, 80, 2, 10);
    refresh();

    noecho(); // not let input show on a screen.
    curs_set(FALSE); // hide cursor

    keypad(stdscr, TRUE);
    while(1){
        int input = getch();
        clear();
        switch(input){
            case KEY_UP:
                mvprintw(--row, col, "/O\\"); // real moving in your screen
                continue;
            case KEY_DOWN:
                mvprintw(++row, col, "\\0/");
                continue;
            case KEY_LEFT:
                mvprintw(row, --col, "<0|");
                continue;
            case KEY_RIGHT:
                mvprintw(row, ++col, "|0>");
                continue;

        }
        if(input == 'q') break;
    }

    endwin();
    return 0;
}