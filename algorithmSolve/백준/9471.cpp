#include <iostream>
#include <vector>

using namespace std;

vector<int> cashe;
int P, M;

//i-2 + i-1 % M으로 피보나치 수열을 만들어가며 0과 1이 발견될때 i가 구하고자 하는 주기이다.
//나눗셈을 사용하기에 0과 1이 발견되는 순간이 주기가 맞음을 증명할수 있다.

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