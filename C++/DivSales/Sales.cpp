#include <iostream>
#include <iomanip>
#include "DivSales.h"

using namespace std;

class DivSalesPlus : public DivSales
{
// needed to derive class for single value
private:
	double corp_sales = 0;

public:
	// method to add to sales total
	void plusCorpSales(double sales)
	{
		corp_sales += sales;
	}
	// method to get sales total
	double getCorpSales()
	{
		return corp_sales;
	}
};

int main() {
	const int DivisionCount = 6;
	DivSales divSales[DivisionCount];
	DivSalesPlus corpTotal;
	
	// q_sales is a temporary hold area of one division quarter inputs
	double q_sales[4];
	// outter loop occurs 6 times - one for each division
	for (int divisionNbr = 0; divisionNbr < DivisionCount; divisionNbr++)
	{
		// inner loop occurs 4 times - one for each quarter
		cout << "\nPlease enter quarter sales for Division #" << (divisionNbr + 1) << " of " << DivisionCount << endl;
		for (int quarterNbr = 0; quarterNbr < 4; quarterNbr++)
		{
			cout << " Sales for Quarter #" << (quarterNbr + 1) << " $"; cin >> q_sales[quarterNbr];
			// maintain a running total of all corp sales
			corpTotal.plusCorpSales(q_sales[quarterNbr]);
		}
		divSales[divisionNbr].setQuarters_Sales(q_sales[0], q_sales[1], q_sales[2], q_sales[3]);
	}

	// show the report of quarterly sales
	double divTotal;
	// outter loop for each division
	for (int divisionNbr = 0; divisionNbr < DivisionCount; divisionNbr++)
	{
		divTotal = 0;
		cout << "Sales for Division #" << (divisionNbr + 1);
		// inner loop for each quater
		for (int quarterNbr = 0; quarterNbr < 4; quarterNbr++)
		{
			cout << "  Q" << (quarterNbr + 1) << ": $" << divSales[divisionNbr].getQuarter_sales(quarterNbr);
			// just for kicks, show the division total
			divTotal += divSales[divisionNbr].getQuarter_sales(quarterNbr);
		}
		cout << "  Division Total: $" << divTotal << endl;
	}
	// get the total corp sales
	cout << "The total sales for the entire corporation: $" << corpTotal.getCorpSales() << endl;
	return 0;
}