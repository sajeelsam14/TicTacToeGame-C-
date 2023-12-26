#include <iostream>
using namespace std;
char board[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
char token = 'x';
int position;
void drawBoard() {
  cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
  cout << "______" << endl;
  cout << board[3] << "| " << board[4] << "|" << board[5] << endl;
  cout << "______" << endl;
  cout << board[6] << "| " << board[7] << "|" << board[8] << endl;
}
void placment() {
  if (token == 'x') {
    cout << "player one turn" << endl << "Enter the position: ";
    cin >> position;
    if (position >= 0 && position <= 8) {
      if (board[position] != 'x' && board[position] != 'o') {
        board[position] = 'x';
        token = 'o';
      } else {
        cout << "Place already filled" << endl;
        placment();
      }
    } else {
      cout << "Invalid position" << endl;
      placment();
    }
  } else {
    cout << "player second turn" << endl << "Enter the position: ";
    cin >> position;
    if (position >= 0 && position <= 8) {
      if (board[position] != 'x' && board[position] != 'o') {
        board[position] = 'o';
        token = 'x';
      } else {
        cout << "Place already filled" << endl;
        placment();
      }
    } else {
      cout << "Invalid position" << endl;
      placment();
    }
  }
}
bool isDraw() {
  if (board[0] == '0' || board[1] == '1' || board[2] == '2' ||
      board[3] == '3' || board[4] == '4' || board[5] == '5' ||
      board[6] == '6' || board[7] == '7' || board[8] == '8') {
    return true;
  } else {
    return false;
  }
}
bool conclusion() {
  if (((board[0] == board[1]) and (board[1] == board[2])) or
      ((board[3] == board[4]) and (board[4] == board[5])) or
      ((board[6] == board[7]) and (board[7] == board[8])) or
      ((board[0] == board[3]) and (board[3] == board[6])) or
      ((board[1] == board[4]) and (board[4] == board[7])) or
      ((board[2] == board[5]) and (board[5] == board[8]))) {
    if (token == 'x') {
      cout << "player2 win";
    } else {
      cout << "player1 win";
    }
    return false;
  } else if (((board[0] == board[4]) and (board[4] == board[8])) or
             ((board[2] == board[4]) and (board[4] == board[6]))) {
    if (token == 'x') {
      cout << "player2 wins";
    } else {
      cout << "player1 wins";
    }
    return false;
  } else {
    if (isDraw()) {
      return true;
    } else {
      cout << "match Draw";
      return false;
    }
  }
}
int main() {
  drawBoard();
  while (conclusion()) {
    placment();
    drawBoard();
  }
  cout << "Program Terminated";
  return 0;
}