#include <stdio.h>
#include <math.h>

float verificar(float num, float lim_inf, float lim_sup){
	while (scanf("%f", &num) != 1 || getchar() != '\n')
        while (getchar() != '\n');
	while ((lim_inf == 0 ? 0 : num < lim_inf) || (lim_sup == 0 ? 0 : num > lim_sup)){
		printf("Ingrese un numero entre %d y %d:\n", (int)lim_inf, (int)lim_sup);
        scanf("%f", &num);
        while (getchar() != '\n');
	}
	return num;
}

void clasify_triangles(){
	int igualdad = 0;
	float triangle[3];

	puts("\nIngrese los lados del triangulo:");
	for(int i = 0; i < 3; i++)
		scanf("%f", &triangle[i]);
	for(int i = 0; i < 2; i++)
		if (triangle[i] == triangle[i + 1])
			igualdad++;

	if (igualdad == 0)
		puts("\nEl triangulo ingresado es un Triangulo Escaleno.");
	else if (igualdad == 1)
		puts("\nEl triangulo ingresado es un Triangulo Isosceles.");
	else
		puts("\nEl triangulo ingresado es un Triangulo Equilatero.");
}

void temperature_calculator(){
	float celsius = 0;
	puts("Ingrese la temperatura en Celsius: ");
	celsius = verificar(celsius, -273.15, 0);
	printf("La temperatura en Fahrenheit es %.1f y en Kelvin es %.1f", (celsius * 1.8) + 32, celsius + 253);
}

void calculator(){
	float value1 = 0, value2 = 0, result;
	int operator = 0;

	puts("Ingrese los numeros");
	scanf("%f", &value1);
	scanf("%f", &value2);
	puts("Cual operacion desea hacer\n1 -- Suma\n2 -- Resta\n3 -- Multiplicacion\n4 -- Division");
	operator = verificar(operator, 1, 4);

	if (operator == 1)
		result = value1 + value2;
	else if (operator == 2)
		result = value1 - value2;
	else if (operator == 3)
		result = value1 * value2;
	else
		if (value2 == 0)
			puts("No se puede dividir entre 0.");
		else
			result = value1 / value2;
	printf("El resultado es %.3f", result);
}

void digit_sum(){
	int num = 0, suma = 0;
	puts("Ingrese el numero para sumar sus digitos");
	num = verificar(num, 0, 0);

	for(int i = 0; num != 0; i++){
		suma += num % 10;
		num /= 10;
	}
	printf("La suma es %d",  suma);
}

void primes(){
	int num = 0;
	num = verificar(num, 0, 0);
	
	for(int i = 2; i <= sqrt(num); i++)
		if (num % i == 0){
			printf("%d no es un numero primo", num);
			return;
		}
	printf("%d es un numero primo", num);
}

void factorial(){
	int num, fact = 1;
	scanf("%d", &num);
	for(int i = 1; i <= num; i++)
		fact *= i;
	printf("El factorial de %d es %d", num, fact);
}

int main(){
	int option = 0;
	while(1) {
		puts("\n\nCual programa quiere usar?\n1 -- Clasificar un Triangulo\n2 -- Calculadora de Temperatura\n3 -- Calculadora Simple\n4 -- Suma de Digitos\n5 -- Numeros Primos\n6 -- Factorial\n7 -- Salir\n");
		option = verificar(option, 1, 7);

		if (option == 1)
			clasify_triangles();
		else if (option == 2)
			temperature_calculator();
		else if (option == 3)
			calculator();
		else if (option == 4)
			digit_sum();
		else if (option == 5)
			primes();
		else if (option == 6)
			factorial();
		else
			break;	
	}
}