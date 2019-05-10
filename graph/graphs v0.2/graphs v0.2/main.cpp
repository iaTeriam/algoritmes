#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <conio.h> 
#include <random> 
#include <locale> 

int graph_start = 0; //�� ������ �����
int graph_end = 0; //�� ������ �����
int graph[7][7]; // ����

int input() {
	//printf("\n���������� ��������\n");
	for (int i = 0; i < 7; i++) {
		//printf("\n First ���� %d\n",i);
		for (int j = 0; j < 7; j++) {
			//printf("\n Second ���� %d\n", i);
			if (j < i) {
				graph[i][j] = graph[j][i];
				//printf("\n���������_1\n"); //��� ������������ 
			}
			else if (j == i) {
				graph[i][j] = 0;
				//printf("\n���������_2\n");//��� ������������
			}
			else {
				graph[i][j] = 1 + rand() % 10;
				//printf("\n���������_3\n");//��� ������������
			}
		}
	}
	return 0;
}

int operation() {
	printf("\n������� ��������� ����\n");
	scanf("%d", &graph_start);
	printf("\n������� �������� ����\n");
	scanf("%d", &graph_end);

	//�������� �������� 

	int mark[7];
	int no_mark[7];

	int s[7]; //������ ������ �� ��������� �������� (�������� ����������) 
	for (int i = 0; i <= 6; i++) { //��������� ������� 
		s[i] = 0;
	}

	int d[7];  //������ ������ �� ��������� �������� (��������� ����������)

	int min = 1000;
	int id_min = 0;

	s[0] = graph_start;
	printf("\n������ ���������\n");
	printf("\n��� ������\n");
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
		printf("�������:%d\n", min);
	}
	printf("\n ����� ��� ������\n");

	//�������� ��� 2





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
		printf("�������:%d\n", min);
	}
}*/

int show() {
	for (int i = 0; i < 7; i++) {
		printf("\n");
		for (int j = 0; j < 7; j++) {
			printf("%d\t", graph[i][j]);
		}
	}
	printf("\n�� ����� %d, �� ����� %d, ����������� ��������� = \n", graph_start, graph_end);
	//������� ����

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