//Двунаправленная связь через пайп между родительским и дочерним процессом
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#define BYTES1 86
#define BYTES2 92
int main () {
	int fd1[2], fd2[2], result;
	size_t size;
	char resstring1[BYTES1], resstring2[BYTES2];
	if((pipe(fd1) < 0)||(pipe(fd2)<0)) {
		printf("Не удалось создать пайп\n");
		exit(-1);
	}
	result = fork();
	if(result < 0) {
		printf("Ошибка при выполнении fork()\n");
		exit(-1);
	}
	else if (result > 0) {
		if(close(fd1[0])||(close(fd2[1]) < 0)) {
			printf("Не удалось закрыть входной поток процесса-родителя\n");
			exit(-1);
		}
		size = write(fd1[1], "Информация для дочернего процесса от родителя", BYTES1);
		if(size !=BYTES1) {
			printf("Родителю не удалос записать всю строку в пайп\n");
			exit(-1);
		}
		if(close(fd1[1]) < 0) {
			printf("Родителю не удалось закрыть выходной поток\n");
			exit(-1);
		} 
		printf("Читаем строку, отправленную процессом-ребенком...\n");
		size = read(fd2[0], resstring2, BYTES2);
		if(size < 0) {
			printf("Процессу-родителю не удалос прочитать строку\n");
			exit(-1);
		}
		printf("Прочитанная родителем строка %s\n", resstring2);
		if(close(fd2[0]) < 0) {
			printf("Не удалось закрыть входной поток процесса-родителя\n");
			exit(-1);
		}
		printf("Процесс-родитель завершил работу\n");
	}
	else {
		if((close(fd1[1]),0)||(close(fd2[0])<0)) {
			printf("Не удалось закрыть выходной или входной поток процесса-ребенка\n");
			exit(-1);
		}
		size = read(fd1[0], resstring1, BYTES1);
		if(size < 0) {
			printf("Процессу-ребенку не удалось прочитать строку\n");
			exit(-1);
		}
		printf("Строка, прочитанная дочерним процессом: %s\n", resstring1);
		if(close(fd1[0])<0) {
			printf("Не удалось закрыть входной поток процесса-ребенка\n");
			exit(-1);
		}
		size = write(fd2[1], "Информация для родительского процесса от ребенка", BYTES2);
		if(size !=BYTES2) {
			printf("Ребенку не удалось записать всю строку в пайп\n");
			exit(-1);
		}
		printf("Процесс-ребенок завершил работу\n");
	}
	return 0;
}
