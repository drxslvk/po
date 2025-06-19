#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BYTES 44

int main() {
	int fd, result;
	size_t size;
	char resstring[BYTES];
	char name[]="file.fifo";

	if((fd = open(name, O_RDONLY)) < 0) {
			printf("Не удавлось открыть FIFO на чтение\n");
			exit (-1);
		}
	if (size < 0) {
			printf("Не удалось прочитать строки из FIFO\n");
			exit(-1);
		}
		printf("Содержимое прочитанной строки %s\n", resstring);
	if(close(fd) < 0) {
			printf("Не удалось закрыть FIFO\n");
			exit(-1);
		}
		printf("Процесс-приемник завершил работу\n");
	return 0;
}
