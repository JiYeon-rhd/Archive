#include <stdio.h> 
#define STUDENT 10 //2학년 1반의 학생수 입력
int main(void)
{
	int student;
	int score[STUDENT] = { 90, 100, 95, 60, 70, 50, 20, 100, 98, 100 }; //각 학생의 점수 입력
	int i;
	int sum = 0;
	float average;

	printf("2학년 1반의 학생은 몇명입니까? : ");
	scanf_s("%d", &student);


	for (i = 0; i <= student-1; ++i) 
	{
		printf("%d번째 학생의 점수 = %d\n",i+1, score[i]);  //학생 순서대로 점수 출력
	}

	for (i = 0; i <= student - 1; ++i)
		sum += score[i];                                   //평균을 구하기 위해 총점을 구함

	printf("---------------------------------------------\n");
	average = sum / (float)student;                       //총점을 학생 수로 나누어 평균 구함
	printf("성적 평균 = %4.1f", average);

	return 0;
}
