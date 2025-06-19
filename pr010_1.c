#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BYTES 44

int main () {
	int fd, result;
	size_t size;
	char resstring[BYTES];
	char name[]="file.fifo";

		printf("Процесс-отправитель начинает запись в FIFO\n");
		if((fd = open(name, O_WRONLY))<0) {
			printf("Не удалось открыть FIFO на запись\n");
			exit(-1);
		}
		size = write(fd, "Текстовая строка для FIFO", BYTES);
		if(size != BYTES) {
			printf("Не удалось записать всю строку в FIFO\n");
			exit(-1);
		}
		if(close(fd)<0){
			printf("Не удалось закрыть FIFO\n");
			exit(-1);
		}
		printf("Процесс-отправитель записал строку в FIFO и завершил работу\n");

		return 0;
}
