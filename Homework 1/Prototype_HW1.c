/*
* �������ڰ�� 2014�� �ܿ�����б� 
* �Ǵ�� 2009190021 UIC �����а�
*
* 2015�� 1�� 3�� ����Ͽ� Visual Studio 2010 ���� �ۼ��Ͽ����ϴ�.
* �� ���α׷��� �ΰ��� ����: X, Y (Y�� 0�� �ƴ�) �� a, s, m, d �� �ϳ��� ���ڸ� argument �� ���� ��
* ������ ���� double ���·� ����� �ݴϴ�.
* ���ڰ��� a �� �Է��� ��� X + Y ��,
* ���ڰ��� s �� �Է��� ��� X - Y ��,
* ���ڰ��� m �� �Է��� ��� X * Y ��,
* ���ڰ��� d �� �Է��� ��� X / Y �� ������� ����� �ְ� �˴ϴ�.
*
* ������ ���� �Է����� ���� �ÿ��� �����޼����� �Բ� ���α׷��� ����˴ϴ�.
* X, Y ���� ������ �ƴ� ���� �Է��� ��� ������ �����޼��� ���� ���α׷��� ����˴ϴ�.
*/

#include <stdio.h>    // ���̺귯�� ��� �� �Լ� ������Ÿ�� ����
#include <math.h>

double add (int x, int y);
double subtract (int x, int y);
double multiply (int x, int y);
double divide (int x, int y);
double print_result (double z);


int main(void)    // �����Լ� ����
{
	// ��������
	int x, y, invalid=0;
	char comp;
	double result;

	// �������� �� �Է�
	printf("You need to type two integers X, Y and a character\n"
		"First, decide which operation to conduct by choosing one of the following characters:\n"
		"If you type \"a\", then we will compute X + Y \n"
		"If you type \"s\", then we will compute X - Y \n"
		"If you type \"m\", then we will compute X * Y \n"
		"If you type \"d\", then we will compute X / Y \n");
	printf("What is your choice?> ");
	scanf("%c", &comp);
	printf("\nNow, give us the first integer X> ");
	scanf("%d", &x);

	if (comp=='d'){    // ���ڿ� d �� ������ ��� �����ִ� ������ 0�� �ƴ� ������ �Է��ϵ��� �ȳ��� ���
		printf("Type the second \"NONZERO\" integer Y> ");
	}
	else{
		printf("Type the second integer Y> ");
	}
	scanf("%d", &y);

	// �Է��� �ڷḦ �������� �Լ��� �̿��� ����� ��� ���� 
	if (comp=='a'){
		result=add(x,y);
	}
	else if (comp=='s'){
		result=subtract(x,y);
	}
	else if (comp=='m'){
		result=multiply(x,y);
	}
	else if (comp=='d'){
		if(y==0){
		printf("\nIf you choose to divide, Y must be a nonzero integer");    // ������ ���ڰ� 0�� ��� �����޼��� ��� 
		invalid=1;    // �׸��� invalid �� �����Ͽ� �Ʒ� �Է°��� �߸��Ǿ��ٴ� �޼����� �Բ����
		}
		else{
		result=divide(x,y);    // ������ ���ڰ� 0 �� �ƴ� ��� ���������� ���� 
		}
	}
	else{
		invalid=1;
	}

	if (invalid==1){    // �Էµ� ���ڰ� a, s, m, d �� �ϳ��� �ƴ� ��,
		printf("\nYou did not follow the input directions properly,\n"
			"Please run the program again.\n");    // �����޼��� ��� �� �����Լ� ����
	}
	else{
		print_result(result);    // �Էµ� ���ڿ� �̻��� ���� ��� �Լ��� �̿��� ����� ��� ���� 
		printf("\n\nThank you for using this program.\nSee you next time ^.^\n\n");    // ����޽��� ��� �� �����Լ� ����
	}

	// �����Լ� ����
	return 0;
}


// �ʿ��� �Լ� ����
double add (int x, int y){
	return (double) (x+y);
}

double subtract (int x, int y){
	return (double) (x-y);
}

double multiply (int x, int y){
	return (double) (x*y);
}

double divide (int x, int y){
	return (double)x / (double)y;
}

double print_result (double z){
	printf("\n>>>> The result of the operation is: %.4lf", z);    // �Լ��� ����Ǹ� ������� ���
	return 0.0;    // 0.0 ���ϰ��� ȭ�鿡 ǥ�õ��� ���� ���̸�, �ܼ��� ������ ���߱� ���� ����
}
