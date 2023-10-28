#include <stdio.h>
// 打印游戏棋盘
void printBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// 检查是否有玩家获胜
int checkWin(char board[3][3], char player) {
    // 检查行
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // 检查列
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // 检查对角线
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int currentPlayer = 1;  // 当前玩家，1 表示玩家 X，2 表示玩家 O
    int moves = 0;  // 已下棋步数

    while (1) {
        // 打印当前棋盘
        printBoard(board);

        // 获取当前玩家的行动
        int row, col;
        printf("玩家 %c，请输入行号和列号（例如：1 1 表示第一行第一列）：", (currentPlayer == 1) ? 'X' : 'O');
        scanf("%d %d", &row, &col);

        // 检查行动的合法性
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("无效的行动，请重新输入。\n");
            continue;
        }

        // 更新棋盘
        board[row - 1][col - 1] = (currentPlayer == 1) ? 'X' : 'O';
        moves++;

        // 检查是否有玩家获胜
        if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O')) {
            printf("玩家 %c 获胜！\n", (currentPlayer == 1) ? 'X' : 'O');
            break;
        }

        // 检查是否平局
        if (moves == 9) {
            printf("平局！\n");
            break;
        }

        // 切换到下一个玩家
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
