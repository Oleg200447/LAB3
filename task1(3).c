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
	int mas[100] = { '\0' };
	int n_in_mas;
	int max, max_indx = 1;
	int res = 1;
	int cheker = 0;
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
			printf("Input how much numbers in masive[1-100]\n");
			while (scanf_s("%d", &n_in_mas) != 1 || n_in_mas < 1)
			{
				rewind(stdin);
				printf("Mistake\n");
				printf("Input how much numbers in masive[1-100]\n");
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
				printf("The bigest:");
				max = mas[0];
				for (int i = 0; i < n_in_mas; i++)
				{

					if (mas[i] > max)
					{
						max = mas[i];
						max_indx = i + 1;
					}
				}
				for (int i = 0; i < n_in_mas; i++)
				{

					if (mas[i] == max)
					{
						max_indx = i + 1;
						printf("%3d", max_indx);
					}
				}
				printf("\n");

				for (int i = 0; i < n_in_mas; i++)
				{
					if (mas[i] == 0)
					{
						cheker++;
						for (int j = i + 1; j < n_in_mas; j++)
						{

							if (mas[j] == 0)
							{
								if (mas[i] == 0 && mas[i + 1] == 0)
								{
									cheker++;
									break;

								}
								cheker += 2;
								for (int k = i + 1; k < j; k++)
									res *= mas[k];
								break;
							}


						}

					}
					if (cheker == 2)
					{
						printf("There isnt nothing among");
						break;
					}
					if (cheker == 1)
					{
						printf("Only one 0");
						break;
					}

					if (cheker == 3)
					{
						printf("Result between zeros:%d", res);
						break;
					}
				}
				if (cheker == 0)
				{
					printf("There no any 0");
				}
			
	}	
	return 0;
}