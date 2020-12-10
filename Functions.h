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

//����� ������� ��� �������� ������ ������

void ImplicitEulerMethod(double*, double*, double*, int, double, double, double, double, double, bool, bool);

void NewtonMethod(double** matrix_Jacobi, double* vector_dF, double* vector_U, double* vector_X2, int size, int iter, double increment_M, double eps, bool type);

void FillMatrixJacobi_II(double** matrix_Jacobi, double* vector_dF, double* vector_U, int size, double increment_M, bool type);

void GaussMethod(double** matrix_Jacobi, double* vector_U, double* vector_X2, int size);

void QuasiOptimalStrategy(double* Tau, double* Eps, int size, double tau, double& tauP, double eps);

void ThreeZoneStrategy(double* Tau, double* Eps, int size, double tau, double& tauP, double eps);

//��� 4 ������
void Function_Two(double* vector_F, double* vector_U);