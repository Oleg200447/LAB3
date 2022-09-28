#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random(int min, int max)
{
	return min + rand() % (max - min + 1);
}


int main()
	{
	srand(time(NULL));
	int mas[100];
	int n_in_mas;
	int odd_in_row=0;
	int choise = -1;
	int max_n_in_mas = 100;
	printf("If you want random input 1 else 0\n");
	while (scanf_s("%d", &choise) < 1 || choise < 0 || choise > 1)
	{
		rewind(stdin);
		printf("Mistake\n");
		printf("If you want random input 1 else 0\n");
	}
	{
		if (choise == 0)
		{
			printf("Input how much numbers in masive[1-100]:");
			while (scanf_s("%d", &n_in_mas) < 1 || n_in_mas < 1|| n_in_mas>max_n_in_mas)
			{
				rewind(stdin);
				printf("Mistake\n");
				printf("Input how much numbers in masive[1-100]:");
			}
			{

				for (int i = 0; i < n_in_mas; i++)
				{
					printf("Input %d number:", i + 1);
					while (scanf_s("%d", &mas[i]) < 1)
					{
						rewind(stdin);
						printf("Mistake\n");
						printf("Input %d number:", i + 1);
					}
					
				}
				printf("Masive:");
				for (int i = 0; i < n_in_mas; i++)
				{
					printf("%4d", mas[i]);
				}
				printf("\n");
			}
		}
		if (choise == 1)
		{
			printf("Input how much numbers in masive[1-100]:");
			while (scanf_s("%d", &n_in_mas) != 1 || n_in_mas < 1 || n_in_mas>max_n_in_mas)
			{
				rewind(stdin);
				printf("Mistake\n");
				printf("Input how much numbers in masive[1-100]:");
			}
			{

				for (int i = 0; i < n_in_mas; i++)
				{
					mas[i] = Random(-10, 10);

				}
				printf("Masive:");
				for (int i = 0; i < n_in_mas; i++)
				{
					printf("%4d", mas[i]);
				}


				printf("\n");
			}
		}
		        if (mas[0] % 2 == 1 || mas[0] % 2 == -1)
				{
					for (int j = 1; j < n_in_mas; j++)
					{
						if (mas[j] % 2 == 1 || mas[j] % 2 == -1)
						{
							for (int k = j; k < n_in_mas; k++)
							{
								if (mas[k] % 2 == 1|| mas[k] % 2 == -1)
									odd_in_row++;
								if (mas[k] % 2 == 0)
									break;
							}
							for (int k = j; k < n_in_mas; k++)
								mas[k - 1] = mas[k + odd_in_row - 1];
							n_in_mas -= odd_in_row;
							odd_in_row = 0;
						}

					}

				}
				if (mas[0] % 2 == 0)
				{
					for (int j = 0; j < n_in_mas; j++)
					{
						if (mas[j] % 2 == 1 || mas[j] % 2==-1)
						{
							for (int k = j; k < n_in_mas; k++)
							{
								if (mas[k] % 2 == 1|| mas[k] % 2 == -1)
									odd_in_row++;
								if (mas[k] % 2 == 0)
									break;
							}
							for (int k = j; k < n_in_mas; k++)
								mas[k - 1] = mas[k + odd_in_row - 1];
							n_in_mas -= odd_in_row;
							odd_in_row = 0;
						}

					}

				}
				printf("Result:");
				for (int i = 0; i < n_in_mas; i++)
					printf("%4d", mas[i]);


	}




	return 0;
}


