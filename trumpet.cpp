#include "trumpet.h"


int trumpet::MAX_ID = 0;

trumpet::trumpet()
{
	id = ++MAX_ID;
}

std::ostream& operator << (std::ostream& out, const trumpet& t)
{
	out << "Длина: " << t.length;
	out << "Диаметр: " << t.diam;
	out << (t.repaired ? "В ремонте !" : "Не в ремонте!");
	return out;
}
std::istream& operator >> (std::istream& in, trumpet& trumpet)
{
	trumpet.length = is_float("Введите длину трубы:   ");
	trumpet.diam = is_float("Введите диаметр трубы:   ");
	return in;
}