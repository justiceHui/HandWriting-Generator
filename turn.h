#include <math.h>
#include <string.h>
#include <stdio.h>

typedef struct pos{
	int i, j;
}pos;

int print[28][28] = {0};

double deg2rad(double angle){
	return angle/180.0*3.14;
}

pos turn(pos a, double angle){
	pos ret;
	angle = deg2rad(angle);
	double i = (double)a.i * cos(angle) - (double)a.j * sin(angle);
	double j = (double)a.i * sin(angle) + (double)a.j * cos(angle);
	ret.i = (int)i;
	ret.j = (int)j;
	return ret;
}
