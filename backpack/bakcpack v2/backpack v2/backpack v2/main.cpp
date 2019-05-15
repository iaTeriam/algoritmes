#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include "conio.h"


int R = 15;
int a[] = {13,14,15,1,2,6,7, 10, 8, 11, 12, 3, 4, 5 };
const int n = sizeof(a) / sizeof(int);
int v[n];
int best[100][n];
int kbest = 0;
int mx = 0;

void mark() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i])
			sum += a[i];
	}
	if (sum > R) return;
	if (sum < mx) return;
	if (sum > mx) { kbest = 0; mx = sum; }
	if (kbest < 100)
		for (int i = 0; i < n; ++i)
			best[kbest][i] = v[i];
	kbest++;
}

int next() {
	for (int i = 0; i < n; ++i)
		if (v[i] == 1)v[i] = 0;
		else { v[i] = 1; return 1; }
	return 0;
}

void show() {

	for (int j = 0; j < (kbest < 100 ? kbest : 100); ++j) {
		printf("%d лучшая выборка\n", j + 1);
		for (int i = 0; i < n; ++i) {
			if (best[j][i] == 1)
				printf(" a[%d]=%d, ", i, a[i]);
		}
		printf("\n\n");
	}
	printf("kbest=%i\n", kbest);
}

int main() {
	setlocale(LC_ALL, "rus");

	for (int i = 0; i < n; ++i)
		v[i] = 0;
	v[0] = 1;
	do {
		mark();
	} while (next());

	show();
	_getch();
	return 0;
}