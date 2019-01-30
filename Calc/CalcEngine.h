#pragma once

class CCalcEngine {
private:
	HWND m_calcWindow;

	bool m_fillingFirstValue;
	bool m_fillingFloat;
	int m_floatCounter;
	bool m_resultReady;
	bool m_firstDigit;
	bool m_fillNegative;

	char m_operation;

	double m_firstValue;
	double m_secondValue;
	double m_calcResult;

	WCHAR m_textOut[256];

	void OperationSelected();
	void CalcResult();

public:
	CCalcEngine(HWND calcWindow);

	void Reset();
	void Test();

	void InsertDigit(BYTE digit);
	void InsertOperation(char operation);

	WCHAR *TextOut();
};

