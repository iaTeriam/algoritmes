/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale>
#include <math.h>

const int N = 400;

void Scan_Number(char string_one[], char string_two[]) {
	setlocale(LC_ALL, "ru");
	FILE *file;

	file = fopen("numbers//number_one.txt", "r");
	if (file == NULL) {
		printf("Error");
	}
	else {
		printf("GoodScanOne\n");
	}
	fscanf(file, "%s", string_one);
	fclose(file);

	file = fopen("numbers//number_two.txt", "r");
	if (file == NULL) {
		printf("Error");
	}
	else
	{
		printf("GoodScanTwo\n");
	}
	fscanf(file, "%s", string_two);
	fclose(file);
}
int strlen(char string[]) {
	int c = 0;
	while (string[c] != '\0')
	{
		c++;
	}

	return c;
}
void revers(char mass[]) {
	int i, j;
	int temp;

	for (j = 0; mass[j] != '\0'; ++j);
	for (i = 0; i < j; ++i)
	{
		temp = mass[i];
		mass[i] = mass[j - 1];
		mass[j - 1] = temp;
		--j;
	}

}
void revers(int mass[]) {
	int i, j;
	int temp;

	for (j = 0; mass[j] != '\0'; ++j);
	for (i = 0; i < j; ++i)
	{
		temp = mass[i];
		mass[i] = mass[j - 1];
		mass[j - 1] = temp;
		--j;
	}

}
void sum(char str_one[], char str_two[], int a, int b) {
	int s;//кол-во символов в большей строке и ++
	int x, y, z;//переводные символы int
	int d = 0;//переносна€ единица

	if (a > b) {
		s = a;
	}
	else {
		s = b;
	}

	char str_sum[N] = "";
	for (int i = 0; i < s; i++) {

		x = (int)str_one[i] - (int)'0';
		y = (int)str_two[i] - (int)'0';
		z = x + y + d;

		d = 0;//зануление

		if (z > 9) {
			z = z-10;
			d++;

		}

		str_sum[i] = z + '0';

		printf("%d\t%c\t%c\n", z, str_one[i], str_two[i]);
	}
	if (d != 0) {
		str_sum[s] = d + '0';
		printf("%c\n", str_sum[s]);
	}

	revers(str_sum);

	FILE *file;

	file = fopen("numbers//number_finish_sum.txt", "w");
	if (file == NULL) {
		printf("Error");
	}
	else {
		printf("GoodPrintSum\n");
	}
	fprintf(file, "%s", str_sum);
	fclose(file);

}
void sub(char str_one[], char str_two[], int a, int b) {
	//swap
	char str_c[] = "";

	if (b > a) {
		for (int i = 0; i < a; i++) {
			str_c[i] = str_one[i]; //c<--a
		}
		for (int i = 0; i < b; i++) {
			str_one[i] = str_two[i]; //a<--b
		}
		for (int i = 0; i < b; i++) {
			str_two[i] = 0;
			//1234 4321
			//0123 3210 что бы по€вилс€ данный ноль, а не прошлый результат
		}
		for (int i = 0; i < a; i++) {
			str_two[i] = str_one[i]; //b<--a
		}
	}

	//вычетание
	int s;//кол-во символов в большей строке и ++
	int x, y, z;//переводные символы int
	int d = 0;//переносна€ единица

	if (a > b) {
		s = a;
	}
	else {
		s = b;
	}

	char str_sub[N] = "";
	for (int i = 0; i < s; i++) {

		x = (int)str_one[i] - (int)'0';
		y = (int)str_two[i] - (int)'0';

		if (x < y) {
			x = x + 10;

				d++;
		}

		z = x - (y + d);
		str_sub[i] = z + '0';

	}

	if (d != 0) {
		str_sub[s] = d + '0';
	}

	revers(str_sub);

	FILE *file;

	file = fopen("numbers//number_finish_sub.txt", "w");
	if (file == NULL) {
		printf("Error");
	}
	else {
		printf("GoodPrintSub\n");
	}
	fprintf(file, "%s", str_sub);
	fclose(file);
}
void multiplication(char str_one[], char str_two[], int a, int b) {

}

/*
 0 * 0 =0--последний
 0 *
 */
 /*void multiplication(char str_one[], char str_two[], int size_a, int size_b)
 {
	 int c[1000];
	 int a[500];
	 int b[500];

	 for (int i = 0; i <= size_a; i++) {
		 a[i] = (int)str_one[i] - '0';
		 b[i] = (int)str_two[i] - '0';
	 }

	 printf("\n%d\n", a[0]);
	 printf("\n%d\n", b[0]);

	 int length = size_a + size_b +1;


	 for (int ix = 0; ix < size_a; ix++)
		 for (int jx = 0; jx < size_b; jx++)
			 c[ix + jx] += a[ix] * b[jx];

	 for (int ix = 0; ix < length; ix++)
	 {
		 c[ix + 1] += c[ix] / 10;
		 c[ix] %= 10;
	 }

	 while (c[length] == 0)
		 length--;

	 revers(c);

	 FILE *file;

	 file = fopen("numbers//number_finish_mult.txt", "w");
	 if (file == NULL) {
		 printf("Error");
	 }
	 else {
		 printf("GoodPrintMult\n");
	 }
	 printf("\n%d\n", c[0]);
	 fclose(file);

 }




void division() {

}


int main() {
	int a, b;

	printf("Hello\n");

	char string_one[N] = { "" };
	char string_two[N] = { "" };

	Scan_Number(string_one, string_two);

	a = strlen(string_one);
	b = strlen(string_two);

	printf(" ол-во символов в первом числе:%d\n", a);
	printf(" ол-во символов во втором числе числе:%d\n", b);

	revers(string_one);
	revers(string_two);

	//сложение 
	//sum(string_one, string_two,a,b);

	//вычитание
	//sub(string_one, string_two, a, b);

	//умножение 
	multiplication(string_one, string_two, a, b);

	//деление 


	_getch();
	return 0;
}
*/