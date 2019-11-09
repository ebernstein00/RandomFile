#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int randNumGen(){
	int fd = open("/dev/random", O_RDONLY);
	int buf[1];
	read(fd, buf, sizeof(int));
	return buf[0];
	close(fd);
}

int main(){
	//Create int array...
	int arr[10];
	int i;
	for(i = 0; i < 10; i++){
		arr[i] = randNumGen();
	}

	//Print array values...
	for(i = 0; i < 10; i++){
		printf("Index %d:\t%d\n", i, arr[i]);
	}

	//Write to another file...
	int wrtr = open("file.txt", O_WRONLY | O_CREAT);
	write(wrtr, arr, sizeof(int));
	printf("Data written to file...");
	close(wrtr);

	//Reading into new array...
	int veri[10];
	int rdr = open("file.txt", O_RDONLY);
	read(rdr, veri, sizeof(int));
	close(rdr);

	//Print new array...
	printf("Verification:\n");
	for(i = 0; i < 10; i++){
		printf("Index %d:\t%d\n", i, veri[i]);
	}
}