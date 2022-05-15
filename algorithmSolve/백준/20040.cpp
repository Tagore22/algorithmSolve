#include <iostream> // 이미 하나로 뭉쳐있는 대상들을 다시 뭉치려고 했을때 사이클 발생
#include <vector>

using namespace std;
int idx = 1;
int answer = 0;
bool findCycle = false;
class uni
{
private:
    vector<int> d;
    vector<int> parents;
public:
    uni(int num);
    int findParents(int num);
    void fusion(int a, int b);
};
uni::uni(int num) : d(num, 0), parents(num, 0)
{
    for (int i = 0; i < num; ++i)
        parents[i] = i;
}

int uni::findParents(int num)
{
    if (parents[num] == num)
        return num;
    return parents[num] = findParents(parents[num]);
}

void uni::fusion(int a, int b)// b를 a에 결속시킨다.
{
    a = findParents(a);
    b = findParents(b);

    if (a == b && !findCycle)
    {
        answer = idx;
        findCycle = true;
    }

    if (d[a] < d[b])
        swap(a, b);

    parents[b] = a;
    if (d[a] == d[b])
        ++d[a];
    ++idx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    uni UF(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        UF.fusion(a, b);
    }
    cout << answer << '\n';
    return 0;
}