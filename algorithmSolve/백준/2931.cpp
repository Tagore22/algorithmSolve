#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// Ǯ�̰� ���� ��������� �����. �׸��� �ſ� �������� �ʿ�� �Ѵٴ� ���̴�. �׷��� �ϳ� ���� �ɷȴ�.
// �밡�ٿ� ����� ������. ��ɵ� ���� ���� �������� �־����� ���� �״�� �����ؾ� �Ѵ�. �����ϰ� �������ڸ� ������ ����.

// 1. M���� �����ϹǷ� M�� ��ġ�� ã�´�. 
// 2. M���� ����� �������� ��ġ from�� ã�´�. ������ M���� Z�� �̾����� ������ M���� ���۵Ǵ� �������� ������ 1���̴�.
// 3. from���� ���� ���� ��, board[i][j]�� '.'�� ��ġ to�� ��ġ�� ã�´�. �̶� �־��� �������� ����� �������� �Ѵ�.
// 4. to���� 4������ ��ȸ�ϸ� to�� ����� ���������� ���� ã�´�. �ѱ������ �� ��ġ�� ���� ����� ã�ƾ��ϰ�,
// �����������(������ 3����) ������ +�̴�.

// �� ���� �ſ� �����ϰ� �����Ѱ��̴�. �ڼ��� ������ �ּ����� �����.

char board[25][25];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
pair<int, int> M, Z, from, to;
bool check[25][25] = { false, };
int R, C;

// 1. ������(Z���� ����ϴ�)�� ã�´�.
// 2. BFS�� �� ����. �̶� Z�� �����ϸ� continue�� ���ؼ� �����ϸ�
// ��������� ���� ���� ���� ã���� BFS�� �������´�.
// 3. 8������ ���ư��� ����ɼ� �ִ°��� ã�´�.


// from���� �����Ͽ� to�� ã�� �Լ�.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    check[from.first][from.second] = true;
    check[M.first][M.second] = true;
    check[Z.first][Z.second] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // from�� �������� ���� �̵��ؾ��� ������ �ٲ��. �̰��� �迭ȭ�ϱ⵵ ����Ƿ� ����Ͽ��� �밡�ٿ� �����
        // ���۾����� �ؾ߸� �ߴ�.
        if (board[y][x] == '|')
        {
            pair<int, int> cur[2] = { {y - 1, x}, {y + 1, x} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                // �迭���� ����ų� �̹� �湮�� ���̶�� �����Ѵ�.
                if (ny < 0 || ny >= R || check[ny][nx])
                    continue;
                // ���� ���� ���̶�� �̰��� �� �� ��ġ�̹Ƿ� �������� ���簪�� ������ Ż���Ѵ�.
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                // �׷��� �ʴٸ� ť�� �����ϰ� �ٽ� ��ȸ�Ѵ�.
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        // �ٸ� ���鵵 ���� �ٸ��� ����. �ٸ� ������ ��� �ٸ���.
        else if (board[y][x] == '-')
        {
            pair<int, int> cur[2] = { {y, x - 1}, {y, x + 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '+')
        {
            pair<int, int> cur[4] = { {y, x - 1}, {y, x + 1}, {y - 1, x}, {y + 1, x} };
            for (int i = 0; i < 4; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '1')
        {
            pair<int, int> cur[2] = { {y, x + 1}, {y + 1, x} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '2')
        {
            pair<int, int> cur[2] = { {y - 1, x}, {y, x + 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '3')
        {
            pair<int, int> cur[2] = { {y - 1, x}, {y, x - 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '4')
        {
            pair<int, int> cur[2] = { {y + 1, x}, {y, x - 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
    }
}

void MakeAnswer()
{
    int y = M.first;
    int x = M.second;
    // M�� ����� �������� ��ġ from�� ã�´�. 4������ ��ȸ�Ѵ�. ������ �ѱ����� ����Ǿ� �ִ�.
    // Z���� ������ ����Ǿ� �ִٰ� ������ ���õǾ��ֱ� �����̴�.
    if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
        board[y][x - 1] == '1' || board[y][x - 1] == '2'))
        from = make_pair(y, x - 1);
    else if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
        board[y - 1][x] == '1' || board[y - 1][x] == '4'))
        from = make_pair(y - 1, x);
    else if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
        board[y][x + 1] == '3' || board[y][x + 1] == '4'))
        from = make_pair(y, x + 1);
    else if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
        board[y + 1][x] == '2' || board[y + 1][x] == '3'))
        from = make_pair(y + 1, x);

    // from���� �� �� ��ġ to�� ã�� ��ȸ�� �����Ѵ�.
    BFS();

    // to���� 4������ ��ȸ�ϸ� to�� ��ġ�� ����� �������� ���� ã�´�. ������ 1 �ƴϸ� 3�̴�.
    pair<char, int> answer = make_pair(0, 0);
    // �������� �ö�.
    if (from.first == to.first && from.second + 1 == to.second)
    {
        int y = to.first;
        int x = to.second;
        // ����
        if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
            board[y - 1][x] == '1' || board[y - 1][x] == '4'))
            answer = make_pair('3', answer.second + 1);
        // �Ʒ���
        if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
            board[y + 1][x] == '2' || board[y + 1][x] == '3'))
            answer = make_pair('4', answer.second + 1);
        // ������
        if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
            board[y][x + 1] == '3' || board[y][x + 1] == '4'))
            answer = make_pair('-', answer.second + 1);
    }
    // �������� �ö�.
    else if (from.first == to.first && from.second - 1 == to.second)
    {
        int y = to.first;
        int x = to.second;
        // ����
        if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
            board[y - 1][x] == '1' || board[y - 1][x] == '4'))
            answer = make_pair('2', answer.second + 1);
        // �Ʒ���
        if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
            board[y + 1][x] == '2' || board[y + 1][x] == '3'))
            answer = make_pair('1', answer.second + 1);
        // ����
        if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
            board[y][x - 1] == '1' || board[y][x - 1] == '2'))
            answer = make_pair('-', answer.second + 1);
    }
    // ���ʿ��� �ö�
    else if (from.first + 1 == to.first && from.second == to.second)
    {
        int y = to.first;
        int x = to.second;
        // ����
        if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
            board[y][x - 1] == '1' || board[y][x - 1] == '2'))
            answer = make_pair('3', answer.second + 1);
        // �Ʒ���
        if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
            board[y + 1][x] == '2' || board[y + 1][x] == '3'))
            answer = make_pair('|', answer.second + 1);
        // ������
        if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
            board[y][x + 1] == '3' || board[y][x + 1] == '4'))
            answer = make_pair('2', answer.second + 1);
    }
    // �Ʒ����� �ö�
    else if (from.first - 1 == to.first && from.second == to.second)
    {
        int y = to.first;
        int x = to.second;
        // ����
        if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
            board[y][x - 1] == '1' || board[y][x - 1] == '2'))
            answer = make_pair('4', answer.second + 1);
        // ����
        if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
            board[y - 1][x] == '1' || board[y - 1][x] == '4'))
            answer = make_pair('|', answer.second + 1);
        // ������
        if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
            board[y][x + 1] == '3' || board[y][x + 1] == '4'))
            answer = make_pair('1', answer.second + 1);
    }
    answer.first = answer.second == 3 ? '+' : answer.first;
    cout << to.first + 1 << ' ' << to.second + 1 << ' ' << answer.first << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'M')
                M = make_pair(i, j);
            else if (board[i][j] == 'Z')
                Z = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}