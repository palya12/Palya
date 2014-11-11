#include "Array.h"

char* Mult_Over = "Переполнение при умножении вектора!";
char* Sum_Over = "Переполнение при сложении векторов!";
char* Dif_Over = "Переполнение при вычитании векторов!";
char* Div_Exc = "Деление векторов невозможно!";
char* Zero_Exc = "Деление на ноль невозможно!";
char* Ecxeption = "!!!!!!!! Введены неверные данные !!!!!!!!";

Array::Array(int ArrSize)
{
	size = ArrSize;
	ptr = new int[size];
	assert(ptr != 0);

	for (int i=0; i<size; i++)
		(*this)[i]=rand();
}

Array::Array(const Array& other_S)
{
	size= other_S.size;
	ptr = new int[size];
	assert(ptr != 0);

	for (int i=0; i<size; i++)
		(*this)[i]= other_S[i];
}

Array::~Array()
{
	delete[] ptr;
}

int Array::getsize()
{
	return size;
}

const Array& Array::operator=(const Array& right)
{
	if (&right != this)
	{
		delete[] ptr;
		size = right.size;
		ptr = new int[size];
		assert(ptr != 0);
		for (int i = 0; i < size; i++)
			(*this)[i] = right[i];
	}
	return *this;
}

const Array& Array::operator=(const int right)
{
	for (int i = 0; i < size; i++)
		(*this)[i] = right;
	return *this;
}


int Array::operator==( const Array& right)
{
	long double s1=0, s2=0;
	for(int i=0; i<size; i++)
		s1+=(*this)[i];

	for(int i=0; i<right.size; i++)
		s2+=right[i];

	if (s1==s2) return 1;
	return 0;
}

int Array::operator!=(const Array& right)
{
	return !(*this ==right);
}

int Array::operator>(const Array& right)
{
	long double s1=0, s2=0;
	for(int i=0; i<size; i++)
		s1+=(*this)[i];

	for(int i=0; i<right.size; i++)
		s2+=right[i];

	if (s1>s2) return 1;
	return 0;
}

int Array::operator<(const Array& right)
{
	long double s1=0, s2=0;
	for(int i=0; i<size; i++)
		s1+=(*this)[i];

	for(int i=0; i<right.size; i++)
		s2+=right[i];

	if (s1<s2) return 1;
	return 0;
}

Array Array::operator/(const Array& right)
{
	if (size <= right.size)
	{
		Array x(right.size);
		for (int i = 0; i < size; i++)
		{
			if (right[i] == 0) 	throw Zero_Exc;
			else x[i] = (*this)[i] / right[i];
		}
		for (int i = size; i < right.size; i++)
		{
			if (right[i] == 0) throw Zero_Exc;
			else x[i] = 0;
		}
		return x;
	}
	else throw Div_Exc;
}


Array Array::operator-(const int right)
{
	Array X(*this);
	for(int i=0; i<size; i++)
		{
			long double d = (*this)[i]*1.0-right;
			if (d>INT_MAX || d<INT_MIN) throw Sum_Over;
			else X[i]-=right;
		}
	return X;
}

Array Array::operator-()
{
	Array X(*this);
	for(int i=0; i<size; i++)
		{
			X[i]=-X[i];
		}
	return X;
}



Array Array::operator-=(const int right)
{
	for(int i=0; i<size; i++)
		{
			long double d = (*this)[i]*1.0-right;
			if (d>INT_MAX || d<INT_MIN) throw Sum_Over;
			else (*this)[i]-=right;
		}
	return *this;
}

Array Array::operator-=(const Array& right)
{	
	for(int i=0; i<size; i++)
		{
			long double d = (*this)[i]*1.0-right[i];
			if (d>INT_MAX || d<INT_MIN) throw Sum_Over;
			else (*this)[i]-=right[i];
		}
	return *this;
}

Array Array::operator*(const Array& right)
{
	if (size<=right.size) 	
	{
		Array X(right.size);
		for(int i=0; i<right.size; i++)
			{
				long double m = (*this)[i]*1.0*right[i];
				if (m>INT_MAX || m<INT_MIN) throw Mult_Over;
				X[i]=(*this)[i]*right[i];
			}
		return X;
	}
	else 
	{
		Array X(size);
		for(int i=0; i<right.size; i++)
			{
				long double m = (*this)[i]*1.0*right[i];
				if (m>INT_MAX || m<INT_MIN) throw Mult_Over;
				X[i]=(*this)[i]*right[i];
			}
		return X;
	}
}

int& Array::operator[](int n) const
{
	assert(n >= 0 && n < size);
	return ptr[n];
}

istream& operator>>(istream& inp, Array& Arr)
{
	for (int i=0; i<Arr.size; i++)
		{
			for (;;)
			{
				cout<<"Введите "<<i<<"-ый элемент: ";
				ifstream inp("CON");
				inp>>Arr[i];
				if (inp.fail() || inp.bad() )
					cout<<"Ошибка ввода данных!!!"<<endl;
				else break;
			}
	}
	return inp;
}

ostream& operator<<(ostream& ost, const Array& Arr)
{
	for(int i=0; i<Arr.size; i++)
		{
			ost<<Arr[i]<< "\t";
			if((i+1)!=Arr.size && (i+1)%10==0) ost<<endl;
		}
	return ost;
}

