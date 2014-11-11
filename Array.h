#pragma once

#include <iostream>
#include <assert.h> 
#include <fstream>//Alex was here
#include <limits.h>
#include <time.h>

using namespace std;

class Array
{
	friend ostream& operator<<(ostream&, const Array&);
	friend istream& operator>>(istream&, Array&);
private:
	int *ptr;
	int size;
public:
	Array(int =1);
	Array(const Array&);
	~Array();

	const Array& operator=(const Array&);
	const Array& operator=(const int);

	int operator==(const Array&);
	int operator!=(const Array&);
	int operator<(const Array&);
	int operator>(const Array&);
	Array operator/(const Array&);
	Array operator-(const int);
	Array operator-();
	Array operator-=(const int);
	Array operator-=(const Array&);
	Array operator*(const Array&);
	
	int& operator[](int) const;
	int getsize();

};
