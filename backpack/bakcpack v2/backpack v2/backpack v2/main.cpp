#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale>
//const int kvar = 300;
//int R = 31;
//int a[] = { 1,2,6,9,13,14,15,16,17,18,19,20,21,22,23,24,7,8,10,11,12,3,4,5 };
int R = 15;
int a[] = { 7,8,10,11,12,13,3,4,5 };
const int n = sizeof(a) / sizeof(int);
int *v = new int[n];
int best[100][n];

int kbest = 0;
int max = 0;
int sum = 0;



int next() {
	for (int i = 0; i < n; ++i) {
		if (v[i] == 1)
			v[i] = 0;
		else {
			v[i] = 1;
			return 1;
		}
		return 0;
	}
	return 0;
}

void mark() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (v[i])
			sum += a[i];
	}
	if (sum > R) return;
	if (sum < max)return;
	if (sum > max) {
		kbest = 0;
		max = sum;
	}
	if (kbest < 100) {
		for (int i = 0; i < n; ++i)
			best[kbest][i] = v[i];
	}
	kbest++;
}

void show() {
	for (int i = 0; i < (kbest < 100 ? kbest : 100); ++i) {
		for (int j = 0; j < n; ++j)
			if (best[i][j])
				printf("%3i", a[j]);
		printf("\n");
	}
	printf("kbest = %d\n", kbest);
	printf("R = %d", R);
}



int main() {
	setlocale(LC_ALL, "rus");

	for (int i = 0; i < n; ++i) {
		v[i] = 0;
		v[n - 1] = 1;
		do {
			mark();
		} while (next());
	}
	show();
	_getch();
	return 0;
}