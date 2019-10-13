#include <iostream>
using namespace std;

float InvSqrt(float x) {
	
	float xhalf = 0.5f * x;
	int i = *(int*)&x;            // store floating-point bits in integer
	//burada 0x5f3759df hexadecimal sayýsýný 1 bit yana kaydýrarak ilk tahmini oluþturacak sayýyý hexadecimal formatýnda elde ediyor
	i = 0x5f3759df - (i >> 1);    // initial guess for Newton's method
	//Bu yöntemin büyüsü 0x5f3759df sayýsýnda olduðu kadar C/C++ dilinin bit kaydýrma operatörününde de saklý.
	x = *(float*)&i;              // convert new bits into float
	x = x * (1.5f - xhalf * x * x);     // One round of Newton's method
	return x;
}
float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;    // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);               // what the fuck? 
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));   // 1st iteration
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration,
											  // this can be removed

	return y;
}
int main()
{
	float gercekDeger = 1 / sqrt(2);
	float quakeDeger = InvSqrt(2);
	float quakeDeger2 = Q_rsqrt(2);
	cout << "1/kok(2) nin gercek degeri: " << gercekDeger << endl;
	cout << "1 / kok(2) nin quake yontemiyle hesaplanan degeri: " << quakeDeger << endl;
	cout << "Hata orani: " << abs(gercekDeger - quakeDeger) / gercekDeger << endl;
	cout << "Newton yontemiyle 2 iterasyon sonucu 1 / kok(2):" << quakeDeger2 << endl;
	cout << "Hata orani: " << abs(gercekDeger - quakeDeger2) / gercekDeger << endl;
	return 0;
}