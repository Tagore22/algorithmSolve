#include <iostream>

using namespace std;

// 풀이.
// 처음에는 로직이 잘 생각나질 않았다. 하지만 문제에서 고르는 아이스크림의 수를 3가지로
// 명확하게 집어준 이유가 있을것이었고, 그것을 이용해야했다. 결과적으로 주먹구구식으로
// 풀어야했다. 불가능한 조합들을 bool 배열에 저장해놓고 각 선택시 확인한다. 
// 상술한대로 3가지로 주어졌기에 3중 for문을 이용하였다.

bool HatePair[201][201] = { false, };
int N, M;

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i <= N - 2; ++i)
    {
        for (int j = i + 1; j <= N - 1; ++j)
        {
            if (HatePair[i][j])
                continue;
            for (int z = j + 1; z <= N; ++z)
            {
                if (HatePair[j][z] || HatePair[i][z])
                    continue;
                ++answer;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int first, second;
        cin >> first >> second;
        HatePair[first][second] = true;
        HatePair[second][first] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}