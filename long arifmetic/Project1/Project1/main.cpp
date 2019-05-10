#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale>
#include <math.h>
#include "cstring"
#include "cmath"

const int N = 100, p = 10;
char a[N + 1];
char b[N + 1];
char ostat[N + 2];
char dest[N + 2];

void mins(char a[]) {
	for (int i = 0; i < N; ++i)
		a[i] = (p - 1 - a[i]);
	for (int i = 0; i < N; ++i)
		if (a[i] == p - 1)
			a[i] = 0;
		else {
			a[i]++;
			break;
		}
}
void input(char a[]) {
	char s[N + 2];
	for (int i = 0; i < N + 2; i++)
		s[i] = 0;
	scanf("%s", s);
	int sign = 1;
	int start = 0;
	if (s[0] == '+' || s[0] == '-') {
		sign = (s[0] == '+' ? 1 : -1);
		start = 1;
	}
	int i = 0, j = strlen(s) - 1;
	for (; j >= start; --j)
		a[i++] = s[j] - '0';
	for (; i < N; ++i)
		a[i] = 0;
	if (sign == -1)
		mins(a);
}
void output(char a[]) {
	int sign = 1;
	if (a[N - 1] >= p / 2) {
		sign = -1;
		mins(a);
		printf("-");
	}
	int i = N - 1;
	while (i > 0 && a[i] == 0)
		--i;
	for (; i >= 0; --i)
		printf("%d", a[i]);
	if (sign == -1)
		mins(a);
}
void add(char dest[], char a[], char b[]) {
	int ym = 0;
	for (int i = 0; i < N; ++i) {
		int t = a[i] + b[i] + ym;
		dest[i] = t % p;
		ym = t / p;
	}
}
void sub(char dest[], char a[], char b[]) {
	mins(b);
	add(dest, a, b);
	mins(b);
}
void mul(char dest[], char a[], char b[]) {
	for (int i = 0; i < N; ++i)
		dest[i] = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; i + j < N; ++j) {
			int t = a[i] * b[j] + dest[i + j];
			dest[i + j] = t % p;
			dest[i + j + 1] += t / p;
		}
}
int compare(char a[], char b[]) {
	int s = N - 1;
	int d = N - 1;
	while (s > 0 && a[s] == 0) --s;
	while (d > 0 && b[d] == 0) --d;
	if (s > d) return 1;
	if (s < d) return 0;
	for (; s >= 0; s--) {
		if (a[s] > b[s]) return 1;
		if (a[s] < b[s]) return 0;
	}
	return 1;
}
void del(char dest[], char t[], char a[], char b[]) {
	for (int i = 0; i < N; i++)
		dest[i] = t[i] = 0;
	int j = N - 1;
	while (j > 0 && b[j] == 0)
		--j;
	int asign = 1;
	int bsign = 1;
	if (a[N - 1] >= p / 2) {
		asign = -1;
		mins(a);
	}
	if (b[N - 1] >= p / 2) {
		bsign = -1;
		mins(b);
	}
	bool error = true;
	if (j == 0 && b[j] == 0) {
		error = false;
		printf("error");
	}
	if (error) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = N - 2; j >= 0; --j)
				t[j + 1] = t[j];
			t[0] = a[i];
			int cnt = 0;
			while (compare(t, b)) {
				sub(t, t, b);
				cnt++;
			}
			dest[i] = cnt;
		}
	}
	if (asign*bsign < 0) {
		mins(dest);
		mins(t);
	}
	if (asign == -1) mins(a);
	if (bsign == -1) mins(b);

}

int main()
{
	int choose;
	printf("Enter first number:\n");
	input(a);
	printf("Enter 1 for +\n      2 for -\n      3 for *\n      4 for /\n");
	scanf("%d", &choose);
	printf("Enter second number:\n");
	input(b);

	if (choose == 1) {
		printf("Sum:\n");
		add(dest, a, b);
		output(dest);
	}
	else if(choose == 2){
		printf("Difference:\n");
		sub(dest, a, b);
		output(dest);
	}
	else if (choose == 3) {
		printf("Composition:\n");
		mul(dest, a, b);
		output(dest);
	}
	else if (choose == 4) {
		printf("Quotient:\n");
		del(dest, ostat, a, b);
		output(dest);
		printf("\nRemainder:");
		output(ostat);
	}
	_getch();
}