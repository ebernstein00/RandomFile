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
	//Create int array...
	int arr[10];
	int i;
	for(i = 0; i < 10; i++){
		arr[i] = randNumGen();
	}
	
	//Print array values...
	printf("Original data read...\n")
	for(i = 0; i < 10; i++){
		printf("Index %d:\t%d\n", i, arr[i]);
	}

	//Write to another file...
	int wrtr = open("file.txt", O_RDWR | O_CREAT, 0644);
	if (wrtr == -1) printf("Error #%d: %s", errno, strerror(errno));
	write(wrtr, arr, sizeof(int) * 10);
	printf("\nData written to file...\n");

	//Reading into new array...
	int veri[10];
	int rdr = open("file.txt", O_RDONLY);
	read(rdr, veri, sizeof(int) * 10);
	if (rdr == -1) printf("Error #%d: %s", errno, strerror(errno));
	close(rdr);

	//Print new array...
	printf("\nVerification...\n");
	for(i = 0; i < 10; i++){
		printf("Index %d:\t%d\n", i, veri[i]);
	}

	//Checking arrays...
	printf("\nPrinting final check...");
	for(i = 0; i < 10; i++){
		if(arr[i] == veri[i]){
			printf("Index %d equal?\tTRUE\n", i);
		}
		else{
			printf("Index %d equal?\tFALSE\n", i);
		}
	}

	printf("\nTesting concluded...\n");
}