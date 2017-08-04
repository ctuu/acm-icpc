#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_N = 100000;
const int MAX_NN = (1 << 20); // should be bigger than MAX_N

int N, Q;
int inp[MAX_N];

int id[MAX_N];
int len[MAX_N];
int lend[MAX_N]; // [lend[i], rend[i])
int rend[MAX_N];

int NN;
int seg[2 * MAX_NN - 1];

void seg_gather(int u) {
    seg[u] = max(seg[u * 2 + 1], seg[u * 2 + 2]);
}

void seg_init() {
    NN = 1;
    while (NN < N)
        NN *= 2;

    memset(seg, 0, sizeof(seg));    // val that won't affect result
    memcpy(seg + NN - 1, len, sizeof(int) * N); // fill in leaves
}

void seg_build(int u) {
    if (u >= NN - 1) { // leaf
        return;
    }

    seg_build(u * 2 + 1);
    seg_build(u * 2 + 2);
    seg_gather(u);
}

int seg_query(int a, int b, int u, int l, int r) {
    if (l >= b || r <= a) {
        return 0;
    }

    if (a <= l && r <= b) {
        return seg[u];
    }

    int m = (l + r) / 2;
    int res1 = seg_query(a, b, u * 2 + 1, l, m);
    int res2 = seg_query(a, b, u * 2 + 2, m, r);

    return max(res1, res2);
}

int main() {
    while (scanf("%d", &N)&&N!=0) {
            scanf("%d",&Q);
        for (int i = 0; i < N; i++) {
            scanf("%d", &inp[i]);
        }

        // [s, t)
        int s = 0, t = 0, idx = 0;
        while (s < N) {
            while (t < N && inp[t] == inp[s]) {
                id[t++] = idx;
            }

            lend[idx] = s;
            rend[idx] = t;
            len[idx] = t - s;

            s = t;
            idx++;
        }

        N = idx;
        seg_init();
        seg_build(0);

        while (Q--) {
            int a, b; scanf("%d %d", &a, &b); a--; b--;

            if (id[a] == id[b]) {
                printf("%d\n", b - a + 1);
                continue;
            }

            if (id[a] + 1 == id[b]) {
                int len_a = rend[id[a]] - a;
                int len_b = b + 1 - lend[id[b]];
                printf("%d\n", max(len_a, len_b));
                continue;
            }

            int len_a = rend[id[a]] - a;
            int len_b = b + 1 - lend[id[b]];
            int len_inner = seg_query(id[a] + 1, id[b], 0, 0, NN);

            printf("%d\n", max(max(len_a, len_b), len_inner));
        }
    }
    return 0;
}