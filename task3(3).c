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
	int mas1[100];
	int mas2[100];
	int mas_sum[100];
	int choise = -1;
	int n_in_mas = 20;
	printf("Input 0, if both masives by hands.Input 1, if both masives random.\n ");
	while (scanf_s("%d",&choise) < 1 || choise < 0 || choise>1)
	{
		rewind(stdin);
		printf("Error\n");
		printf("Input 0, if both masives by hands.Input 1, if both masives random.\n ");
	}
	{
		if (choise == 0)
		{
			
			for (int i = 0; i < n_in_mas; i++)
			{
				printf("Input %d number of first masive:", i + 1);
				while (scanf_s("%d", &mas1[i]) < 1 || mas1[i]<0 || mas1[i]>9)
				{
					rewind(stdin);
					printf("Error\n");
					printf("Input %d number of first masive:", i + 1);
				}

			}
			for (int i = 0; i < n_in_mas; i++)
			{
				printf("Input %d number of second masive:", i + 1);
				while (scanf_s("%d", &mas2[i]) < 1 || mas2[i] < 0 || mas2[i]>9)
				{
					rewind(stdin);
					printf("Error\n");
					printf("Input %d number of second masive:", i + 1);
				}

			}
		}
		
		if (choise == 1)
		{
			mas1[0] = Random(1, 9);
			for (int i = 1; i < n_in_mas; i++)
			{
				mas1[i] = Random(0, 9);

			}

			mas2[0] = Random(1, 9);
			for (int i = 1; i < n_in_mas; i++)
			{
				mas2[i] = Random(0, 9);

			}
		}
		printf("First number:");
		for (int i = 0; i < n_in_mas; i++)
			printf("%d", mas1[i]);
		printf("\n");
		printf("Second number:");
		for (int i = 0; i < n_in_mas; i++)
			printf("%d", mas2[i]);
		printf("\n");


		
			for (int i = 0; i < n_in_mas; i++)
			{
				mas_sum[i] = mas1[i] + mas2[i];
			}
			for (int i = n_in_mas - 1; i > 0; i--)
			{
				if (mas_sum[i] > 9)
				{
					mas_sum[i] = mas_sum[i] - 10;
					mas_sum[i - 1]++;
				}
			}
			if (mas_sum[0] > 9)
			{
				n_in_mas++;
				for (int j = n_in_mas; j > 0; j--)
					mas_sum[j] = mas_sum[j - 1];
				mas_sum[0] = 1;
				mas_sum[1] = mas_sum[1] - 10;
			}
		
		printf("Sum:");
		for (int i = 0; i < n_in_mas; i++)
			printf("%d", mas_sum[i]);
	}
	return 0;
}