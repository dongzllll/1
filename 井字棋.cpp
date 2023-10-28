#include <stdio.h>
// ��ӡ��Ϸ����
void printBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

// ����Ƿ�����һ�ʤ
int checkWin(char board[3][3], char player) {
    // �����
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // �����
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // ���Խ���
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

    int currentPlayer = 1;  // ��ǰ��ң�1 ��ʾ��� X��2 ��ʾ��� O
    int moves = 0;  // �����岽��

    while (1) {
        // ��ӡ��ǰ����
        printBoard(board);

        // ��ȡ��ǰ��ҵ��ж�
        int row, col;
        printf("��� %c���������кź��кţ����磺1 1 ��ʾ��һ�е�һ�У���", (currentPlayer == 1) ? 'X' : 'O');
        scanf("%d %d", &row, &col);

        // ����ж��ĺϷ���
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("��Ч���ж������������롣\n");
            continue;
        }

        // ��������
        board[row - 1][col - 1] = (currentPlayer == 1) ? 'X' : 'O';
        moves++;

        // ����Ƿ�����һ�ʤ
        if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O')) {
            printf("��� %c ��ʤ��\n", (currentPlayer == 1) ? 'X' : 'O');
            break;
        }

        // ����Ƿ�ƽ��
        if (moves == 9) {
            printf("ƽ�֣�\n");
            break;
        }

        // �л�����һ�����
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
