#include <stdio.h> 
#define STUDENT 10 //2�г� 1���� �л��� �Է�
int main(void)
{
	int student;
	int score[STUDENT] = { 90, 100, 95, 60, 70, 50, 20, 100, 98, 100 }; //�� �л��� ���� �Է�
	int i;
	int sum = 0;
	float average;

	printf("2�г� 1���� �л��� ����Դϱ�? : ");
	scanf_s("%d", &student);


	for (i = 0; i <= student-1; ++i) 
	{
		printf("%d��° �л��� ���� = %d\n",i+1, score[i]);  //�л� ������� ���� ���
	}

	for (i = 0; i <= student - 1; ++i)
		sum += score[i];                                   //����� ���ϱ� ���� ������ ����

	printf("---------------------------------------------\n");
	average = sum / (float)student;                       //������ �л� ���� ������ ��� ����
	printf("���� ��� = %4.1f", average);

	return 0;
}
