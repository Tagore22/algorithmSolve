#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Ǯ��
// �־������ �����϶�� ���� �ùķ��̼ǽ� �����̴�. ���õ� ���� �������� �ٽ� �ѹ� ���캸�� ��� �����ϸ� ���� ����

// 1. ���� �Ӹ��� �־��� �������� ��ĭ �� ���δ�.(���ư���).
// 2. ���� ���ư����� ������ ����� ������� ������ ������� �ʴ´�. ��, ���� 1ĭ �þ��.
// 3. ����� �ƴ϶�� ������ ��ĭ ����� �´�.
// 4. ���ư� ���� ���� �Ϻΰų� ���̶�� �� ��� ������ ����ȴ�.

// ó������ ���� �̵��� ��� �����ؾ������� �ָ��ߴ�. board[][]�� 2�� 3�� �ξ� ���� ���� ��ġ�� ǥ���ұ ����������,
// ������ ��ġ �����̳�, ���� ��ȯ�� ���� ��ġ���� ��ȯ���� �ָ��ߴ�. �׷��� �����س� ���� �׳� �����̳� �ȿ� �� ����ְ�
// �Ӹ��� ������ ��ġ�� �����ϴ� ���̾���. deque�� �����Ͽ� ���ư� �Ӹ��� ��ġ�� ���� �߰��ϰ�, ���ư� ���� ������
// ����� ���ְ� ����� �ƴ϶�� �� ������ �����κи� �����ϸ� �ȴ�. �߰��� ������ �յڿ����� �Ͼ�⿡ deque�� �����ϱ⿡
// �ȼ������̾���. 

int board[101][101];
int rot[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // �� �� �� ��, 0 ~ 3
deque<pair<int, char>> moving;
deque<pair<int, int>> snake; // ������ �Ӹ���.
int N, K, L;

void MakeAnswer()
{

    // ���� �ð��� ������ �ʱ�ȭ��. ������ �����ʹ������� �̹� ������ �־����ִ�.
    int answer = 0, dir = 1;

    // ���ư� ��ġ���� ��Ÿ���� ����.
    pair<int, int> next;
    while (true)
    {
        // ���� �ð����� ������ ��ȯ�ؾ��ϴ��� Ȯ����, �׷��ϴٸ� ������ ��ȯ�Ѵ�.
        if (!moving.empty() && answer == moving.front().first)
        {
            if (moving.front().second == 'D')
                dir = dir + 1 <= 3 ? dir + 1 : 0;
            else
                dir = dir - 1 >= 0 ? dir - 1 : 3;
            moving.pop_front();
        }

        ++answer;

        next = make_pair(snake.front().first + rot[dir][0], snake.front().second + rot[dir][1]);


        // ���ư� ���� ���̰ų�, ���� �Ϻζ�� ��� �����Ѵ�.
        if (next.first <= 0 || next.first > N || next.second <= 0 || next.second > N ||
            find(snake.begin(), snake.end(), next) != snake.end())
            break;

        snake.push_front(next);

        // ���ư� ���� ������ ����� ���ְ�, ����� �ƴ϶�� ������ ���ش�.
        if (board[next.first][next.second] == 1)
            board[next.first][next.second] = 0;
        else
            snake.pop_back();
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    int y, x;
    for (int i = 0; i < K; ++i)
    {
        cin >> y >> x;
        board[y][x] = 1;
    }
    cin >> L;
    int time;
    char dir;
    for (int i = 0; i < L; ++i)
    {
        cin >> time >> dir;
        moving.push_back(make_pair(time, dir));
    }
    snake.push_back(make_pair(1, 1));
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}