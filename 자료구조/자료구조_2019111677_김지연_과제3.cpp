#include <iostream>
using namespace std;

#define STUDENT 10 //�л��� �Է�
#define SUBJECT 3 //����� �Է�
#define CLASS 3 //�ݼ� �Է�
#define NAME_LEN 5 //�����̸��� �ִ� ����


void main()
{
	int score[CLASS][SUBJECT][STUDENT] = { 
		{{90, 100, 95, 60, 70, 50, 20, 100, 98, 100},{75, 60, 88,67, 99,100,60,70,80,90},{70, 50, 80, 79, 85,89,78,67,90,88}},
		{{99, 10, 85, 70, 60, 80, 88, 89, 99, 22},{35, 55, 68,87, 100,10,40,50,90,70},{66, 55, 60, 44, 55,99,100,100,98,58}},
		{{90, 100, 95, 60, 70, 50, 20, 100, 98, 100},{75, 60, 88,67, 99,100,60,70,80,90},{70, 50, 80, 79, 85,89,78,67,90,88}}
	}; //�� �л��� ����,����,���������� ���ʷ� �Է�

	char class_name[SUBJECT][NAME_LEN] = { "����","����","����" };   //����� �迭�� ����� ���� ����� ����� �� ���
	
	int c,student, subject, total;
	float average;

	//1,2,3 ���� ���� ���
	printf("�� ���� ���� ���\n");
	for (int c = 0; c < CLASS; c++) {
		for (int subject = 0; subject < SUBJECT; subject++) 
		{
			int total = 0;
			for (int student = 0; student < STUDENT; student++) 
			{
				total = total + score[c][subject][student];//�� ������ �� �ձ��ϱ�
			}
			float average = total / STUDENT;//�� ������ ��հ��
			cout << c + 1 << "�� " << class_name[subject]<< "�� ���: " << average << endl;
		}
	}

	//���� ���
	printf("\n���� ���\n");
	for (int subject = 0; subject < SUBJECT; subject++)
	{
		int total = 0;//���� ��ü ��
		for (int c = 0; c < CLASS; c++)
			for (int student = 0; student < STUDENT; student++) {
				total += score[c][subject][student];

			}
		float average = total / (CLASS * STUDENT);

		cout << class_name[subject] << "�� ���: " << average << endl;
	}

}