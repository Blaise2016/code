#include "matrix.h"
#include "mex.h"
#include "math.h"

double f(double x) {
	if (x==0) return 1; // lim sin(x)/x = 1
	return sin(x)/x;
}

double min(double a, double b) {
	return a>b?b:a;
}

void mexFunction(int ansNum, mxArray *ans[], int argNum, const mxArray *args[]) {
	double a, b;
	double dx;
	double l, r, m;
	double sum;

	a = *mxGetPr(args[0]);  // left end
	b = *mxGetPr(args[1]);  // right end
	dx  = pow(2, -8);		// interval length

	ans[0] = mxCreateDoubleMatrix(1, 1, mxREAL);

	l = a; 
	sum = 0;
	while (l < b) {
		r = min(l+dx, b);
		m = (l+r)/2;
		sum += (r-l) * (f(l)+4*f(m)+f(r)) /6;
		l  = r;
		r += dx;
	}

	*mxGetPr(ans[0]) = sum;
}