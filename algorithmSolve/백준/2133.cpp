#include <iostream>

using namespace std;

// Ǯ��
// ��Ģ�� �˾Ƴ��� �ϴ� �����̴�. �ٽ� ����.

int answer[31];
int N;

void MakeAnswer()
{
    answer[0] = 1;
    answer[2] = 3;

    for (int i = 4; i <= N; i++) {
        for (int j = 2; j <= i; j += 2)
        {
            int multi = 2;
            if (j == 2) multi = 3;
            answer[i] += answer[i - j] * multi;
        }
    }
    cout << answer[N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}