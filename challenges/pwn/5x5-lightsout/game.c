#include <stdio.h>
#include <string.h>

void print_flag() {
  char flag[64] = "FLAG_HERE\0";
  printf("here you go: %s", flag);
}


void show_board(char* board, int size) {
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      char row = board[y];
      int bit = row & (1 << x);

      if (bit) {
        putchar('#');
      } else {
        putchar('.');
      }
    }
    putchar('\n');
  }
  putchar('\n');
}

void flip(char* board, int position, int size) {
  int x = position & 0xf;
  int y = position >> 4;
  if (y > 0) {
    board[y - 1] ^= 1 << x;
  }
  int mask = 0b11;
  if (x > 0) {
    mask = 0b111 << (x - 1);
  }
  board[y] ^= mask;
  if (y < 15) {
    board[y + 1] ^= 1 << x;
  }
}


int play_game() {
  struct {
    char padding[8];
    int position;
    int x, y;
    char command;
    unsigned int size;
    char *board;
    char aboard[8];
  } data;

  puts("Welcome to 5x5!");

  data.board = &data.aboard[0];

  data.size = 5;
  do {
      printf("Board size (1 to 8)? ");
      scanf("%d", &data.size);
  } while (data.size > 8);

  memset(data.board, 0, data.size);

  while (1) {
    show_board(data.board, data.size);
    printf("[f <x> <y>/h/q]: ");

    do {
      scanf("%c", &data.command);
    } while (data.command != 'f' && data.command != 'h' && data.command != 'q');

    switch (data.command) {
    case 'h':
      puts("The objective of this game is to turn on all the cells");
      puts("Your only move is to change a flip a cell");
      puts("However, when you filp a cell, the four cells around it get flipped too");
      puts("Type `f <x> <y>' to flip a cell or `q' to give up");
      puts("Have fun!");
      break;
    case 'q':
      return 0;
    case 'f':
      scanf("%d", &data.x);
      scanf("%d", &data.y);
      data.position = data.x | (data.y << 4);

      flip(data.board, data.position, data.size);
      break;
    }
  }
  return 0;
}

void thanks() {
  puts("Thanks for playing!");
}

void good_job() {
  puts("You won! Good job");
}

int main() {
  setbuf(stdout, NULL);
  fflush(stdin);

  char *exit_message = "Bye!";

  puts("Welcome to Emacs Lite!");
  puts("Implemented commands in this version are: M-x 5x5");
  puts("Press enter to run M-x 5x5");

  int won;
  scanf("%c", (char*) &won);

  won = play_game();

  if (won) {
    exit_message = "Good job, you won!";
  }

  printf("%s\n", exit_message);
}
