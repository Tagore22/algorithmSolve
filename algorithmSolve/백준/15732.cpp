#include <iostream>

using namespace std;

// 풀이.
// 매개변수 탐색과 이분 탐색을 떠올렸다면 어렵지 않으나 떠올리기가 어려운 문제였다.
// 결과적으로 이분 탐색을 통해 얻은 선물번호 mid가 마지막 도토리가 담긴 선물인지 찾는것이다.
// 하지만 몇가지 주의해야할점이 있는데 그것은 주석을 통해 남기겠다.

// 자세한 설명은 주석으로 남긴다.

// 선물의 시작점과 끝점, 건너뛰는 수를 담는 box 구조체.
struct box
{
    int from;
    int to;
    int div;
};

int N, K, D;
box board[10000];

// num번째 선물이 마지막 도토리를 담는지 확인하는 함수.
bool CalNum(int num)
{
    // 주의해야할점 첫번째. 실제로 도토리는 10억개이기에 int로 다 담을수 있으나
    // 주어진 범위에 모두 담을수 없을수 있다. 예를 들어 주어지는 입력값이
    // 100만, 10000, 10억이고
    // 1, 100만 1이 1만개 있을때 실젤 도토리는 10억개지만 들어갈수 있는 곳은
    // 그 이상이 되어버린다. 따라서 규칙이 여러개이기에 실제 도토리의 수보다
    // 담을수 있는 도토리의 수가 더 클수 있기 때문에 10억을 훌쩍 뛰어넘는다.
    // 그렇기에 int가 아닌 long long을 사용해야한다.
    long long ans = 0;
    for (int i = 0; i < K; ++i)
    {
        // 주의해야할점 두번째. 범위의 시작값보다 num이 작을때이다.
        // 처음에는 어차피 음수가 되어서 상관없겠지라고 생각했으나
        // 실제로는 그렇지 않다. 예를 들어 첫번째 규칙에서 num이 시작값보다 작아서
        // 0개가 되고 두번째 규칙에서 D보다 많은 경우 false를 반환해야한다. 하지만 만약
        // 첫번째 규칙에서 음수가 되어 두번째 규칙에서 많은값을 보완해준다면 true를 반환할수도 있게 된다.
        // 이러한 경우를 방지하기 위해 이 if문은 반드시 필요하다.
        if (num < board[i].from)
            continue;
        // num이 범위의 끝값보다 크다면 허구의 값을 구하게 된다. 이러한 것을 방지하기 위해
        // 더 작은값을 얻어야 한다.
        int cur = min(num, board[i].to);
        // 현재 구할수 있는 도토리의 수.
        ans += (cur - board[i].from) / board[i].div + 1;
    }
    return ans >= D;
}

void MakeAnswer()
{
    int l = 0, r = N + 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (CalNum(mid))
            r = mid;
        else
            l = mid + 1;
    }
    // 이 부분에서 살짝 고민했는데 역시 r을 출력하는게 맞다. r은 무조건 성공가능한 위치이기 때문이다.
    cout << r << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> D;
    for (int i = 0; i < K; ++i)
        cin >> board[i].from >> board[i].to >> board[i].div;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}