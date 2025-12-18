#include <iostream>
#include <vector>

using namespace std;

// 풀이
// 오랜만에 유니온 파인드 문제였다. 다만 묶는 부분이 친구와 적 2가지로
// 나뉘었기에 고민을 좀 했다. 더 좋은 방법은 아래 구현처럼 vector를 쓰지
// 않고 f처럼 그냥 배열을 쓰는 방법이지만 구태여 설명하기 위해 수정하지 않았다.

// 자세한 설명은 주석으로 남긴다.

int n, m;
int f[1001], r[1001];
vector<int> e[1001]; // 상술한대로 int e[1001]; 으로 하는게 더 낫다.

// return 문이 중요한대 Find()가 애시당초 가장 루트 번호를 찾는 함수이기에
// 함수 호출 종료시 루트 번호를 갱신하는 방식으로 최적화가 가능하다.
int Find(int num)
{
    if (f[num] == num)
        return num;
    return f[num] = Find(f[num]);
}

// 두 부분을 잇는 함수. r[]을 이용하여 둘중 랭크가 높은쪽으로
// 합친다. from에 to를 합치는 것으로 구현되었기에
// from이 랭크가 더 낫다면 from과 to를 swap()으로 변환한다.
void Merge(int from, int to)
{
    int first = Find(from);
    int second = Find(to);
    if (first == second)
        return;
    if (r[first] < r[second])
        swap(from, to);
    f[second] = first;
    if (r[first] == r[second])
        ++r[first];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    for (int i = 0; i < m; ++i)
    {
        char c;
        int from, to;
        cin >> c >> from >> to;
        if (c == 'F')
        {
            Merge(from, to);
        }
        else
        {
            // 이 부분이 리팩토링할 부분인데 기존에는 적 부분을 별도의 루트로
            // 이어야하나 고민했다. 그러나 그건 아니었는데 적 부분의 루트와
            // 친구 부분의 루트가 연동이 되질 않았기 때문이다. 힘을 조금 빼고
            // 생각해보면 간단한데 그냥 1차원 배열로 현재 적의 번호를 저장해놓으면
            // 된다. 루트를 단 하나로만 관리한다면 Merge(e[from], k)등으로 합쳤을때
            // 모든 경우가 연동되기 때문이다. 이전에는 모든 적들을 계속 저장해놓고
            // 있어야 된다고 생각했는데 연동되는 루트를 사용하기 때문에 순간순간의
            // 적이 몇번인지만 알아도 충분했다.
            for (auto k : e[to])
                Merge(from, k);
            for (auto k : e[from])
                Merge(k, to);
            e[from].push_back(to);
            e[to].push_back(from);
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; ++i)
        if (f[i] == i)
            ++answer;
    cout << answer << '\n';
    return 0;
}