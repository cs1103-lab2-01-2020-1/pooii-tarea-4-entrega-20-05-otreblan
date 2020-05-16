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
#include <list>

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
	unpack(key, value) = p;

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

void aru::problem9()
{
	// Esto no compila con clang
	auto vec = generar_contenedor(1,2,3,4);

	std::cout << "Ejercicio 9:\n";
	for(auto i: vec)
	{
		std::cout << i << '\n';
	}

	auto li = generar_contenedor<std::list>(10000000,2,3,4,10);

	for(auto i: li)
	{
		std::cout << i << '\n';
	}

	std::cout <<  '\n';
}

void aru::problem10()
{
	std::vector vec1 = {1};
	std::vector vec2 = {2,2,3};
	std::vector vec3 = {2,2,3,3,4};
	std::vector vec4 = {2,2};

	std::cout << "Ejercicio 10:\n";
	std::cout
		<< min_size(vec4, vec2, vec3) << '\n'
		<< min_size(vec1, vec2) << '\n'
		<< min_size(vec3) << '\n'
		<< '\n'
	;
}

void aru::problem11()
{
	std::list vec1 = {2,2,3};
	std::list vec2 = {2,3,4};
	std::list vec3 = {10,20,30,40};


	std::cout << "Ejercicio 11:\n";
	auto vec_vec = zip(vec1, vec2, vec3);

	for(const auto& i: vec_vec)
	{
		for(const auto& j: i)
		{
			std::cout << j << ' ';
		}
		std::cout << "\n\n";
	}
}

void aru::problem12()
{
	std::vector vec = {1,2,3,4,5,6,8,9,10,11};
	std::cout
		<< "Ejercicio 12:\n";
	for(auto i: vec)
	{
		std::cout
			<< std::boolalpha << aru::binary_search(vec.begin(), vec.end(), i)
			<< '\n'
		;
	}

	bool fail = aru::binary_search(vec.begin(), vec.end(), 7);
	bool fail2 = aru::binary_search(vec.begin(), vec.end(), -1000);
	bool fail3 = aru::binary_search(vec.begin(), vec.end(), 1000000);

	std::cout
		<< std::boolalpha
		<< fail << '\n'
		<< fail2 << '\n'
		<< fail3 << '\n'
		<< '\n'
	;
}
