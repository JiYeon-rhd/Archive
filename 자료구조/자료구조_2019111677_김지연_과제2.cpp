#include <stdio.h> 
#define STUDENT 10 //학생수 입력
#define SUBJECT 3 //과목수 입력
#define NAME_LEN 5 //과목이름의 최대 길이
int main(void)
{
	int score[SUBJECT][STUDENT] = { {90, 100, 95, 60, 70, 50, 20, 100, 98, 100},{75, 60, 88,67, 99,100,60,70,80,90},{70, 50, 80, 79, 85,89,78,67,90,88} }; //각 학생의 국어,수학,영어점수를 차례로 입력
	char class_name[SUBJECT][NAME_LEN] = { "국어","수학","영어" };   //과목명도 배열로 만들어 과목별 평균을 계산할 때 사용
	int student,subject, sum;
	float average;

	printf("학생은 몇명입니까? : ");
	scanf_s("%d", &student);
	printf("몇개의 과목이 있습니까? : ");
	scanf_s("%d", &subject);


	//각 학생의 과목별 점수와 개인별 평균 
	for (student = 0; student < STUDENT; student++)   
	{
		printf("%d번째 학생의 성적을 입력하세요\n", student + 1);
		sum = 0;  //합계를 0으로 초기화함
		for (subject = 0; subject < SUBJECT; subject++)
		{
			printf("%s점수 = %d\n", class_name[subject], score[subject][student]);   //각 학생의 과목별 점수 출력
			sum += score[subject][student];       //개인별 총점을 계산                                  
		}

		printf("평균 = %.1f\n", (float)(sum) / SUBJECT);  //개인별 평균 계산
		printf("\n");
	}

	//과목별 평균점수
	printf("과목별 평균 점수\n");
	for (subject = 0; subject < SUBJECT; subject++)
	{
		printf("[%s] : ", class_name[subject]);
		sum = 0;  //합계를 0으로 초기화함
		for (student = 0; student < STUDENT; student++)
		{
			sum += score[subject][student];   //각 과목별 총점 계산
		}

		printf("%.1f\n", (float)(sum) / STUDENT);  //과목별 평균계산
	}


}