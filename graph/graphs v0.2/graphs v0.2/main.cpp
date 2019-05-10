#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 
#include <random> 
#include <locale> 

int graph_start = 0; //от какого графа
int graph_end = 0; //до какого графа
int graph[7][7]; // граф

int input() {
	//printf("\nЗаполнение началось\n");
	for (int i = 0; i < 7; i++) {
		//printf("\n First Цикл %d\n",i);
		for (int j = 0; j < 7; j++) {
			//printf("\n Second Цикл %d\n", i);
			if (j < i) {
				graph[i][j] = graph[j][i];
				//printf("\nПоложение_1\n"); //для отслеживания 
			}
			else if (j == i) {
				graph[i][j] = 0;
				//printf("\nПоложение_2\n");//для отслеживания
			}
			else {
				graph[i][j] = 1 + rand() % 10;
				//printf("\nПоложение_3\n");//для отслеживания
			}
		}
	}
	return 0;
}

int operation() {
	printf("\nВведите начальный граф\n");
	scanf("%d", &graph_start);
	printf("\nВведите конечный граф\n");
	scanf("%d", &graph_end);

	//алгоритм дейкстры 

	int mark[7];
	int no_mark[7];

	int s[7]; //первый массив из алгоритма дейкстры (помещаем переменные) 
	for (int i = 0; i <= 6; i++) { //зануление массива 
		s[i] = 0;
	}

	int d[7];  //второй массив из аглоритма дейкстра (изменияем переменные)

	int min = 1000;
	int id_min = 0;

	s[0] = graph_start;
	printf("\nначало алгоритма\n");
	printf("\nшаг первый\n");
	for (int i = 0; i <= 6; i++) {
		if (i == graph_start) {
			d[i] = 0;
		}
		else {
			d[i] = graph[graph_start][i];
		}
		if (d[i] > 0 && d[i] < min) {
			min = d[i];
			id_min = i;
		}
		printf("\nd[i] = %d\t", d[i]);
		printf("минимум:%d\n", min);
	}
	printf("\n Конец шаг первый\n");

	//доделать шаг 2





	return 0;
}

/*int proverka(int d[], int graph_start, int id_min) {
	int min = 1000;
	for (int i = 0; i <= 6; i++) {
		if (i == graph_start) {
			d[i] = 1000;
		}
		else {
			d[i] = graph[graph_start][i];
		}
		if (d[i] > 0 & d[i] < min) {
			min = d[i];
			id_min = i;
		}
		printf("\nd[i] = %d\t", d[i]);
		printf("минимум:%d\n", min);
	}
}*/

int show() {
	for (int i = 0; i < 7; i++) {
		printf("\n");
		for (int j = 0; j < 7; j++) {
			printf("%d\t", graph[i][j]);
		}
	}
	printf("\nОт графа %d, до графа %d, минимальное растояние = \n", graph_start, graph_end);
	//вывести путь

	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));




	input();
	operation();
	show();

	_getch();
	return 0;
}