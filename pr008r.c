//Программа записи информации из процесса в фаил
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	size_t size;
	char string[20];
	if((fd = open("myfile", O_RDONLY))<0) {
		printf("Ошибка при открытии файла на чтение");
		exit(-1);
	}
	size = read(fd,string,20);
	if(size != 20) {
		printf("Не удалос прочитатьь всю строку");
		exit(-1);
	}
	else
		printf("Строка прочитанаана из  фаила \"myfile\"\n");
	printf("Строка: %s\n", string);
	printf("В файл с дескриптором %d записано %ld байт\n", fd, size);
	if (close(fd)<0) {
		printf("Не удается закрыть фаил с дескриптором %d\n", fd);
		exit(-1);
	}
	return 0;
}
