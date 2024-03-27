#include <iostream>
using namespace std;

#define STUDENT 10 //학생수 입력
#define SUBJECT 3 //과목수 입력
#define CLASS 3 //반수 입력
#define NAME_LEN 5 //과목이름의 최대 길이


void main()
{
	int score[CLASS][SUBJECT][STUDENT] = { 
		{{90, 100, 95, 60, 70, 50, 20, 100, 98, 100},{75, 60, 88,67, 99,100,60,70,80,90},{70, 50, 80, 79, 85,89,78,67,90,88}},
		{{99, 10, 85, 70, 60, 80, 88, 89, 99, 22},{35, 55, 68,87, 100,10,40,50,90,70},{66, 55, 60, 44, 55,99,100,100,98,58}},
		{{90, 100, 95, 60, 70, 50, 20, 100, 98, 100},{75, 60, 88,67, 99,100,60,70,80,90},{70, 50, 80, 79, 85,89,78,67,90,88}}
	}; //각 학생의 국어,수학,영어점수를 차례로 입력

	char class_name[SUBJECT][NAME_LEN] = { "국어","수학","영어" };   //과목명도 배열로 만들어 과목별 평균을 계산할 때 사용
	
	int c,student, subject, total;
	float average;

	//1,2,3 반의 과목별 평균
	printf("각 반의 과목별 평균\n");
	for (int c = 0; c < CLASS; c++) {
		for (int subject = 0; subject < SUBJECT; subject++) 
		{
			int total = 0;
			for (int student = 0; student < STUDENT; student++) 
			{
				total = total + score[c][subject][student];//각 과목의 총 합구하기
			}
			float average = total / STUDENT;//각 과목의 평균계산
			cout << c + 1 << "반 " << class_name[subject]<< "의 평균: " << average << endl;
		}
	}

	//과목별 평균
	printf("\n과목별 평균\n");
	for (int subject = 0; subject < SUBJECT; subject++)
	{
		int total = 0;//과목별 전체 합
		for (int c = 0; c < CLASS; c++)
			for (int student = 0; student < STUDENT; student++) {
				total += score[c][subject][student];

			}
		float average = total / (CLASS * STUDENT);

		cout << class_name[subject] << "의 평균: " << average << endl;
	}

}