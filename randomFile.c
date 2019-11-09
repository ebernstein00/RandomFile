#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int randNumGen(){
	int fd = open("/dev/random", O_RDONLY);
	int buf[1];
	int bytes = read(fd, buf, sizeof(int));
	return buf[0];
	close(fd);
}

int main(){
	//Create int array
	int arr[10];
	int i;
	for(i = 0; i < 10; i++){
		arr[i] = randNumGen();
	}

	//Print array values...
	for(i = 0; i < 10; i++){
		printf("Index %d:\t%d\n", i, arr[i]);
	}
}