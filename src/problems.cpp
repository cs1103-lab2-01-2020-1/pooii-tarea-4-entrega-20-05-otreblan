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
