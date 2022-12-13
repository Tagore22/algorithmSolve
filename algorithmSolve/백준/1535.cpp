#include <iostream>

using namespace std;

//Ǯ��
//�������� �賶������ �־��� ���� N�� �ִ� 20�̱⿡ �ִ� ���귮�� 2�� 20�������� 100���� ���� �ѱ⿡ �ƹ��� ������ ����.
//�� ���Һ��� 2���� ����� ���� �ִµ� ù��°�δ� ���� ü���� �λ�� �پ��� ü�º��� Ŭ��� �λ縦 �ϴ� ���̰�
//�ι�°�δ� �λ縦 ���� �ʴ� ���̴�. �� ��� ����� ���� ���� ������ ���ұ��� ��� ��ȸ�� ���� �ִ밪�� ����ϸ� �ȴ�.

int L[20], J[20];
int N, answer = 0;

void Max_Happy(int idx, int health, int happy)
{
    if (idx == N)
    {
        answer = max(answer, happy);
        return;
    }

    if (L[idx] < health)
        Max_Happy(idx + 1, health - L[idx], happy + J[idx]);

    Max_Happy(idx + 1, health, happy);
}

void MakeAnswer()
{
    Max_Happy(0, 100, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> L[i];
    for (int i = 0; i < N; ++i)
        cin >> J[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}