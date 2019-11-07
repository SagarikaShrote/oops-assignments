#include<bits/stdc++.h>
using namespace std;

class Length{
private:
	int feet;
	float inches;
public:
	Length(int f=0, float i=0){
		feet=f;
		inches=i;
	}
	Length(const Length &l){
		feet=l.feet;
		inches=l.inches;
	}
	void setData(int f, float i){
		feet=f;
		inches=i;
	}
	Length operator + (Length const &a){
		int f;
		f=feet+a.feet;
		float i;
		i=inches+a.inches;
		f=f+(int)i/12;
		i=(int)i%12;
		Length d(f,i);
		return d;
	}
	Length operator - (Length const &a){
		int f;
		float i;
		i=inches+feet*12-(a.inches+12*a.feet);
		f=(int)i/12;
		i=(int)i%12;
		Length d(f,i);
		return d;
	}
	Length operator += (Length const &d){
		this->feet+=d.feet;
		this->inches+=d.inches;
		this->feet+=(this->inches)/12;
		this->inches=(int)this->inches%12;
		return *this;
	}
	Length operator -= (Length const &d){
		this->inches=this->inches+this->feet*12-(d.inches+12*d.feet);
		this->feet=(int)this->inches/12;
		this->inches=(int)this->inches%12;
		return *this;
	}
	bool operator == (Length const &d){
		bool ret=false;
		if(this->feet==d.feet && this->inches==d.inches){
			ret=true;
		}
		return ret;
	}
	friend istream & operator >> (istream &is, Length &d);
	friend ostream & operator << (ostream &os, const Length &d);
};

istream & operator >> (istream &is, Length &d){
	cout<<"Enter length "<<endl;
	cout<<"Enter feet :";
	is>>d.feet;
	cout<<"Enter inches : ";
	is>>d.inches;
}

ostream & operator << (ostream &os, const Length &d){
	os<<d.feet<<" feet "<<d.inches<<" inches"<<endl;
}

int main()
{
	/* code */
	Length l1,l2,l3,l4(3,8),l;
	cin>>l1;
	cin>>l2;
	int f;
	float i;
	cout<<"Enter length "<<endl;
	cout<<"Enter feet :";
	cin>>f;
	cout<<"Enter inches : ";
	cin>>i;
	l3.setData(f,i);
	cout<<l1;
	cout<<l2;
	cout<<l3;
	cout<<l4;
	l=l1+l2;
	cout<<"l1+l2 = ";
	cout<<l;
	l=l1-l2;
	cout<<"l1-l2 = ";
	cout<<l;
	cout<<"l3-=l4 : ";
	l3-=l4;
	cout<<l3;
	cout<<"l2+=l4 : ";
	l2+=l4;
	cout<<l3;
	cout<<" l2==l4 :";
	bool b=l2==l4;
	cout<<b<<endl;
	return 0;
}