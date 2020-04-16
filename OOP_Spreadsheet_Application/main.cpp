#include "rowArr.h"
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	RowArr ra;
	cout << "Enter file path: ";
	char filePath[256];
	cin >> filePath;

	int row;
	int col;

	int choice;
	while (true)
	{
		cout << endl;
		cout << " 1.Load\n 2.Save\n 3.Sort ascending\n 4.Sort descending\n 5.Print\n 6.Edit\n 7.Add ROW\n 8.Add COL\n 9. quit\n";
		cout << "choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			if (ra.load(filePath) == false) return 1; break;
		case 2:
			ra.save(filePath); break;
		case 3:
			cout << "Enter col: ";
			cin >> col;
			ra.sortAscending(col); break;
		case 4:
			cout << "Enter col: ";
			cin >> col;
			ra.sortDescending(col); break;
		case 5:
			ra.print(); break;
		case 6:
			cout << "Enter ROW and COL: ";
			cin >> row >> col;
			ra.edit(row, col); break;
		case 7: ++ra; break;
		case 8: ra++; break;
		case 9: return 1;
		default:cout << "Wrong command!\n"; break;
		}
	}

	return 0;
}