#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 주어지는 배열의 크기를 비교하는 문제다. 다만 그냥 배열을 사용하면 주소값을 비교하기 때문에
// 불가능하고 벡터를 이용해야 한다. 이것만 알면 나머지 구현은 전혀 어렵지 않다.

// 자세한 설명은 주석으로 남긴다.

vector<int> a, b;
int N, num;

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        // 이전의 내용들을 비워야한다.
        a.clear();
        b.clear();

        cin >> num;
        int cur;
        // a를 만든다.
        for (int i = 0; i < num; ++i)
        {
            cin >> cur;
            a.push_back(cur);
        }
        cin >> num;
        // b를 만든다.
        for (int i = 0; i < num; ++i)
        {
            cin >> cur;
            b.push_back(cur);
        }

        // a와 b를 내림차순으로 정렬한다.
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());

        // 비교후 결과를 출력한다.
        if (a > b)
            cout << 'A' << '\n';
        else if (a < b)
            cout << 'B' << '\n';
        else
            cout << 'D' << '\n';
    }
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