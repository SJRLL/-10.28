#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***************************\n");
	printf("*******1.paly������**\n");
	printf("*******0.exit**************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int num = 0;
	printf("%d", ret);
	while (1)
	{
		printf("�������\n");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("�¶���\n");
			break;
		}
		else if (num > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}
int main()
 {
			int input = 0;
			srand((unsigned int)time(NULL));
			do
			{
				menu();
				printf("��ѡ��:>");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					game();
					break;
				case 0:
					break;
				default:
					printf("ѡ�����\n");
					break;
				}
			} while (input);
		    system("pause");
			return 0;
}