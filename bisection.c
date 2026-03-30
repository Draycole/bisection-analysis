#include <stdio.h>

float evaluate_function (float ex)
{
	float result;
	result = ((ex*ex) - 4); //function being evaluated here is f(x) = x^2 - 4. approximations for any otherpolynomial will be replaces here.
	return result;
}

void main ()
{
	float r_1, r_2; //user enter the two initial guesses; the closer their values are to zero the better
	printf("enter first root estimate: ");
	scanf("%f", &r_1);
	printf("enter second root estimiate: ");
	scanf("%f", &r_2);

		float sol_1 = evaluate_function(r_1); //get the y values of the two initial guesses
		float sol_2 = evaluate_function(r_2);

		if ((sol_1 < 0 && sol_2 > 0) || (sol_1 > 0 && sol_2 < 0)) //need to make sure values of roots selected are on opposite sides of zero for the method to be effective.
		{
			printf("variable selected meet criteria ✅ \n");
		}
		else
			printf("variable selected don't meet criteria ❎ \n");


	for (int i = 0; i < 100; i++) //number of desired iterations would be determined here, at i.
	{

		float r_3 = ((r_1 + r_2)/2); //find the bisect
		float sol_3 = evaluate_function(r_3); //find f(bisect)

		printf("roots        yvalue\n%f   %f\n%f   %f\n%f   %f\n", r_1, sol_1, r_2, sol_2, r_3, sol_3); //print the two guesses, the bisect, and the values of the function at those bisects

		printf("-------------------------\n");

		//if-else blocks to compare f(bisect) and determine which of the former roots it is going to replace
		if (sol_1 > 0 && sol_3 > 0 && sol_3 < sol_1)
		{
			printf("sol_3; %f, is closer to zero than sol_1; %f.\ntherefore x_1 is now x_3\n", sol_3, sol_1);
			r_1 = r_3;
			sol_1 = sol_3;
			printf("new boundaries are (%f, %f)\n", r_2, r_1);
			printf("function boundaries are (%f, %f)\n", sol_2, sol_1);
		}
		else if (sol_2 > 0 && sol_3 > 0 && sol_3 < sol_2)
		{
			printf("sol_3; %f, is closer to zero than sol_2; %f.\n therefore x_2 is now x_3\n", sol_3, sol_2);
			r_2 = r_3;
			sol_2 = sol_3;
			printf("new boundaries are (%f, %f)\n", r_1, r_2);
			printf("function boundaries are (%f, %f)\n", sol_1, sol_2);
		}
		else if (sol_1 < 0 && sol_3 < 0 && sol_3 > sol_1)
		{
			printf("sol_3; %f, is closer to zero than sol_1; %f.\n therefore x_1 is now x_3\n", sol_3, sol_1);
			r_1 = r_3;
			sol_1 = sol_3;
			printf("new boundaries are (%f, %f)\n", r_1, r_2);
			printf("function boundaries are (%f, %f)\n", sol_1, sol_2);
		}
		else if (sol_2 < 0 && sol_3 < 0 && sol_3 > sol_2)
		{
			printf("sol_3; %f, is closer to zero than sol_2; %f.\n therefore x_2 is now x_3\n", sol_3, sol_2);
			r_2 = r_3;
			sol_2 = sol_3;
			printf("new boundaries are (%f, %f)\n", r_2, r_1);
			printf("function boundaries are (%f, %f)\n", sol_2, sol_1);
		}
		else
		{
			printf("sol_3; %f, is a root of f(x)\n", sol_3);
		}
		printf("\n----end of iteration-----\n");
	}
}