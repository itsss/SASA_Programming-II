#include <stdio.h>
#include <queue>
using namespace std;

int map[111][111], n, m;
queue<int> qr, qc;

int count(int r, int c) {
    return map[r-1][c] + map[r+1][c] + map[r][c-1] + map[r][c+1];
}

main() {
    int i, j;
    int tr, tc, flag = 0;
    int res = 0;

    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
            map[i][j] = !map[i][j];

        }

    while(1) {
        flag = 0;
        res++;
        for(i = 2; i < n; i++)
            for(j = 2; j < m; j++)
                if ( map[i][j] == 0 && count(i, j) >= 2 ) {
                    flag = 1;
                    qr.push(i); qc.push(j);
                }
        if ( flag == 1 ) {
            while( !qr.empty() ) {
                tr = qr.front(); tc = qc.front();
                map[tr][tc] = 1;
                qr.pop(); qc.pop();
            }
        }
        else {
            printf("%d", res - 1);
            return 0;
        }
    }
}
