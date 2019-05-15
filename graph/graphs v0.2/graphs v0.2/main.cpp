#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 
#include <random> 
#include <locale> 

int start = 0; //от какого графа
int graph_end = 0; //до какого графа
const int V = 7;
int GR[V][V]; // граф


void input() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j <V ; j++) {
			if (j < i) {
				GR[i][j] = GR[j][i];
			}
			else if (j == i) {
				GR[i][j] = 0;
			}
			else {
				printf("Чему равен путь из %d в %d:\n",i+1,j+1);
				scanf("%d", &GR[i][j]);
				//GR[i][j] = 0 + rand() % 10;
			}
		}
	}
	printf("Начальная вершина:");
	scanf("%d", &start);

	printf("Конечная вершина:");
	scanf("%d", &graph_end);

	start--;
	graph_end--;
}

//алгоритм Дейкстры
void algoritm()
{
	int distance[V], count, index, i, u, m = start + 1;
	bool visited[V];
	int test1, test2;


	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}

	distance[start] = 0;
	printf("Путь где номера это вершины:\n");
	for (count = 0; count < V - 1; count++){
		int min = INT_MAX;
		for (i = 0; i < V; i++)
			if (!visited[i] && distance[i] <= min) 
			{
				min = distance[i]; 
				index = i;
			}
		u = index;
		visited[u] = true;
		
		for (i = 0; i < V; i++) {
			test1 = distance[graph_end];
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX && distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
			test2 = distance[graph_end];
			if (test1 != test2) {
			printf("%d\t", u+1);
			}
		}
	}
	printf("%d", graph_end+1);
	printf("\n");
	printf("Стоимость пути из начальной вершины до остальных:\t\n");
	for (i = 0; i < V; i++) if (distance[i] != INT_MAX)
		printf("%d > %d = %d\n", m, i + 1, distance[i]);
	else printf("%d > %d = маршрут недоступен\n", m, i + 1);
}

void show() {
	for (int i = 0; i < 7; i++) {
		printf("\n");
		for (int j = 0; j < 7; j++) {
			printf("%d\t", GR[i][j]);
		}
	}
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