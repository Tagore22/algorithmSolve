#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#define P pair<int, int>
#define F first
#define S second
#define INF 987654321

using namespace std;

// ���� Ǯ���µ� �� �ȵǴ��� �𸣰ڴ�. �ݷʵ� �� �´´�. ������ �� �̻��ѵ� 
// �и� Ŭ�����ʹ� �ٴ� Ȥ�� �ٸ� �̳׶� ���� �����ϴ� ��츸 �ִٰ� �����µ�
// �׷��� ���� ��쵵 �����־�� �Ѵ�. ���߿� �ٽú���.

int N, M;
char map[101][101];
int check[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int K;
vector<int> Throw;
vector<P> Move;

void reset_all() {
    memset(check, 0, sizeof(check));
    Move.clear();
}

void break_mineral(int x, int dir) {
    if (dir % 2 == 0) {
        int y = 1;
        while (1) {
            if (y > M) break;
            if (map[N - x + 1][y] == 'x') {
                map[N - x + 1][y] = '.';
                break;
            }
            y++;
        }
    }
    else {
        int y = M;
        while (1) {
            if (y < 1) break;
            if (map[N - x + 1][y] == 'x') {
                map[N - x + 1][y] = '.';
                break;
            }
            y--;
        }
    }
}

void bfs(int X, int Y) {
    queue<P> q;
    q.push({ X, Y });
    check[X][Y] = 1;
    while (!q.empty()) {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= N && yy >= 1 && yy <= M) {
                if (check[xx][yy] == 0 && map[xx][yy] == 'x') {
                    check[xx][yy] = 1;
                    q.push({ xx, yy });
                }
            }
        }
    }
}

int move_cluster(int x, int y) {
    int cnt = 0;
    for (int i = x + 1; i <= N; i++) {
        if (map[i][y] == 'x') {
            if (check[i][y] == 0) return INF; //�̹� �Ʒ��� ������ �̳׶��� �������� �̹��� X
            else return cnt;
        }
        else cnt++;
    }
    return cnt;
}

void remake_map() {
    int down = INF;
    for (int i = 0; i < Move.size(); i++) {
        int cnt = move_cluster(Move[i].F, Move[i].S);
        if (cnt == INF) continue;
        else down = min(cnt, down);
    }
    if (down == INF) return;
    for (int i = 0; i < Move.size(); i++) {
        int x = Move[i].F, y = Move[i].S;
        map[x][y] = '.';
    }
    for (int i = 0; i < Move.size(); i++) {
        int x = Move[i].F, y = Move[i].S;
        map[x + down][y] = 'x';
    }
}

bool find_float_cluster() {
    bool can = false; // ���߿� ���ִ� �̳׶��� ���� ���, false�� return ���ش�.
    for (int i = 1; i <= M; i++) {
        if (check[N][i] == 0 && map[N][i] == 'x') bfs(N, i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 'x' && check[i][j] == 0) { // ���߿� ���ִ� �̳׶�
                Move.push_back({ i,j }); // �����̱� ���� ��ǥ�� �����Ѵ�.
                can = true;
            }
        }
    }
    return can;
}

void show_map() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve() {
    for (int i = 0; i < Throw.size(); i++) {
        reset_all();
        break_mineral(Throw[i], i);
        if (!find_float_cluster()) continue;
        remake_map();
    }
    show_map();
}


int main() {
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
    cin >> K;
    for (int i = 1; i <= K; i++) {
        int x;
        cin >> x;
        Throw.push_back(x);
    }
    solve();
    return 0;
}