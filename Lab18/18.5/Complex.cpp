#include "Complex.h"
using namespace std;
Complex::Complex()
{
}
Complex::~Complex()
{
}
Complex::Complex(Pair fir, Pair sec)
{
	SetReal(fir, sec);
	SetImag(fir, sec);
}
int Complex::getReal()
{
	return real;
}
int Complex::getImag()
{
	return imaginary;
}
void Complex::SetReal(Pair a, Pair b)
{
	real = a.GetF() * b.GetF() - a.GetS() * b.GetS();
}
void Complex::SetImag(Pair a, Pair b)
{
	imaginary = a.GetF() * b.GetS() + a.GetS() * b.GetF();
}
void Complex::Show()
{
	cout << "(" << real << ", " << imaginary << "i)" << endl;
}
