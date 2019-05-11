#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h> 
#include <conio.h> 
#include <random> 
#include <locale> 

using namespace std;

int graph_start = 0; //от какого графа
int graph_end = 0; //до какого графа
int GR[7][7]; // граф
const int SIZE = 7;
int st;


int input() {
	//printf("\nЗаполнение началось\n");
	for (int i = 0; i < 7; i++) {
		//printf("\n First Цикл %d\n",i);
		for (int j = 0; j < 7; j++) {
			//printf("\n Second Цикл %d\n", i);
			if (j < i) {
				GR[i][j] = GR[j][i];
				//printf("\nПоложение_1\n"); //для отслеживания 
			}
			else if (j == i) {
				GR[i][j] = 0;
				//printf("\nПоложение_2\n");//для отслеживания
			}
			else {
				GR[i][j] = 1 + rand() % 10;
				//printf("\nПоложение_3\n");//для отслеживания
			}
		}
	}
	printf("Начальная вершина:");
	scanf("%d", &st);
	st--;
	return 0;
}

const int V = 7;
//алгоритм Дейкстры
void algoritm()
{
	int distance[V], count, index, i, u, m = st + 1;
	bool visited[V];
	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < V; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i < V; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	printf("Стоимость пути из начальной вершины до остальных:\t\n");
	for (i = 0; i < V; i++) if (distance[i] != INT_MAX)
		printf("%d > %d = %d\n", m, i + 1, distance[i]);
	else printf("%d > %d = маршрут недоступен\n", m, i + 1);
}

int show() {
	for (int i = 0; i < 7; i++) {
		printf("\n");
		for (int j = 0; j < 7; j++) {
			printf("%d\t", GR[i][j]);
		}
	}

	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));




	input();
	algoritm();
	show();

	_getch();
	return 0;
}