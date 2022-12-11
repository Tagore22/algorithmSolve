#include <iostream>
#include <vector>
#include <algorithm>

//Ǯ��
//ó������ �־��� S��ŭ �տ��� ���� ���������� �ϴ� ������ �����ߴµ� �ʹ� ����������, �䵵 ���� �ʾҴ�.
//��¥ Ǯ�̴� �� ù��° ���Һ��� �迭�� ��ȸ�ϸ� �־��� S���� ���ų� ���� �̵��ؼ� i��° ���ҷ� �̵� ������
//���� ū ���Ҹ� ã�ư��� �̵���Ű�� ���̴�.
//��, ù��° ���� ���� 2��° ���Һ��� ��ȸ�ϸ� S���ȿ� ù��° ���ҷ� �̵� ������ ���� ū ���Ҹ� ã�� ù��° ���ҷ� �ΰ�
//�̰��� �� ������ ���ұ��� �ݺ��ϴ� ���̴�.

using namespace std;

vector<int> board;
int N, S;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        int max_num = board[i]; //���� ���� ū ����
        int max_idx = i;        //���� ū ������ �ε�����

        for (int j = i + 1; j < N; ++j)
            if (max_num < board[j] && j - i <= S) //i��° ���ұ��� �̵������� ������ ���� ū���� ã�´�.
            {
                max_num = board[j];
                max_idx = j;
            }

        S -= max_idx - i;
        board.erase(board.begin() + max_idx);
        board.insert(board.begin() + i, max_num);

        if (S == 0)
            break;
    }

    for (auto& a : board)
        cout << a << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        board.push_back(num);
    }
    cin >> S;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}