#include "math.h"

namespace hftmath {

	int hftmath::power(int base, unsigned exp)
	{
		return exp ? base * power(base, exp-1) : 1;
	}

	double hftmath::power(double base, unsigned exp)
	{
		return exp ? base * power(base, exp-1) : 1;
	}

	int hftmath::log(int n)
	{
		return n>1 ? log(n/2) : 0;
	}

	int hftmath::factorial(int n)
	{
		return n ? n *  factorial(n-1) : 1;
	}

	int hftmath::findinarray(int n, int* a, int k)
	{
		return n > 1 ?
							k < a[n/2] ?
								findinarray(n/2,a,k)
							:
								findinarray((n+1)/2, a+n/2, k)
						:
							k == a[0];
	}

	/*
		binary representation
		*/

	int hftmath::binary(int n)
	{
		return n > 1 ? 10*binary(n/2)+n%2 : n%2;
	}

	int hftmath::pascaltriangle(int n)
	{
		int triangle[n][n];
		for(int i=0;i<n;i++) {
			triangle[i][0] = triangle[0][i]=1;
		}
		for(int i=1;i<n-1;i++) {
			for (int j=1;i<n-1-i;j++) {
				triangle[i][j] = triangle [i-1][j] + triangle[i][j-1];
			}
		}
		return 0;
	}

	double hftmath::sin_taylor(double x, int maxN, double tolerance)
	{
	    if(maxN==1)
	    {
	        return x;
	    }

	    double result = 0;
	    for (int j =1; j<=maxN;j++)
	    {
	        if(j%2 == 1) //for differentiating subtracting or adding series
	        {
	            result += pow(x, j*2-1) / factorial(j*2-1);
	            if (fabs((pow(x, j*2-1) / factorial(j*2-1))/result)<=tolerance)
	            {
	                break;
	            }
	        }
	        else
	        {
	            result -= pow(x, j*2-1)/ factorial(j*2-1);
	            if (fabs((pow(x, j*2-1) / factorial(j*2-1))/result)<=tolerance)
	            {
	                break;
	            }
	        }
	    }
	    return (result);
	}

	double hftmath::cos_taylor(double x, int maxN, double tolerance)
	{
	    if(maxN==1)
	    {
	        return 1;
	    }

	    double result = 0;
	    for (int j =1; j<=maxN;j++)
	    {
	        if(j%2 == 1) //for differentiating subtracting or adding series
	        {
	            result += pow(x, j*2-2) / factorial(j*2-2);
	            if (fabs((pow(x, j*2-2) / factorial(j*2-2))/result)<=tolerance)
	            {
	                break;
	            }
	        }
	        else
	        {
	            result -= pow(x, j*2-2)/ factorial(j*2-2);
	            if (fabs((pow(x, j*2-2) / factorial(j*2-2))/result)<=tolerance)
	            {
	                break;
	            }
	        }
	    }
	    return (result);
	}

	double hftmath::sum_taylor(int maxN, double tolerance)
	{
	    double result=1;
	    for (int j =1; j<=maxN;j++)
	    {
	        result += pow((1/j),j);
	        if (fabs(pow((1/j),j)/result)<=tolerance)
	        {
	            break;
	        }
	    }

	    return (result);
	}

}
