#include<bits/stdc++.h>
using namespace std;

class Complex{
	private :
		double re;
		double img;
	public :
		Complex(double r=0, double im=0){
			re=r;
			img=im;
		}
		Complex(const Complex &c){
			re=c.re;
			img=c.img;
		}
		void setComplex(double r, double im){
			re=r;
			img=im;
		}
		void display(){
			if(img<0){
				cout<<re<<img<<"i"<<endl;
			}
			else{
				cout<<re<<"+"<<img<<"i"<<endl;
			}
		}
		Complex operator + (Complex const &a){
			Complex c(a.re+re,a.img+img);
			return c;
		}
		Complex operator - (Complex const &a){
			Complex c(re-a.re,img-a.img);
			return c;
		}
		Complex operator * (Complex const &a){
			Complex c(a.re*re-a.img*img,a.img*re+a.re*img);
			return c;
		}
		Complex operator / (Complex const &a){
			double r,i;
			r=(a.re*re+a.img*img)/(a.re*a.re+a.img*a.img);
			i=(a.re*img-a.img*re)/(a.re*a.re+a.img*a.img);
			Complex c(r,i);
			return c;
		}
		friend istream & operator >> (istream &is, Complex &c);
		friend ostream & operator << (ostream &os, const Complex &c);
		
};
istream & operator >> (istream &is, Complex &c){
	cout<<"Enter real part : ";
	is>>c.re;
	cout<<"Enter imaginary part : ";
	is>>c.img;
}

ostream & operator << (ostream &os, const Complex &c){
	if(c.img<0){
		os<<c.re<<c.img<<"i"<<endl;
	}
	else{
		os<<c.re<<"+"<<c.img<<"i"<<endl;
	}
}

int main(){
	stack<Complex>s;
	stack<char>operation;
	char p;
	Complex c;
	int i=1;
	printf("enter the string or press s to display latest complex no.\n");
	while(i==1){
		cin>>p;
		switch(p){
			case '+':operation.push(p);
					break;
			case '*':operation.push(p);
					break;
			case '/':operation.push(p);
					break;
			case '-': operation.push(p);
					break;
			case '(': cin>>c;
					break;
			case ')':{ s.push(c);
						if(s.size()>=2 && operation.size()>0){
							p=operation.top();
							operation.pop();
							switch(p){
									case '-':{
											Complex c1,c2;
											if(s.size()>1){
												c1=s.top();
												s.pop();
												if(s.size()>0){
													c2=s.top();
													s.pop();
													c=c2-c1;
													s.push(c);
												}
												else{
													cout<<"stack has 1 element"<<endl;
												}
											}
									}break;
									case '+':{
											Complex c1,c2;
											if(s.size()>1){
												c1=s.top();
												s.pop();
												if(s.size()>0){
													c2=s.top();
													s.pop();
													c=c2+c1;
													s.push(c);
												}
												else{
													cout<<"stack has 1 element"<<endl;
												}
											}
									}break;
									case '*':{
											Complex c1,c2;
											if(s.size()>1){
												c1=s.top();
												s.pop();
												if(s.size()>0){
													c2=s.top();
													s.pop();
													c=c2*c1;
													s.push(c);
												}
												else{
													cout<<"stack has 1 element"<<endl;
												}
											}
									}break;
									case '/':{
											Complex c1,c2;
											if(s.size()>1){
												c1=s.top();
												s.pop();
												if(s.size()>0){
													c2=s.top();
													s.pop();
													c=c2/c1;
													s.push(c);
												}
												else{
													cout<<"stack has 1 element"<<endl;
												}
											}
											
									}break;
							}
						}
					}
					break;
			case 's': {
						if(s.size()>0) cout<<s.top();
						else cout<<"Stack is empty"<<endl;

					}break;
			default : cout<<"invalid input"<<endl;
					break;
		}
	}
	return 0;
}