#include <stdio.h> 
#define STUDENT 10 //�л��� �Է�
#define SUBJECT 3 //����� �Է�
#define NAME_LEN 5 //�����̸��� �ִ� ����
int main(void)
{
	int score[SUBJECT][STUDENT] = { {90, 100, 95, 60, 70, 50, 20, 100, 98, 100},{75, 60, 88,67, 99,100,60,70,80,90},{70, 50, 80, 79, 85,89,78,67,90,88} }; //�� �л��� ����,����,���������� ���ʷ� �Է�
	char class_name[SUBJECT][NAME_LEN] = { "����","����","����" };   //����� �迭�� ����� ���� ����� ����� �� ���
	int student,subject, sum;
	float average;

	printf("�л��� ����Դϱ�? : ");
	scanf_s("%d", &student);
	printf("��� ������ �ֽ��ϱ�? : ");
	scanf_s("%d", &subject);


	//�� �л��� ���� ������ ���κ� ��� 
	for (student = 0; student < STUDENT; student++)   
	{
		printf("%d��° �л��� ������ �Է��ϼ���\n", student + 1);
		sum = 0;  //�հ踦 0���� �ʱ�ȭ��
		for (subject = 0; subject < SUBJECT; subject++)
		{
			printf("%s���� = %d\n", class_name[subject], score[subject][student]);   //�� �л��� ���� ���� ���
			sum += score[subject][student];       //���κ� ������ ���                                  
		}

		printf("��� = %.1f\n", (float)(sum) / SUBJECT);  //���κ� ��� ���
		printf("\n");
	}

	//���� �������
	printf("���� ��� ����\n");
	for (subject = 0; subject < SUBJECT; subject++)
	{
		printf("[%s] : ", class_name[subject]);
		sum = 0;  //�հ踦 0���� �ʱ�ȭ��
		for (student = 0; student < STUDENT; student++)
		{
			sum += score[subject][student];   //�� ���� ���� ���
		}

		printf("%.1f\n", (float)(sum) / STUDENT);  //���� ��հ��
	}


}