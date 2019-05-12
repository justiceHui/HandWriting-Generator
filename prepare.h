#include "loader.h"

mnist_data *train_data;
unsigned int train_count;
int train_ret;
int sum[10][28][28];
int maxIdx[10];

void init(){
	int i, j, k;
	train_ret = mnist_load("./data/train-images.idx3-ubyte", "./data/train-labels.idx1-ubyte", &train_count, sum);
	if(train_ret){
		printf("[[error code]] %d\n", train_ret);
		exit(1);
	}
	printf("[[image count]] %d\n", train_count);
	for(i=0; i<10; i++){
		for(j=0; j<28; j++){
			for(k=0; k<28; k++){
				maxIdx[i] = maxIdx[i]>sum[i][j][k]?maxIdx[i]:sum[i][j][k];
			}
		}
	}
}
