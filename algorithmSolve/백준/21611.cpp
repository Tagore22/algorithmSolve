#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �������̴�. �Ｚ ������. ����� ������ ������ ���� �������� �����ִ�. �� ���������� �Ｚ������
// Ǯ���� �߻󺸴� ������ �ɷ��� �� ���ϴµ��ϴ�. ������ �� ������ �������� �˰����� ���ø��⺸��
// �־����� �����ϱ� �ޱ��ϴ�. �������� ���� ��ŭ ���� ���� ��������.

// �ڼ��� ������ �ּ����� �����.

int board[50][50], answer[4] = { 0, };
int rot[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dir[2][2] = { {-1, 1}, {1, -1} };
pair<int, int> magic[101]; // ����, �Ÿ�.
int N, M, from;
vector<int> cou;

// ���ڵ带 �� ������ �迭�� �����ϴ� �Լ�.
void Blizzard(int idx)
{
    int y = from, x = from;
    // ���ڵ��� ���̸�ŭ ���� ��ǥ�� �̵��ذ��� ���� 0���� �����.
    for (int i = 0; i < magic[idx].second; ++i)
    {
        int ny = y + rot[magic[idx].first][0];
        int nx = x + rot[magic[idx].first][1];
        board[ny][nx] = 0;
        y = ny;
        x = nx;
    }
}

// �������� �̵���Ű�� �Լ�.
bool Move()
{
    // isEnd�� ���Ŀ� Move()�� �ѹ� �� ȣ���ϴ����� ���θ� ���ϴ� �Լ���.
    // �ѹ��� ��ȸ���� �̵��� �������� ���������� Move()�� ��� ȣ��ȴ�.
    bool isEnd = true, isX = true;
    int y = from, x = from, num = 1;

    // �ݺ��� Ƚ���� �����ϱⰡ �������. 
    // ������ while���� ��ȸ�ϴٰ� ���� ���ǿ� ���� Ż���Ѵ�.
    while (true)
    {
        if (isX)
        {
            // �¿���ϸ� ���������ϴµ� ���� ���̵� �������� �ʾ� �̷��� �����ߴ�.
            // ���Ͽ������ �����̱� ������ ��, ��� ��, �ϸ� ���� ��� �迭�� �̿���
            // �̵����� �����ߴ�.
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                // �̵��Ϸ��� ��ǥ���� �迭�� ����ٸ� �����Ѵ�.
                if (nx <= 0 || nx > N)
                    // ���� 2�� �ݺ����ȿ� �����ϱ� ������ ���ѹ��� break�δ� Ż���Ҽ� ������.
                    // ���� bool ������ �����ϰ� ���Ŀ� �ѹ� �� Ż���Ѵ�.
                    return isEnd;
                // �� ó�� ����� ��ġ�� 0�̴�. �̰��� ���ǹ����� �ɷ������ϱ� ������
                // ��ǥ�� �������̶�� �����ϰ� ���簪�� 0�̸� �������� 0�� �ƴҶ�����
                // ���� ��ȯ�Ѵ�. �ֳ��ϸ� ���絵 0�̰� ������ 0�̸� ��ȯ�غ����̸�
                // ���絵 0�� �ƴϰ� ������ 0�� �ƴϸ� ��ȯ��ü�� �Ұ����ϱ� �����̴�.
                if ((y != from || x != from) && board[y][x] == 0 && board[y][nx] != 0)
                {
                    swap(board[y][x], board[y][nx]);
                    // �̹��� ��ȯ�� ���������Ƿ� ���Ŀ� Move()�� �ѹ� �� ȣ���Ѵ�.
                    isEnd = false;
                }
                x = nx;
            }
            isX = false;
        }
        // y�� �̵��Ҷ�. �ݺ�.
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N)
                    return isEnd;
                if (board[y][x] == 0 && board[ny][x] != 0)
                {
                    swap(board[y][x], board[ny][x]);
                    isEnd = false;
                }
                y = ny;
            }
            ++num;
            isX = true;
        }
    }
}

