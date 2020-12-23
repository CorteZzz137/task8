#pragma once
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Polynomial
{
public:
	Polynomial(map<int, double> new_data) {
		data = new_data;
	}
	Polynomial(pair<int, double> monom) {
		data.insert(monom);
	}
	Polynomial(pair<int, int> monom) {
		data.insert(monom);
	}
	Polynomial(double value) {
		data[0] = value;
	}
	Polynomial() {}
	~Polynomial() {}
	void write(ostream &out = cout) {
		for (auto it = this->data.rbegin(); it != this->data.rend(); it++) {
			if (it->second != 0) {
				if (it->second < 0) {
					out << " - ";
				}
				else if (it != data.rbegin()) {
					out << " + ";
				}
				else {
					out << "   ";
				}
				if (it->second != 1 || it->first == 0) {
					out << abs(it->second);
				}
				if (it->first == 1) {
					out << "x";
				}
				else if (it->first != 0) {
					out << "x^" << it->first;
				}
			}
		}
		out << endl;
	}


	friend const Polynomial operator+(const Polynomial& left, const Polynomial& right);
	friend const Polynomial operator-(const Polynomial& left, const Polynomial& right);
	friend const Polynomial operator*(const Polynomial& left, const Polynomial& right);
	friend Polynomial& operator+=(Polynomial& left,const Polynomial& right);
	friend Polynomial& operator-=(Polynomial& left, const Polynomial& right);
	friend Polynomial& operator*=(Polynomial& left, const Polynomial& right);
	Polynomial& operator=(const Polynomial& right) {
		if (this != &right) {
			this->data = right.data;
		}
		return *this;
	}
private:
	map<int, double> data;
};

const Polynomial operator+(const Polynomial& left, const Polynomial& right) {
	Polynomial tmp;
	for (auto& i : left.data) {
		tmp.data[i.first] += i.second;
	}
	for (auto& i : right.data) {
		tmp.data[i.first] += i.second;
	}
	return tmp;
}

const Polynomial operator-(const Polynomial& left, const Polynomial& right) {
	Polynomial tmp;
	for (auto& i : left.data) {
		tmp.data[i.first] += i.second;
	}
	for (auto& i : right.data) {
		tmp.data[i.first] -= i.second;
	}
	return tmp;
}

const Polynomial operator*(const Polynomial& left, const Polynomial& right) {
	Polynomial tmp;
	for (auto& i : right.data) {
		for (auto& j : left.data) {
			tmp.data[i.first+j.first] += i.second * j.second;
		}
	}
	return tmp;
}

Polynomial& operator+=(Polynomial& left, const Polynomial& right) {
	left = left + right;
	return left;
}

Polynomial& operator-=(Polynomial& left, const Polynomial& right) {
	left = left - right;
	return left;
}

Polynomial& operator*=(Polynomial& left, const Polynomial& right) {
	left = left * right;
	return left;
}