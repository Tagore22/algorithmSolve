#include <iostream>
#include <vector>

using namespace std;

// Ǯ��
// ������ �������� �����ϸ鼭 ���� Ǯ��ô� �����̴�. K��° ������ ���ϴ� �����ε�, �켱 ���� �ڸ������� ���Ҽ� �ִ� ������ �˾ƾ��Ѵ�.
// �װ��� MakePermu()�ε�, ������ ���� ���� �ߺ����� ���� �ʱ⿡ ���丮�� ������ �����ϴ�.

// �� �������� �ҹ����� �ִµ� �װ��� ���� ó��������Ѵ�.

// �켱 1������ ���ڸ�, �־����� K��° ������ ����ϴ� ���̴�.
// ���������� ���ĵǾ� �ֱ⿡ ���� �������� 1���� �����Ͽ� ���� i��°���� ����� �ִ� �� make_cur�� K�� ���Ѵ�. K�� �� �۰ų� ���ٸ�
// ���� ���� ����� �ֱ⿡ ������ �迭 answer�� i�� �ְ�, �ٽ� i�� ����Ҽ� ���⿡ check[i] = false�� ���ش�.
// �̷��� N���� �ݺ��Ͽ� ������ answer�� ����� ����ϸ� �ȴ�.

// 2���� �� �ݴ�� ������ �־������� ���° �������� K���� ����ؾ��ϴµ� ����� ������ Ǯ�� �ִ�. ��°� skip�� 0���� �����Ѵ�.
// �ٽ� �ڸ����� �ݺ��ϸ� 1������ �����Ͽ� ����� i�� ���� �ڸ��� board[iter]�� ���Ѵ�. �׷��� �񱳽� �� ���� ���ٸ� ���� �ڸ����� �Ѿ��
// ���� �ʴٸ� make_cur���� skip�� Ŀ�� �������� �Ѿ���̱⿡ ��°� skip�� make_cur���� �����ش�. �ٸ� �� ����Ͽ��� ������ �ߺ��Ǵ� ����
// ���⿡ �̹� ���� ���� check �迭�� �̿��Ͽ� �������־���Ѵ�. �̷��� ������ �ڸ����� ��ȸ�� ������ ������ skip�� 1�� ���� ����Ѵ�.

vector<int> board;
vector<long long> permu;
vector<bool> check;
int N, T;
long long num;

void MakePermu()
{
    permu.push_back(1);
    for (int i = 1; i <= N; ++i)
        permu.push_back(permu[i - 1] * i);
}

void CalOne()
{
    long long skip = num;
    for (int iter = 1; iter <= N; ++iter)
    {
        long long make_cur = permu[N - iter];
        for (int i = 1; i <= N; ++i)
        {
            if (!check[i])
                continue;
            if (skip <= make_cur)
            {
                board.push_back(i);
                check[i] = false;
                break;
            }
            else
            {
                skip -= make_cur;
            }
        }
    }

    for (auto& n : board)
        cout << n << ' ';
    cout << '\n';
}

void CalTwo()
{
    long long skip = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        long long make_cur = permu[N - iter - 1];
        for (int i = 1; i <= N; ++i)
        {
            if (!check[i])
                continue;
            if (board[iter] == i)
            {
                check[i] = false;
                break;
            }
            skip += make_cur;
        }
    }
    cout << skip + 1 << '\n';
}

void MakeAnswer()
{
    MakePermu();
    if (T == 1)
        CalOne();
    else
        CalTwo();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    check.resize(N + 1, true);
    if (T == 1)
        cin >> num;
    else
        for (int i = 0; i < N; ++i)
        {
            int a;
            cin >> a;
            board.push_back(a);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}