// ������ 4�� �̻� �������� �����Ͽ� �����Ҷ��� �Լ�.
bool Explode()
{
    bool isX = true, isEnd = true, isCross = false;
    int y = from, x = from, num = 1, prev = -1;
    vector<pair<int, int>> overlap;

    while (true)
    {
        if (isX)
        {
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                if (nx <= 0 || nx > N)
                {
                    isCross = true;
                    break;
                }
                x = nx;
                // ������ ���� ��ȣ�� ������ ���� ��ȣ�� �ٸ���
                // vector�� �־���� ���ҵ��� �����Ѵ�.
                // ���� 4�� �̻��̶�� ������ �����Ͽ� 0���� �����
                // �׷��� �ʴٸ� �׳� ����������.
                if (board[y][x] != prev)
                {
                    int osize = overlap.size();
                    if (osize >= 4)
                    {
                        isEnd = false;
                        for (auto& p : overlap)
                        {
                            ++answer[board[p.first][p.second]];
                            board[p.first][p.second] = 0;
                        }
                    }
                    prev = board[y][x];
                    overlap.clear();
                }
                // ���� ��ȣ�� ���� ��ȣ�� �������� ������� ���� ������ ������ vector�� ����.
                // �� 0�� ������ �������� �ʱ⿡ ���귮�� ���̱� ���� �����Ѵ�.
                if (board[y][x] != 0)
                    overlap.push_back(make_pair(y, x));
            }
            if (isCross)
                break;
            isX = false;
        }
        // y�� �����϶�. �ݺ�.
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N)
                {
                    isCross = true;
                    break;
                }
                y = ny;
                if (board[y][x] != prev)
                {
                    int osize = overlap.size();
                    if (osize >= 4)
                    {
                        isEnd = false;
                        for (auto& p : overlap)
                        {
                            ++answer[board[p.first][p.second]];
                            board[p.first][p.second] = 0;
                        }
                    }
                    prev = board[y][x];
                    overlap.clear();
                }
                if (board[y][x] != 0)
                    overlap.push_back(make_pair(y, x));
            }
            if (isCross)
                break;
            ++num;
            isX = true;
        }
    }
    // ��ȸ ���Ŀ� vector�� ���Ұ� ������������ �ִ�. ����Ͽ��� ��ȸ Ƚ���� ��Ȯ�ϰ�
    // ����ϱⰡ ��ȣ�ϱ⿡ �ϴ� �� �ִ´�. 
    int osize = overlap.size();
    if (osize >= 4)
    {
        isEnd = false;
        for (auto& p : overlap)
        {
            ++answer[board[p.first][p.second]];
            board[p.first][p.second] = 0;
        }
    }
    return isEnd;
}

// ���ġ�� ������ ��ȣ�� ������ ����ϴ� �Լ�.
void Count()
{
    bool isX = true, isCross = false;
    int y = from, x = from, num = 1, prev = -1, sum = 1;
    vector<pair<int, int>> overlap;

    while (true)
    {
        if (isX)
        {
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                // ����� Move() �Լ��� ���� ��ĭ�� ���� ä���� �����̴�.
                // �̶� board[y][x]�� 0�̶�� ���� ��� ������ ��ȸ�ϰ� �� �����̴�.
                // �̰��� �迭���� �������ó�� ���ܽ����־�� �Ѵ�.
                // �׷��� ������ 0�� ������ �Բ� vector�� ���ԵǾ� ���� ���ġ�� �ǿ����� ����
                // ����� �� ���� ������� ���ϱ� �����̴�.
                if (nx <= 0 || nx > N || board[y][nx] == 0)
                {
                    isCross = true;
                    break;
                }
                x = nx;
                // ���� �������� ���� �������� �ٸ��ٸ�
                // ������ ���� ��ȣ�� ������ vector�� �����ϰ�
                // ���� ���� ��ȣ�� 1�� �����Ѵ�.
                if (board[y][x] != prev)
                {
                    cou.push_back(sum);
                    cou.push_back(prev);
                    prev = board[y][x];
                    sum = 1;
                }
                else
                {
                    ++sum;
                }
            }
            if (isCross)
                break;
            isX = false;
        }
        // y�� �����϶�. �ݺ�.
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N || board[ny][x] == 0)
                {
                    isCross = true;
                    break;
                }
                y = ny;
                if (board[y][x] != prev)
                {
                    cou.push_back(sum);
                    cou.push_back(prev);
                    prev = board[y][x];
                    sum = 1;
                }
                else
                {
                    ++sum;
                }
            }
            if (isCross)
                break;
            ++num;
            isX = true;
        }
    }
    // Explode()�� ���������� vector�� ���Ұ��� ���������� �ֱ⿡ �߰����ش�.
    cou.push_back(sum);
    cou.push_back(prev);
}

// �迭�� ���������� ���ġ�ϴ� �Լ�.
void Resort()
{
    bool isX = true;
    int y = from, x = from, num = 1, idx = 2;
    vector<pair<int, int>> overlap;

    // vector ���� cou�� ��� �迭��ǥ��ŭ ��ȸ�ϸ� �� ���Ұ����� ��ü�Ѵ�.
    while (true)
    {
        if (isX)
        {
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                if (nx <= 0 || nx > N)
                    return;
                x = nx;
                board[y][x] = cou[idx];
                ++idx;
                if (idx >= cou.size())
                    return;
            }
            isX = false;
        }
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N)
                    return;
                y = ny;
                board[y][x] = cou[idx];
                ++idx;
                if (idx >= cou.size())
                    return;
            }
            ++num;
            isX = true;
        }
    }
}

void MakeAnswer()
{
    from = (N + 1) / 2;
    for (int iter = 0; iter < M; ++iter)
    {
        cou.clear();
        Blizzard(iter);
        // ����Ѵ�� Move()���� ���̻� �������� ����������
        // �ݺ��Ͽ� ȣ���Ѵ�.
        while (!Move())
        {
        }
        // ���������� ������ ���̻� �������� ����������
        // ���߰� �̵��� �ݺ��ϳ�.
        while (!Explode())
        {
            while (!Move())
            {
            }
        }
        Count();
        Resort();
    }
    cout << (1 * answer[1] + 2 * answer[2] + 3 * answer[3]) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
    for (int i = 0; i < M; ++i)
        cin >> magic[i].first >> magic[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}