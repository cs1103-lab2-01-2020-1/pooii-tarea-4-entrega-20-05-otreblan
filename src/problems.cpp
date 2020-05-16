// Tarea
// Copyright © 2020 otreblan
//
// tarea-4 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// tarea-4 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with tarea-4.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>

#include <problems.hpp>
#include <templates.hpp>

void aru::problem5()
{
	std::vector<int> vec = {1,2,4,2,2,3,4,2,2,2};

	vec = aru::delete_duplicated(vec);


	std::cout << "Ejercicio 5:\n";

	for(auto& i: vec)
	{
		std::cout << i << '\n';
	}

	std::cout << '\n';
}

void aru::problem6()
{
	std::vector<int> vec = {1,2,3,4,5,6};

	vec = aru::rotate_range(vec, -7);


	std::cout << "Ejercicio 6:\n";

	for(auto& i: vec)
	{
		std::cout << i << '\n';
	}

	std::cout << '\n';
}

void aru::problem7()
{
	std::pair p = {1,2.5};

	int key;
	double value;
	unpack_pair(key, value) = p;

	std::cout
		<< "Ejercicio 7:\n"
		<< "Key: " << key << '\n'
		<< "Value: " << value << '\n'
		<< '\n'
	;
}

void aru::problem8()
{
	std::tuple p = {1,2.5,4,(long)100};

	int key;
	double value;
	int value2;
	long value3;
	unpack(key, value, value2, value3) = p;

	std::cout
		<< "Ejercicio 8:\n"
		<< "Key: " << key << '\n'
		<< "Value: " << value << '\n'
		<< "Value2: " << value2 << '\n'
		<< "Value3: " << value3 << '\n'
		<< '\n'
	;
}
