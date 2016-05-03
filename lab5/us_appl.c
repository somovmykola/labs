#include <stdio.h>
#include <stdlib.h>
#include <rtai.h>
#include <rtai_fifos.h>

/* we specify an array of fifos for use later */
char* fifo_device="/dev/rtf0";

int main(int argc,char* argv[]) {
 
	/* read the position in given as an argument to the program */
	int position=(argc==2)? atoi(argv[1]) : 0;

	/* preset the fifo number to 0 */
	//int fifo_number;
	int count;
 
	/* open the fifo */
	//int fd = open(fifo_device[fifo_number],O_WRONLY);
	int fd = open(fifo_device,O_WRONLY);

	/* simple error check */
	if (fd < 0 ) {
		printf("Error opening the fifo\n");
		exit(1);
	}

	/* write the data */
	count = write(fd,&position,sizeof(int));
	printf("Wrote %d bytes to the fifo\n",count);
 
	/* close the fifo */
	close(fd);

	return 0;
}
