#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
	char str[100];
	int first;
	int second;
	int result;
	printf("Введите первое число\n");
	scanf("%d", &first);
	printf("Введите второе число\n");
	scanf("%d", &second);
	printf("Выберите действие:\n  1. Сложение. 3. Умножение. \n  2. Вычитание. 4. Деление.\n");
	scanf("%s", str);
	if (strcmp(str, "1") == 0) {
		result = first + second;
		printf("Результат: %d\n", result);
	}
	if (strcmp(str, "2") == 0) {
		result = first - second;
		printf("Результат: %d\n", result);
	}
	if (strcmp(str, "3") == 0) {
		result = first * second;
		printf("Результат: %d\n", result);
	}
	if (strcmp(str, "4") == 0) {
		if (second != 0) {
			result = first / second;
			printf("Результат: %d\n", result);
		} 
		else {
			printf("На ноль делить нельзя!\n");
		}
	}
	return 0;
}

