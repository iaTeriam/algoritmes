#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <locale>
const int kvar = 300;
int R = 31;
int a[] = { 1,2,6,9,13,14,15,16,17,18,19,20,21,22,23,24,7,8,10,11,12,3,4,5 };
const int n = sizeof(a) / sizeof(int);
int *v = new int[n];
int best[kvar][n];

int kbest = 0;
int max = 0;
int sum = 0;
int index = 0;

/*void input() {
	printf("Вес рюкзака = ");
	scanf("%d", &R);
	printf("\nКолличество вещей = ");
	scanf("%d", &k);
	printf("\nЗаполните массив вещей = ");
	for (int i = 0; i < k; i++) {
		printf("\nВещь %d = ", i + 1);
		scanf("%d", &a[i]);
	}
}*/

void forvard() {
	for (int i = index; i < n; ++i)
		if (sum + a[i] <= R) {
			v[i] = 1;
			sum += a[i];
		}
		else {
			v[i] = 0;
		}
}

int back() {
	if (v[n - 1] == 1)
	{
		v[n - 1] = 0;
		sum -= a[n - 1];
	}
	for (int i = n - 2; i >= 0; --i)
		if (v[i] == 1) {
			v[i] = 0;
			sum -= a[i];
			index = i + 1;
			return 1;
		}
	return 0;
}

void mark() {


	int sum = 0;
	for (int i = 0; i < n; ++i)
		if (v[i])
			sum += a[i];
	if (sum > R) return;
	if (sum < max)return;
	if (sum > max) {
		kbest = 0;
		max = sum;
	}
	if (kbest < kvar) {
		for (int i = 0; i < n; ++i)
			best[kbest][i] = v[i];
	}
	kbest++;

}

void show() {
	//printf("kbest = %d\n", kbest);
	for (int i = 0; i < (kbest < kvar ? kbest : kvar); ++i) {
		for (int j = 0; j < n; ++j)
			if (best[i][j])
				printf("%3i", a[j]);
		printf("\n");
	}
	printf("kbest = %d\n", kbest);
	printf("R= %d", R);
}



int main() {
	setlocale(LC_ALL, "rus");
	//input();
	do {
		forvard();
		mark();
	} while (back());
	show();

	_getch();
	return 0;
}
