#include "HugeInteger.h"
#include<iostream>
#include<string>
using namespace std;


HugeInteger::HugeInteger(int a)
{
	for (int i = 39; i >= 0; i--) {
		int n = a % 10;
		integer[i] = n;
		a = a / 10;
	}
}

HugeInteger::HugeInteger(const char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		integer[39 - i] = str[len - i - 1];
	}
}

HugeInteger HugeInteger::add(const HugeInteger& a)
{	
	HugeInteger temp;
	int carry = 0;
	for (int i = 39; i >= 0; i--) {
		temp.integer[i] = integer[i] + a.integer[i]+carry;
		carry = temp.integer[i] / 10;
		temp.integer[i] = temp.integer [i] % 10;
	}
	return temp;
}

HugeInteger HugeInteger::add(int a)
{
	HugeInteger temp;
	int carry = 0;
	for (int i = 39; i >= 0; i--) {
		int n = a % 10;
		temp.integer[i] = integer[i] + n+carry;
		a = a / 10;
		carry = temp.integer[i] / 10;
		temp.integer[i] = temp.integer[i] % 10;
	}
	return temp;
}

HugeInteger HugeInteger::add(const char* str)
{	
	HugeInteger temp;
	int carry = 0;
	int len = strlen(str);
	int a = len < 39 ? len : 39;
		for (int i = 0; i <= a; i++){
			temp.integer[39 - i] = integer[39 - 1] + str[len - i - 1]+carry;
			carry = temp.integer[i] / 10;
			temp.integer[i] %= 10;
	}
	return temp;
}

HugeInteger HugeInteger::subtract(const HugeInteger& a)
{
	HugeInteger temp;
	int borrow = 0;
	for (int i = 39; i >= 0; i--) {
		temp.integer[i] = integer[i] - a.integer[i]-borrow;
		if (temp.integer[i] < 0) {
			temp.integer[i] = temp.integer[i] + 10;
			borrow = 1;
		}
		else
			borrow = 0;
	}
	return temp;
}

HugeInteger HugeInteger::subtract(int a)
{
	HugeInteger temp;
	for (int i = 39; i >= 0; i--) {
		int n = a % 10;
		temp.integer[i] = integer[i] - n;
		a = a / 10;
	}
	return temp;
}

HugeInteger HugeInteger::subtract(const char* str)
{
	HugeInteger temp;
	int len = strlen(str);
	int a = len < 39 ? len : 39;
	for (int i = 0; i <= a; i++) {
		temp.integer[39 - i] = integer[39 - 1] - str[len - i - 1];
	}
	return temp;
}

bool HugeInteger::isEqualTo(HugeInteger& a)
{
	for (int i = 0; i < 40; i++) {
		if (integer[i] != a.integer[i]) {
			return false;
		}
	}
	return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger& a)
{
	return !isEqualTo(a);
}

bool HugeInteger::isGreaterThan(HugeInteger& a)
{
	for (int i = 0; i < 40; i++) {
		if (integer[i] < a.integer[i]){
			return true;
			}
		else if (integer[i] < a.integer[i]) {
			return false;
		}
	}
	return false;
}

bool HugeInteger::isLessThan(HugeInteger& a)
{
	return !isGreaterThan(a)&&!isEqualTo(a);
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger& a)
{
	return isGreaterThan(a)||isEqualTo(a);
}

bool HugeInteger::isLessThanOrEqualTo(HugeInteger& a)
{
	return isLessThan(a) || isEqualTo(a);
}

bool HugeInteger::isZero()
{
	for (int i = 0; i < 40; i++) {
		if (integer[i] != 0) {
			return false;
		}
	}
	return true;
}

void HugeInteger::input(const char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		integer[39 - i] = str[len - i - 1];
	}
}

void HugeInteger::output()
{
	int i=0;
	for (; i < 40 && integer[i] == 0; i++); 
	{}
	if (i == 40) {
		cout << 0;
	}
	else {
		for (; i < 40; ++i) {
			cout << integer[i];
		}
	}
}

