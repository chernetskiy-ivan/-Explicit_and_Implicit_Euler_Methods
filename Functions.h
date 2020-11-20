#pragma once
#include<iostream>
#include<math.h>

double* Function(double* vector_F, double* vector_U);

double findStep(double* vector_F);

double* makeStep(double* vector_F, double* vector_U, double t);