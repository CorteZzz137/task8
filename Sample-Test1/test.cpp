#include "pch.h"
#include "../task8/poly.hpp"
#include <fstream>

TEST(HermitePolynomials, 1) {
	int n = 11;
	vector<Polynomial> H;
	H.push_back(1);
	H.push_back(make_pair(1, 1));
	for (int i = 2; i < n; i++) {
		H.push_back((Polynomial)make_pair(1,1) * H[i-1] - (Polynomial)(i-1) * H[i-2]);
	}
	ofstream out("out.txt");
	for (int i = 0; i < n; i++) {
		out << "H_" << i << "(x) =";
		H[i].write(out);
	}
	out.close();

	ifstream ansfin("ansout.txt");
	ifstream fin("out.txt");
	while (!ansfin.eof() && !fin.eof()) {
		string s, ans_s;
		getline(fin, s);
		getline(ansfin, ans_s);
		EXPECT_TRUE(s == ans_s);
	}
	EXPECT_TRUE(fin.eof() == ansfin.eof());
	fin.close();
	ansfin.close();
}
