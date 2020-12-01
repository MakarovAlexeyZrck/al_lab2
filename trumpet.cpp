#include "trumpet.h"


int trumpet::MAX_ID = 0;

trumpet::trumpet()
{
	id = ++MAX_ID;
}

std::ostream& operator << (std::ostream& out, const trumpet& t)
{
	out << "�����: " << t.length;
	out << "�������: " << t.diam;
	out << (t.repaired ? "� ������� !" : "�� � �������!");
	return out;
}
std::istream& operator >> (std::istream& in, trumpet& trumpet)
{
	trumpet.length = is_float("������� ����� �����:   ");
	trumpet.diam = is_float("������� ������� �����:   ");
	return in;
}