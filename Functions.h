#pragma once
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void Function(double* vector_F, double* vector_U);

double findStep(double* vector_F);

void makeStep(double* vector_F, double* vector_U, double t);

void find_tk(double* tk, double tau);

void explicit_Euler_method(double* vector_U, double tk, double T, double eps, double tmax);


//для неявного метода

void Function_2(double vector_F, double* vector_U);