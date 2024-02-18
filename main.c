#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include <stdio.h>
#include <stdlib.h>

int* calculate_coffee(int duration, int gender, int bodyweight, int drink, int thresh) {
	double coefficient = 0.0, BV = 0.0;

	if (thresh == 1)
	{
		coefficient = .5;
	}
	else if (thresh == 2)
	{
		coefficient = .7;
	}
	else
	{
		coefficient = .9;
	}

	if (gender == 1)
	{
		BV = .07 * bodyweight;
	}
	else
	{
		BV = .065 * bodyweight;
	}
	int time[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
	int t[10] = { 0 };
	double Caffine[10] = { 0 };
	for (int i = 0; i < duration; i++)
	{
		t[i] = time[i];

		Caffine[i] = drink + (-.078 * 1000000 / BV) * t[i];
	}
	double low = 0.0;

	low = coefficient * drink * .5/BV;
	int* coffee = malloc(duration * sizeof(int));
	int i = 0;
	while (i < duration)
	{
		if (Caffine[i] < low)
		{
			printf("Take a serving of %dmg coffee after this many hours: %d\n", drink, i);
			coffee[i] = i;
			for (int j = 0; j < duration; j++)
			{
				Caffine[i] = Caffine[i] + Caffine[j - 1];
				
				if (coffee[i] > low)
				{
					printf("We recommend you drink something less caffinated like soda or tea! If that doesn't sound appealing, its a great idea to get some exercise!");
				}
			}

		}
		else
		{
			Caffine[i] = Caffine[i];
		}
		i++;
		
	}
	return coffee;
}

int main(void)
{
	int duration = 0, gender = 0, bodyweight = 0, drink = 0;
	int hours[10] = { 0 };
	printf("How many hours do you need to stay productive for? (Enter an integer from 1-10): \n");
	scanf("%d", &duration);

	printf("If you are a male, enter 1 If you are a female, enter 2 : \n");
	scanf("%d", &gender);

	printf("Enter your body weight(kg): \n");
	scanf("%d", &bodyweight);


	printf("Enter how much caffeine is in 1 serving of coffee (mg): \n");
	scanf("%d", &drink);
	int thresh = 0;
	printf("Please select the appropriate option for caffeine consumption\n1. Need a small energy boost\n2. Need to wake up and feel active\n3. Need to reanimate my fatigued body and work hard\n");
	scanf("%d", &thresh);

	int* coffee = calculate_coffee(duration, gender, bodyweight, drink, thresh);
	
	
	
	free(coffee); 

	return 0;
}
