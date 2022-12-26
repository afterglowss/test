#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int cnt, n, m, i, j, **p, previous=0;
	scanf("%d %d", &n, &m);
	p = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++) {
		p[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	for (i = 0; i < m; i++) {
		cnt = 0; previous = 0;
		for (j = 0; j < n; j++) {
			if (p[i][j] == 0) {
				if (previous == 0) cnt++;
				else {
					printf("%d ", cnt);
					previous = 0; cnt = 1;
				}
			}
			else if (p[i][j] == 1) {
				if (previous == 0) {
					printf("%d ", cnt);
					previous = 1; cnt = 1;
				}
				else {
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	for (i = 0; i < m; i++) {
		free(p[i]);
	}
	free(p);
}