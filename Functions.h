#pragma once
#include<iostream>
#include<math.h>

void Function(double* vector_F, double* vector_U);

double findStep(double* vector_F);

void makeStep(double* vector_F, double* vector_U, double t);

double find_tk(double tk, double t);