#include <iostream>
#include <vector>

using namespace std;

// Ǯ��
// ���հ� DFS�� �ݺ��� ���� �����̴�.
// ���� ĥ�� �ִ� ������� 3���� ��� ���� ������ ���������� �ִ밪(0�� ������ ���� ������)�� ���ؾ��Ѵ�.
// �켱 �����ͺ��� �ϳ��ϳ� Ǯ��Ҵ�.

// 1. DFS�� ����
// 2. DFS�� ���̷����� Ȯ�� ���� �����ϴ� ���������� ũ�⸦ ���ϴ� �Լ� ����.
// 3. K���� �� ������ 3���� ��� 2�� �Լ��� ȣ���ϴ� �Լ� ����.

// 1�� �Լ��� �⺻���� DFS�� ũ�� ����� �ʴ�. �¿���Ϸ� �����ϼ� �ִٰ� ������ �����ֱ� ������ 4���� ��쿡 ����
// ���ο� ��ǥ�� ������ �̵��Ҽ� ���� ���(�迭�� �Ѿ�� ���, ������ �����ְų�, �̹� �湮�ߴ� ���)�� �����ϰ�
// �ٽ� ����������� DFS�� ȣ���ϸ� �ȴ�.

// 2�� �Լ��� ���ؼ� ������ ���� 2������ �ʿ��ϴ�.
// 1. �迭�� ������ vector<vector<int>> temp.
// 2. ó�� �Է¹����� ���� 2���� ��ǥ������ ��Ƴ��� vector<pair<int, int>> two.

// ���� ����� �������� ��츶�� DFS�� ��ȸ�ؾ��ϴµ�, DFS�� ���ٺ��� ���̷����� Ȯ��Ǵ� ��쿡 ���� ���� �迭 board�� 
// ���ϰ� �ȴ�. �̸� �ٽ� ���̷��� Ȯ�������� ���� ���Ѿ��ϴµ�, 2�� ������״� ��ǥ���� �ٽ� 0���� �����Ű�� �ȵȴ�. 
// DFS��ȸ�� �̹� ������ ���� �ٽ� �湮�Ҽ��� �ִµ� 0���� �ٽ� ������ױ⿡ �湮�� �̹� �������� �ٽ� �湮�ϱ� �����̴�. 
// �̷��� ������ �ƿ� 2��° �迭�� ���� ���� board�� ���� ����� ��츦 ����ϰ�, temp�� �Ź� board���� �����Ͽ�
// DFS��ȸ���� ����ϸ� ����ϰ� �����Ҽ� �ִ�. 

// ���� ����Ͽ��� DFS��ȸ�� ������ �ؾ��ϱ� ������ �Ź� NXM �迭�� ��ȸ���� �ʰ� Ȯ���� �������� ���̷����� ��ǥ���� ����
// ����Ͽ� DFS��ȸ�� �ϸ� ���ݴ� ���� ������ ����Ҽ� �ִ�. ���� DFS��ȸ ��� temp�� ��ȸ�ϸ� ��������(���� 0�� ��ǥ)��
// ���� ��ȯ�ϸ� �ȴ�.

// 3���Լ��� �������� ��Ʈ��ŷ �Լ��ε� �� �Լ����� ���� ����� �ִ� ���� 0�� ��ǥ������ �迭�� �ʿ��ϴ�.
// ���� 0�� ��ǥ������ K���� �ִٰ� �Ҷ� ������� ù��° ~ K��° ��ǥ���� ��� �� 3���� �������ϱ� �����̴�.
// ���� 3���� ��ǥ���� ������ٸ� 2�� �Լ��� ȣ���Ͽ� �������� answer�� ���� �������ش�.


vector<vector<int>> board, temp;
vector<pair<int, int>> zero, two;
int trans[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M, answer = 0;


// DFS�� 1�� �Լ�.
void DFS(int y, int x)
{
    temp[y][x] = 2;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + trans[i][0];
        int dx = x + trans[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || temp[dy][dx] != 0)
            continue;

        DFS(dy, dx);
    }
}

// 2�� �Լ�. DFS�� ��ȸ�Ͽ� ���� ���������� ũ�⸦ ��ȯ�Ѵ�.
int CalSafe()
{
    int safe = 0;
    temp = board;
    for (int i = 0; i < two.size(); ++i)
        DFS(two[i].first, two[i].second);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (temp[i][j] == 0)
                ++safe;

    return safe;
}

// ��Ʈ��ŷ�� 3�� �Լ�. ���� 0�� ��ǥ������ ��ȸ�ϸ� �ϳ��� ���� ����, �� 3���� ����ٸ� �׶� ���������� ũ�⸦ �����س�����.
void BackTrack(int idx, int num)
{
    if (num == 3)
    {
        answer = max(answer, CalSafe());
        return;
    }

    for (int i = idx + 1; i < zero.size(); ++i)
    {
        board[zero[i].first][zero[i].second] = 1;
        BackTrack(i, num + 1);
        board[zero[i].first][zero[i].second] = 0;
    }
}

void MakeAnswer()
{
    BackTrack(-1, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>());
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> cur;
            board[i].push_back(cur);
            if (cur == 0)
                zero.push_back(make_pair(i, j));
            else if (cur == 2)
                two.push_back(make_pair(i, j));
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}