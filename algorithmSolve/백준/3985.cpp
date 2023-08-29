#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ���������� ����� ������ ���� ������ �������� ���� ������.
// ���������� ���ϴ� �κ��� ������ �����鿡�� ������ �ٶ� ó���� ���� ���� �ް� �ɰ����� ����Ǵ� ������ ��ȣ��
// ������ ���� ���� �ް� �� ������ ��ȣ�� ����ϴ� ������. ���� Ǯ���� ūƲ�� ������ ����.

// 1. ����ũ�� ���� ���θ� �ľ��ϴ� bool �迭 cake�� �غ��Ͽ� ���� false�� �ʱ�ȭ�Ѵ�.
// 2. �������� ��� ��ȣ from ~ to�� �Է¹޴´�. ���⼭ ���� ���� �ް� �ɰ����� ����Ǵ� ���� ���Ҽ� �ִ�.
// to - from + 1�� ����Ǵ� ����ũ �������� �����ϸ� ù��° �� f_answer�� ���Ѵ�.
// 3. from ~ to�� ��ȸ�ϸ� �ش� ��ȣ�� ����ũ�� �����ϴ����� �ľ��Ѵ�. true��� �̹� ���� ���� ���̰�
// false��� �޾ư��� �ִ�. �׷��� ��ȸ�ϸ� ���� ���� ����ũ�� ���� �ι�° �� s_answer�� ���Ѵ�.
// 4. �־��� ��ȸ�� �ҽ� 1000 * 1000 = 100���̹Ƿ� �ð����� ����� Ǯ�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

bool cake[1001];
int L, N;

void MakeAnswer()
{
    memset(cake, false, sizeof(cake));
    int from, to, ans;
    // ������ ��, ��û���� ��ȣ.
    pair<int, int> f_answer = make_pair(0, -1);
    pair<int, int> s_answer = f_answer;
    for (int i = 1; i <= N; ++i)
    {
        cin >> from >> to;
        int cur = to - from + 1;
        // ���� ���� �ް� �ɰ����� ����Ǵ� ù��° ���� ���Ѵ�.
        f_answer = f_answer.first < cur ? make_pair(cur, i) : f_answer;
        ans = 0;
        // from ~ to���� ��ȸ�ϸ� ������ �޴� ����ũ�� ���� ������ ���� ���� ���� �ް� �Ǵ� �ι�° ���� ���Ѵ�.
        for (int j = from; j <= to; ++j)
        {
            if (!cake[j])
            {
                cake[j] = true;
                ++ans;
            }
        }
        s_answer = s_answer.first < ans ? make_pair(ans, i) : s_answer;
    }
    cout << f_answer.second << '\n' << s_answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}