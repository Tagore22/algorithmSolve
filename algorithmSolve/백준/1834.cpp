#include <iostream>

using namespace std;

//Ǯ��
//�������� �־��� �״�� 1���� N-1���� N * i + i�� ���ؼ� �� �������� ����ϸ� �ȴ�.
//�ٸ�, ������ int�� ��½ �Ѿ���� long long�� ����Ͽ��� �Ѵ�.

int N;

void MakeAnswer()
{
    long long answer = 0;

    for (long long i = 1; i < N; ++i)
        answer += N * i + i;

    cout << answer << '\n';
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