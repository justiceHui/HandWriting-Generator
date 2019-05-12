#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mnist_data{
	double **data;
	unsigned int label;
}mnist_data;

unsigned int mnist_bin2dec(char *v){
	int i; unsigned int ret = 0;
	for(i=0; i<4; i++){
		ret <<= 8;
		ret |= (unsigned char)v[i];
	}
	return ret;
}

int mnist_load(
	char *imagePath,
	char *labelPath,
	unsigned int *count,
	int arr[10][28][28]
){
	printf("[[STSTEM]] file openning start!\n");
	int i; char tmp[4];
	unsigned int imageCnt, labelCnt, imageDim[2];
	FILE *ifp = fopen(imagePath, "rb"), *lfp = fopen(labelPath, "rb");
	printf("[[SYSTEM]] 20%%...\n");
	
	if(!ifp || !lfp){
		return -1;
	}
	
	fread(tmp, 1, 4, ifp);
	if(mnist_bin2dec(tmp) != 2051){
		return -2;
	}
	
	fread(tmp, 1, 4, lfp);
	if(mnist_bin2dec(tmp) != 2049){
		return -3;
	}
	
	printf("[[SYSTEM]] 40%%...\n");
	fread(tmp, 1, 4, ifp);
	imageCnt = mnist_bin2dec(tmp);
	
	fread(tmp, 1, 4, lfp);
	labelCnt = mnist_bin2dec(tmp);
	
	printf("[[SYSTEM]] 60%%...\n");
	if(imageCnt != labelCnt){
		return -4;
	}
	
	printf("[[SYSTEM]] 80%%...\n");
	for(i=0; i<2; i++){
		fread(tmp, 1, 4, ifp);
		imageDim[i] = mnist_bin2dec(tmp);
	}
	if(imageDim[0]!=28 || imageDim[1]!=28){
		return -2;
	}
	printf("[[SYSTEM]] file openning finish\n");
	
	*count = imageCnt;
	for(i=0; i<imageCnt; i++){
		int j;
		unsigned char readData[28*28];
		fread(readData, 1, 28*28, ifp);
		fread(tmp, 1, 1, lfp);
		for(j=0; j<28*28; j++){
			arr[tmp[0]][j/28][j%28] += (int)readData[j];
		}
	}
	return 0;
}
