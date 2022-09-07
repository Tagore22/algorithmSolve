#include <iostream>
#include <vector>

using namespace std;

vector<int> cashe;
int P, M;

//i-2 + i-1 % M���� �Ǻ���ġ ������ ������ 0�� 1�� �߰ߵɶ� i�� ���ϰ��� �ϴ� �ֱ��̴�.
//�������� ����ϱ⿡ 0�� 1�� �߰ߵǴ� ������ �ֱⰡ ������ �����Ҽ� �ִ�.

void CalculFibo()
{
    cashe.clear();
    cashe.push_back(0);
    cashe.push_back(1);
    int idx = 3;
    while (true)
    {
        cashe.push_back((cashe[idx - 3] + cashe[idx - 2]) % M);
        if (cashe[idx - 2] == 0 && cashe[idx - 1] == 1)
            break;
        ++idx;
    }
    cout << idx - 2 << '\n';
}

void MakeAnswer()
{
    int idx;
    for (int i = 0; i < P; ++i)
    {
        cin >> idx >> M;
        cout << idx << " ";
        CalculFibo();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> P;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}