#include <iostream>

using namespace std;

//�Ʒ� �ּ�ó�� N-M�� ���������� int���� �ִ밪�� �Ѿ���� �ֱ⿡ ĳ������ �ϴ��� �ƴϸ� N�� M�� �ƿ� long long���� �����ϸ� �ȴ�.

long long N, M;

void MakeAnswer()
{
    long long answer = abs(N - M); //abs�ȿ��� N-M�� int�� �ִ밪�� �Ѿ�� ����.
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}