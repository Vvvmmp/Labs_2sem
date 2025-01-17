#include "stdafx.h"
#include "Error.h"
#include "Parm.h"

namespace Parm {
	PARm getparm(int argc, _TCHAR* argv[]) { // ��������� ����������
		PARm parm;
		bool in = 0, out = 0, log = 0; 
		for (int i = 1; i < argc; i++) {
			if (wcslen(argv[i]) > PARM_MAX_SIZE) { // ���� �������� ���������� ������ ���������
				throw ERROR_THROW(104); // �������� ����������
			}
			if (wcsstr(argv[i], PARM_IN)) { // ���� ����� in
				wcscpy_s(parm.in, argv[i] + wcslen(PARM_IN)); // �� ���������� ��� � ���� ���������
				in = 1; // ��������, ��� �� ����
			}
			if (wcsstr(argv[i], PARM_OUT)) { // ���� ����� out 
				wcscpy_s(parm.out, argv[i] + wcslen(PARM_OUT));// �� ���������� ��� � ���� ���������
				out = 1; // ��������, ��� �� ����
			}
			if (wcsstr(argv[i], PARM_LOG)) { // ���� ����� log 
				wcscpy_s(parm.log, argv[i] + wcslen(PARM_LOG));// �� ���������� ��� � ���� ���������
				log = 1; // ��������, ��� �� ����
			}
		}
		if (!in) { // ���� �������� in �� ����� �� �������� ����������
			throw ERROR_THROW(100);
		}
		if (!out) { // ���� out �� �����, �� ��������� ��� �� �������� in
			wcscpy_s(parm.out, parm.in);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}
		if (!log) {// ���� log �� �����, �� ��������� ��� �� �������� in
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}
		return parm;
	}
}