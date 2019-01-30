#include "stdafx.h"
#include "CalcEngine.h"

CCalcEngine::CCalcEngine(HWND calcWindow) {
	m_calcWindow = calcWindow;

	Reset();
}

void CCalcEngine::Reset() {
	m_firstValue = 0.0;
	m_secondValue = 0.0;
	m_operation = 0;
	m_floatCounter = 0;
	m_calcResult = 0;

	m_fillingFirstValue = true;
	m_fillingFloat = false;
	m_resultReady = false;
	m_firstDigit = true;
	m_fillNegative = false;

	StrCpyW(m_textOut, L"0");
}

void CCalcEngine::Test() {
	WCHAR testMsg[1024];

	swprintf_s(testMsg, L"%f %c %f = %f", m_firstValue, m_operation, m_secondValue, m_calcResult);
	MessageBox(m_calcWindow, testMsg, L"TEST", MB_ICONASTERISK);
}

void CCalcEngine::InsertDigit(BYTE digit) {
	WCHAR digitString[4];

	if (m_resultReady)
		Reset();

	if (m_firstDigit && m_fillingFirstValue && digit == 0)
		return;

	if (m_fillingFirstValue && m_firstDigit)
		ZeroMemory(m_textOut, sizeof(m_textOut));

	if (m_fillingFirstValue) {
		if (!m_firstDigit)
			m_firstValue *= 10.0;

		m_firstValue += static_cast<double>(digit);

		if (m_fillingFloat)
			m_floatCounter++;
	} else {
		if (!m_firstDigit)
			m_secondValue *= 10.0;

		m_secondValue += static_cast<double>(digit);

		if (m_fillingFloat)
			m_floatCounter++;
	}

	m_firstDigit = false;

	_itow_s(digit, digitString, 10);
	StrCatW(m_textOut, digitString);
}

void CCalcEngine::OperationSelected() {
	if (m_resultReady) {
		Reset();
		return;
	}

	if (m_fillingFloat) {
		for (int i = 0; i < m_floatCounter; i++)
			m_firstValue /= 10.0;
	}

	m_firstDigit = true;
	m_fillingFirstValue = false;
	m_fillingFloat = false;
	m_floatCounter = 0;
}

void CCalcEngine::CalcResult() {
	if (m_fillingFloat) {
		for (int i = 0; i < m_floatCounter; i++)
			m_secondValue /= 10.0;
	}

	if (!m_fillingFirstValue && m_firstDigit)
		InsertDigit(0);

	StrCatW(m_textOut, L" = ");

	switch (m_operation) {
		case '+':
		{
			m_calcResult = m_firstValue + m_secondValue;
			break;
		}

		case '-':
		{
			m_calcResult = m_firstValue - m_secondValue;
			break;
		}

		case '*':
		{
			m_calcResult = m_firstValue * m_secondValue;
			break;
		}

		case '/':
		{
			if (m_secondValue == 0.0) {
				StrCatW(m_textOut, L"Ошибка");
				m_resultReady = true;
				return;
			}

			m_calcResult = m_firstValue / m_secondValue;
			break;
		}

		default:
		{
			MessageBox(m_calcWindow, L"Введена неизвестная операция!", L"Ошибка!", MB_ICONERROR);
			Reset();
			return;
		}
	}

	WCHAR calcResultString[32];
	swprintf_s(calcResultString, L"%f", m_calcResult);
	StrCatW(m_textOut, calcResultString);
	m_resultReady = true;
}

void CCalcEngine::InsertOperation(char operation) {
	switch (operation) {
		case ',':
		{
			if (!m_fillingFloat) {
				m_fillingFloat = true;
				m_firstDigit = false;
				StrCatW(m_textOut, L",");
			}
			break;
		}
		
		case '+':
		{
			if (m_fillingFirstValue) {
				m_operation = operation;
				OperationSelected();
				StrCatW(m_textOut, L" + ");
			}
			break;
		}

		case '-':
		{
			if (m_fillingFirstValue) {
				m_operation = operation;
				OperationSelected();
				StrCatW(m_textOut, L" - ");
			}
			break;
		}

		case '*':
		{
			if (m_fillingFirstValue) {
				m_operation = operation;
				OperationSelected();
				StrCatW(m_textOut, L" x ");
			}
			break;
		}

		case '/':
		{
			if (m_fillingFirstValue) {
				m_operation = operation;
				OperationSelected();
				StrCatW(m_textOut, L" / ");
			}
			break;
		}

		case '=':
		{
			if (!m_fillingFirstValue) {
				CalcResult();
			}
			break;
		}

		case 'C':
		{
			Reset();
			break;
		}

		default:
		{
			MessageBox(m_calcWindow, L"Введена неизвестная операция!", L"Ошибка!", MB_ICONERROR);
			break;
		}
	}
}

WCHAR *CCalcEngine::TextOut() {
	return m_textOut;
}