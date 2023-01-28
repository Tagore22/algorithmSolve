#include <iostream>
#include <algorithm>

using namespace std;

//Ǯ��
//���� �����ؾ��ϴ� ������ ������ �䱸�ϴ� ��������. ���� �����߷� 1~K���� ���� ����� ������, ���� ������ L�� K���� �۰ų� ���ٸ�
//1~K+L���� ����� �ִ�. ������ L�� K���� ũ�ٸ� K+1���� L-1������ ���� ��� �ȴ�. ������ �̿��ؾ��ϴ� �����̴�.

int chu[1000];
int N;

void MakeAnswer()
{
    int answer = 1; //���� �����ؾ��ϴ� ��.
    sort(chu, chu + N); //�����Ͽ� ���������� �����ؾ� ����� ����� ����Ҽ� �ִ�. 

    for (int i = 0; i < N; ++i)
    {
        if (answer < chu[i]) //�������� ������ �߰� ���� �������ϴ� �� answer���� ũ�ٸ� answer�� ����� ����.
            break;
        answer += chu[i]; //������ ���� ����.
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> chu[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}