#include <iostream>
using namespace std;

void simp(int x, int &num, int &den, int Nn, int Nd)
{
	if(num < 0) {num *= -1; Nn = 1;}
	if(den < 0) {den *= -1; Nd = 1;}

	if(num == 0) {
		den = 1;
	} else if(x <= num and x <= den) {
		if(num%x == 0 and den%x == 0) {
			num /= x; den /= x;
			simp(x, num, den, Nn, Nd);
		}
		else simp(x+1, num, den, Nn, Nd);
	}

	if(Nn == 1) num *= -1;
	if(Nd == 1) den *= -1;
}

int main()
{
	int x, y;
	cin >> x >> y;
	simp(2,x,y,0,0);
	cout << x << '/' << y << endl;
}