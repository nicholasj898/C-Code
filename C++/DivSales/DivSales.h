#pragma once
class DivSales
{
private:
	// array of elements representing four quarter
	double quarter_sales[4];

public:
	DivSales();
	~DivSales();

	// method to take in all the quarter sales at one time and store in array
	void setQuarters_Sales(double quarter1, double quarter2, double quarter3, double quarter4)
	{
		quarter_sales[0] = quarter1;
		quarter_sales[1] = quarter2;
		quarter_sales[2] = quarter3;
		quarter_sales[3] = quarter4;
		return;
	}

	double getQuarter_sales(int quarter)
	{
		return quarter_sales[quarter];
	}

};

