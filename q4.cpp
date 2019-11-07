#include<bits/stdc++.h>
using namespace std;
class Complex
{
	private:
		int re;
		int im;
	public:
		Complex(int r=0, int i=0){
			re=r;
			im=i;
		}
		void set(int re1,int im1)
		{
			re=re1;
			im=im1;
		}
		friend class count;
		friend class counter;
};
class count
{
	protected:
		Complex c1;
	public:
		count():c1(1,1)
		{
			
			cout << "before postfix increment: " << c1.re << "+" << c1.im << "i" <<endl;
			(*this)++;
			cout << "After postfix increment: " << c1.re << "+" << c1.im << "i" <<endl;
		}
		count(int r,int i):c1(r,i)
		{
			//c1.set(re1,1);
			cout << "before postfix increment: " << c1.re << "+" << c1.im << "i" <<endl;
			(*this)++;
			cout << "After postfix increment: " << c1.re << "+" << c1.im << "i" <<endl;
		}
		Complex operator ++(int)		//postfix overload
		{
			this->c1.re++;
			this->c1.im++;
			return this->c1;
		}
};
class counter : public count
{
	public:
		counter():count()
		{
			cout << "before postfix decrement: " << c1.re << "+" << c1.im << "i" <<endl;
			(*this)--;
			cout << "After postfix decrement: " << c1.re << "+" << c1.im << "i" <<endl;
		}
		counter(int re,int i):count(re,i)
		{
			cout << "before postfix decrement: " << c1.re << "+" << c1.im << "i" <<endl;
			(*this)--;
			cout << "After postfix decrement: " << c1.re << "+" << c1.im << "i" <<endl;
		}
		Complex operator --(int)	//postfic decrement
		{
			this->c1.re--;
			this->c1.im--;
			return this->c1;
		}
		void print()
		{
			cout << "number is " << c1.re << "+" << c1.im << "i\n";
		}
};
int main()
{
	cout << "number was " << "1+1i\n";
	counter c1;
	int re,img;
	cout<<"enter real and imaginary part"<<endl;
	cin>>re>>img;
	cout << "number was "<<re<<"+"<<img << "i\n";
	counter c(re,img);
}
