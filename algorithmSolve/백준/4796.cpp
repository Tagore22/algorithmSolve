#include <iostream>

using namespace std;

// 풀이.
// 연속되는 P일중 L일만 캠핑장을 쓸수 있을때 총 V일중 몇일을 쓸수 있는지를 알아내는 문제다.
// 예를 들어 문제에서 주어진 예시 첫번째를 보면 L : 5, P : 8, V : 20인데,
// 처음 8일까지 총 5일을 쓸수 있고 다시 9 ~ 16까지 5일을 쓸수 있으며 나머지
// 17 ~ 20까지 4일을 쓸수 있기에 답은 14이다.
// 이를 통해서 아래와 같은 점화식을 유추해낼수 있다.

// answer = V / P * L + min(V % P, L);

// 즉 총 V일중에서 P일이 몇번 존재하는지를 찾고 각 P일마다 L일을 사용할수 있기에 L만큼 곱해준다.
// 그후 V일중 P일을 나누고 난 나머지와 P중 작은 수만큼을 더해주면 된다.

// 자세한 설명은 주석으로 남긴다.

int L, P, V;

void MakeAnswer()
{
    int idx = 0;
    while (true)
    {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            break;

        ++idx;
        // 상술한 점화식. V를 P일로 나누어 끝까지 사용할수 있는 일자를 구하고 나머지 일자중 L일과 비교하여
        // 더 적은 수를 더해준다.
        cout << "Case " << idx << ": " << V / P * L + min(V % P, L) << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}