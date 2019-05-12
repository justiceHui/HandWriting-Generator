#include "prepare.h"
#include <time.h>
#include <math.h>
#include "turn.h"

void drawOriginal(int n){
	int i, j, k;
	double maxi = (double)maxIdx[n];
	double now, per;
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			now = (double)sum[n][i][j];
			per = (double)now/maxi*100.0;
			if(per >= 50) printf("@ ");
			else if(per >= 45) printf("* "); 
			else printf("  ");
		}
		printf("\n");
	}
}

void drawE(int n){
	int i, j, k;
	double rnd;
	double maxi = (double)maxIdx[n];
	double now, per;
	double bound;
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			now = (double)sum[n][i][j];
			rnd = (double)(rand()%10+1);
			per = (double)now/maxi*100.0;
			
			if(per >= 70) bound = 9;
			else if(per>50) bound = 8;
			else if(per >= 45) bound = 4;
			else if(per >= 40) bound = 3;
			else bound = 0.1;
			
			if(rnd <= bound) printf("@ ");
			else if(rnd/2 <= bound) printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}

void rotDraw(int n, double angle){
	int i, j, k;
	double rnd;
	double maxi = (double)maxIdx[n];
	double now, per;
	double bound;
	int print[28][28] = {0};
	int tmp[28][28] = {0};
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			now = (double)sum[n][i][j];
			rnd = (double)(rand()%10+1);
			per = (double)now/maxi*100.0;
			
			if(per >= 70) bound = 9;
			else if(per>50) bound = 8;
			else if(per >= 45) bound = 4;
			else if(per >= 40) bound = 3;
			else bound = 0.1;
			
			if(rnd <= bound) print[i][j] = 1; //printf("@ ");
			else if(rnd/2 <= bound) print[i][j] = 2;
			else print[i][j] = 0; //printf("  ");
		}
		
		//printf("\n");
	}
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			pos ret, p;
			p.i = i-14; p.j = j-14;
			ret = turn(p, angle);
			ret.i += 14;
			ret.j += 14;
			if(0<=ret.i && ret.i<28 && 0<=ret.j && ret.j<28){
				tmp[ret.i][ret.j] = print[i][j];
			}
		}
	}
	for(i=0; i<28; i++){
		for(j=0; j<28; j++){
			if(tmp[i][j] == 1) printf("@ ");
			else if(tmp[i][j] == 2) printf("*");
			else printf("  ");
		}
		printf("\n");
	}
}

int main(){
	int i, j, k;
	int input;
	srand(time(NULL));
	init();
	
	/*printf("\n\nEnter the desired number : ");
	scanf("%d", &input);
	drawE(input);
	printf("==================================================\n");
	rotDraw(input, 20);*/
	
	for(i=0; i<10; i++){
		int rnd;
		for(j=0; j<3; j++){
			rnd = rand()%21-10;
			rotDraw(i, rnd);
			printf("\n\n");
		}
		printf("==================================================\n");
	}
}
