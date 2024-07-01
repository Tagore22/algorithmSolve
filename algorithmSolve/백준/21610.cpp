#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ������ ��������. �ƴ� ���� ���� ���ΰ�. ��� ��¼�� �ϴ� ������ �� �Ｚ SW ��������.
// �׸��� ����� ���� ������ �������� �쵢�� �񷽸��� ������ٴ� ���̾���.
// ������ ������ ����� �ʾ����� �������� �ܰ谡 ����������, �������� ������ �����ߴ�.
// �ٸ� �Ｚ SW������ ���������� �ѹ��� ������ �ϱ�� ������ �ּ����� ������ ��ü�Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[50][50], rot[9][2] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int bug[4][2] = { {-1, -1}, {-1, 1}, {1, 1}, {1, -1} }; // �»������ �ð����.
vector<pair<int, int>> cloud;
pair<int, int> mov[100];
bool check[50][50];
int N, M;

// 1. ������ �����϶� �迭���� ����� �ݴ�� �̵��ȴ�.
// 2. ������ Ư�� ����(�¿���� + �밢��)���� Ư������ŭ �̵��Ѵ�.
// 3. ������ �̵��� �� ĭ�� ���� 1��ŭ �����Ѵ�.
// 4. ������ ������� �� ĭ�� ��������װ� ����ȴ�. �밢������ �Ÿ��� 1��ŭ�� �ٱ�����
// ���� �ִ� �ٱ����� ����ŭ �ٽ� ���� �����Ѵ�. �̶� ������ �̵����� �ٸ��� �迭���� �����
// ĭ���� �����Ѵ�.
// 5. �ٱ��Ͽ� ����� ���� ���� 2�̻��� ��� ������ �� ���� ������ �߻��ϸ� ���� ���� 2�� �پ���.
// �ٸ� ���� ������ ��ġ�ߴ� ���� �����Ѵ�.

// ��������״� �ݵ�� ��� ������ �̵��� �� ĭ�� ���� 1�� �����Ŀ� �ؾ��Ѵ�. �׷��� �ʰ�
// ������ �Ѻκ��� �̵��� ��������׸� �����ϸ� ����� �� ���� ������ �������̴�.

// �� �������� ��ġ�� �̵��ϴ� �Լ�.
void MoveCloud(int idx)
{
    // ���� ������ ��ġ�� ������� �ؾ��ϴµ� vector�� �����Ƿ� �����ϱ� �����ϴ�.
    // ���� ��ü�Ǵ� vector�� �ϳ� �� ���� ������ cloud�� �����.
    vector<pair<int, int>> next;
    for (auto a : cloud)
    {
        // �� �κп� �ϳ� �߿��� �κ��� ��� �ִ�.
        // 1. ������ ��ǥ �ű��� �׳� y + rot[i][0]������ �Ͽ���. ������ �̹�����
        // �̵��ϴ� ĭ�� ũ�Ⱑ �ܼ��� 1�� �ƴϱ� ������ �� ũ�⸸ŭ �����־�� �Ѵ�.
        // 2. ���� ���Ҷ� N��ŭ ������� �Ѵ�. N�� �Ѿ�� �̵��� N���� ���� ��������ŭ�� �̵��� ��ġ�ϱ⿡
        // �ð��� �� �����Ҽ� �ִ�.
        int ny = a.first + rot[mov[idx].first][0] * (mov[idx].second % N);
        // �̵����� 0���� �۴ٸ� N - 1�� ����Ǿ� �ִ�.
        if (ny < 0)
            ny = N + ny;
        // �̵����� N���� ũ�ų� ���ٸ� 0�� ����Ǿ� �ִ�.
        else if (ny >= N)
            ny = ny - N;
        int nx = a.second + rot[mov[idx].first][1] * (mov[idx].second % N);
        if (nx < 0)
            nx = N + nx;
        else if (nx >= N)
            nx = nx - N;
        // ���ο� �������� �����ϰ� �̰������� ���� ������ ���� ���� ���� ������ ��ġ���°��� ���� üũ�Ѵ�.
        next.push_back(make_pair(ny, nx));
        check[ny][nx] = true;
    }
    cloud = next;
}

// ��������׸� �����ϴ� �Լ�.
int WaterBug(int y, int x)
{
    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        // �̰����� int ny = bug[i][0]; �̷��� �־���.
        // �����ؼ� �Ǽ��һ��ߴ�.
        // �� �밢���� ��ġ�� ���غ���.
        int ny = y + bug[i][0];
        int nx = x + bug[i][1];

        // ������ �̵����� �޸� �̰������� �迭���� ����� �����Ѵ�. ���� ������ ĭ�� ���� ���� 0�̶��
        // ���������� �����Ѵ�.
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 0)
            continue;
        ++ans;
    }
    return ans;
}

void MakeAnswer()
{
    // �ʱ� ������ ��ġ����.
    cloud.push_back(make_pair(N - 1, 0));
    cloud.push_back(make_pair(N - 1, 1));
    cloud.push_back(make_pair(N - 2, 0));
    cloud.push_back(make_pair(N - 2, 1));
    for (int iter = 0; iter < M; ++iter)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                check[i][j] = false;
        MoveCloud(iter);
        for (auto a : cloud)
            ++board[a.first][a.second];
        for (auto a : cloud)
            board[a.first][a.second] += WaterBug(a.first, a.second);
        cloud.clear();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] >= 2 && !check[i][j])
                {
                    cloud.push_back(make_pair(i, j));
                    board[i][j] -= 2;
                }
    }
    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer += board[i][j];
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    for (int i = 0; i < M; ++i)
        cin >> mov[i].first >> mov[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}