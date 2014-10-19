#include <cmath>

namespace hftmath {
	class hftmath
	{
	public:
		int power(int base, unsigned exp);
		double power(double base, unsigned exp);
		int log(int n);
		int factorial(int n);
		int findinarray(int n, int* a, int k);
		int binary(int n);
		int pascaltriangle(int n);
		double expTaylor(double arg);
		double sin_taylor(double x, int maxN, double tolerance);
		double cos_taylor(double x, int maxN, double tolerance);
		double sum_taylor(int maxN, double tolerance);
	};

}
