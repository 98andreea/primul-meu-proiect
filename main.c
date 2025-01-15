/*
Se dă un număr natural N. Să se determine dacă acesta se poate descompune în sumă de două pătrate diferite 
de zero.

=> N = a^2 + b^2 si a,b>0 si a diferit de b

PASUL 1: a^2 <= N;
PASUL 2: b^2 = N - a^2;
PASUL 3: ? b^2 = patrat perfect ?

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int N, a=1, b=1, a_patrat=0, b_patrat=0, optiune, solutii_gasite=0;


	while (1)
	{
		printf("~~~~~~~~~~~~MENIU~~~~~~~~~~~~~\n");
		printf("1. Introdu un numar natural N\n");
		printf("0. Iesire\n");
		printf("Alegeti o optiune: ");
		scanf("%d", &optiune);
		printf("\n");

		switch (optiune)
		{
			case 1:
			{
				printf("Introdu un numar natural N: ");
				scanf("%d", &N);
				printf("\n");

				//verificam daca numarul introdus este natural, adica >= 0
				if (N >= 0)
				{
					printf("Numarul introdus este un numar natural\n");
					printf("\n");
				}
				else
				{
					printf("WARRNING! Trebuie sa introduceti un numar natual\n");
					while (N < 0)
					{
						printf("Introduceti va rog un numar natural: ");
						scanf("%d", &N);
						printf("\n");
					}

					printf("Felicitari, acuma ati introdus un numar natural\n");
					printf("\n");

				}
				
				printf("sqrt(N) = %.2f\n", sqrt(N));
				printf("\n");

				//resetare nr solutii
				solutii_gasite = 0;

				//verificare a si b
				for (a = 1; a <= sqrt(N); a++)
				{
					a_patrat = a * a;
					b_patrat = N - a_patrat;
					b = sqrt(b_patrat);

					//verificare daca b^2 este patrat perfect
					if (b == (int)b && b * b == b_patrat && b != a && a != 0 && b != 0 && a < b)
					{
						
						printf("\n");
						printf("REZULTATE: \n");
						printf("a = %d\ta^2 = %d\n", a, a_patrat);
						printf("b = %d\tb^2 = %d - %d = > %d\n", b, N, a_patrat, b_patrat);
						printf("\n");
						printf("%d = %d^2 + %d^2\n", N, a, b);
						printf("%d = %d + %d\n", N, a_patrat, b_patrat);

						solutii_gasite++;
						printf("\n");
					}
				}

				if (solutii_gasite == 0)
				{
					printf("Numarul %d nu poate fi descompuns ca suma de 2 patrate diferite diferite de 0\n", N);
					printf("\n");
					printf("\n");
				}
				else
				{
					printf("CONCLUZII:\n");
					printf("Numarul %d poate fi descompus ca suma de 2 patrate diferite diferite de 0\n", N);
					printf("Numar solutii: %d\n", solutii_gasite);
					printf("\n");
					printf("\n");
				}
				break;
			}
			case 0:
			{
				printf("Programul s-a incheiat\n");
				exit(2);
				break;
			}
		}

	}
	
	return 0;
}