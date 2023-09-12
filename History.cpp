#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
#include "History.h"
#include <iostream>
using namespace std;

void clearScreen();

History::History(int nRows, int nCols) {
	m_rows = nRows;
	m_cols = nCols;

	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m_arena[i][j] = '.';
}

bool History::record(int r, int c) {
	if (r > m_rows || r < 1 || c > m_cols || c < 1)
		return false;

	if (m_arena[r - 1][c - 1] == '.')
		m_arena[r - 1][c - 1] = 'A';
	else if (m_arena[r - 1][c - 1] == 'Z' || m_arena[r - 1][c - 1] == 'Y')
		m_arena[r - 1][c - 1] = 'Z';
	else
		m_arena[r - 1][c - 1]++;

	return true;
}

void History::display() const {
	clearScreen();
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_cols; j++) {
			cout << m_arena[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}