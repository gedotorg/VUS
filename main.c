#define _CRT_SECURE_NO_WARNINGS
#define MAX 9
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>


long long inputCheck();
void multi();

int main() {
	int isOpen = 1;
	while (isOpen == 1) {

		long long num1 = 0, num2 = 0;
		int k = 1;

		printf("Выберете операцию: \n");
		printf(" 1 - сложение \n 2 - вычитание \n 3 - умножение \n 4 - деление \n 5 - возведение в степень \n 6 - изъятие корня \n esc - выход \n ");
		int check = _getch();

		if (check == 27)
			isOpen = 0;

		else if (check > 48 && check < 55) 
		{

			switch (check) 
			{
			case 49:
				printf("\033[0d\033[2J");
				printf("*Сложение*\n");
				num1 = inputCheck();
				num2 = inputCheck();
				printf("Ваш результат: %lld\n", num1 + num2);
				break;
			case 50:
				printf("\033[0d\033[2J");
				printf("*Вычитание*\n");
				printf("Введите уменьшаемое число: ");
				scanf("%lld", &num1);
				printf("Введите вычитаемое число: ");
				scanf("%lld", &num2);
				printf("Ваш результат: %lld\n", num1 - num2);
				break;

			case 51:
				printf("\033[0d\033[2J");
				printf("*Умножение*\n");
				printf("Введите первое число: ");
				scanf("%lld", &num1);
				printf("Введите второе число: ");
				scanf("%lld", &num2);
				printf("Ваш результат: %lld\n", num1 * num2);
				break;
			case 52:
				printf("\033[0d\033[2J");
				printf("*Деление*\n");
				printf("Введите делимое: ");
				scanf("%lld", &num1);
				printf("Введите делитель: ");
				scanf("%lld", &num2);
				printf("Ваш результат: %lld\n", num1 / num2);
				break;
			case 53:
				printf("\033[0d\033[2J");
				printf("*Возведение в степень*\n");
				multi();
				break;
			case 54:
				printf("\033[0d\033[2J");
				printf("*ИзЪятие корня*\n");
				printf("Введите число: ");
				scanf("%lld", &num1);
				printf("Введите степень корня: ");
				scanf("%lld", &num2);
				printf("Ваш результат: %lld\n", num1 + num2);
				break;
			}

		}
		else 
		{
			printf("Такого выбора не было!");
		}
		
		


	}
	return 0;
}

void multi() 
{
	long long maxResult = 9223372036854775807;
	long long num1, num2;
	printf("1: ");
	num1 = inputCheck();
	printf("2: ");
	num2 = inputCheck();
	long long result = pow(maxResult, 1.0 / num2);
	if (num2 < 0) {
		printf("Введите положительную степень\n");
		multi();
	}
	else if (result < num1) {
		printf("Введите числа поменьше\n");
		multi();
	}
	else {
		int i = pow(num1, num2);
		printf("Ваш результат: %lld\n", i);
		main();
	}
}

long long inputCheck()
{
	long long num = 0;
	int s = 0;
	int k = -1;
	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char strings[MAX]; 
	char rings[MAX];

	fgets(strings, MAX, stdin);
	while ((getchar()) != '\n');
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (strings[i] == numbers[j]) 
			{
				s++;
			}
		}
	}
	if (s > 0) {
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (strings[i] == numbers[j])
				{
					k++;
					rings[k] = strings[i];
					break;
				}
			}
		}
		printf("Это ваше число: %d\n", atoi(rings));

		num = atoi(rings);
		return num;
	}
	else
	{
		printf("Введите хотя бы одну цифру.\n");
		inputCheck();
	}
}



