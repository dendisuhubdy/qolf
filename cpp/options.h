#include <cmath>

namespace options
{
	class options
	{
	private:
		double volatility;
		double strike;
		double maturity;
		double time;
		double interest_rate;
	protected:
	public:
		double europeanoption(double volatility, double strike, double maturity, double time, double interest_rate);
	};
}
