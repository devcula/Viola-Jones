%module features
%{
#define SWIG_FILE_WITH_INIT
#include "features.h"
%}
%include "numpy.i"

%init%{
	import_array();
%}

%apply(double* IN_ARRAY2,int DIM1,int DIM2){(double *arr,int p,int q)}
%include "features.h"

