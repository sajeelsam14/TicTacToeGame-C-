#include <iostream>
using namespace std;

void drawBoard(char *board) {
  cout << *board << "|" << *(board + 1) << "|" << *(board + 2) << endl;
  cout << "______" << endl;
  cout << *(board + 3) << "| " << *(board + 4) << "|" << *(board + 5) << endl;
  cout << "______" << endl;
  cout << *(board + 6) << "| " << *(board + 7) << "|" << *(board + 8) << endl;
}

void placment(char *board, char *token) {
  int position;
  if (*token == 'x') {
    cout << "player one turn" << endl << "Enter the position: ";
    cin >> position;
    if (position >= 0 && position <= 8) {
      if (board[position] != 'x' && board[position] != 'o') {
        board[position] = 'x';
        *token = 'o';
      } else {
        cout << "Place already filled" << endl;
        placment(board, token);
      }
    } else {
      cout << "Invalid position" << endl;
      placment(board, token);
    }
  } else {
    cout << "player second turn" << endl << "Enter the position: ";
    cin >> position;
    if (position >= 0 && position <= 8) {
      if (board[position] != 'x' && board[position] != 'o') {
        board[position] = 'o';
        *token = 'x';
      } else {
        cout << "Place already filled" << endl;
        placment(board, token);
      }
    } else {
      cout << "Invalid position" << endl;
      placment(board, token);
    }
  }
}

bool isDraw(char *board) {
  if (*board == '0' || *(board + 1) == '1' || *(board + 2) == '2' ||
      *(board + 3) == '3' || *(board + 4) == '4' || *(board + 5) == '5' ||
      *(board + 6) == '6' || *(board + 7) == '7' || *(board + 8) == '8') {
    return true;
  } else {
    return false;
  }
}

bool conclusion(char *board, char *token) {
  if (((*board == *(board + 1)) && (*(board + 1) == *(board + 2))) ||
      ((*(board + 3) == *(board + 4)) && (*(board + 4) == *(board + 5))) ||
      ((*(board + 6) == *(board + 7)) && (*(board + 7) == *(board + 8))) ||
      ((*board == *(board + 3)) && (*(board + 3) == *(board + 6))) ||
      ((*(board + 1) == *(board + 4)) && (*(board + 4) == *(board + 7))) ||
      ((*(board + 2) == *(board + 5)) && (*(board + 5) == *(board + 8)))) {
    if (*token == 'x') {
      cout << "player2 win";
    } else {
      cout << "player1 win";
    }
    return false;
  } else if (((*board == *(board + 4)) && (*(board + 4) == *(board + 8))) ||
             ((*(board + 2) == *(board + 4)) &&
              (*(board + 4) == *(board + 6)))) {
    if (*token == 'x') {
      cout << "player2 wins";
    } else {
      cout << "player1 wins";
    }
    return false;
  } else {
    if (isDraw(board)) {
      return true;
    } else {
      cout << "match Draw";
      return false;
    }
  }
}
int main() {
  char board[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
  char token = 'x';
  drawBoard(board);
  while (conclusion(board, &token)) {
    placment(board, &token);
    drawBoard(board);
  }
  cout << "\nProgram Terminated";
  return 0;
}
