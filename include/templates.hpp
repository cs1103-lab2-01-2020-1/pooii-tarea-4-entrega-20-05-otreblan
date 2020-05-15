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

#pragma once

#include <set>
#include <iterator>

namespace aru
{
template <typename T>
T delete_duplicated(T container)
{
	using value_t = typename std::iterator_traits<typename T::iterator>::value_type ;

	T result;

	std::set<value_t> values;

	for(const auto& i: container)
	{
		if(values.find(i) == values.end()) // Not repeated
		{
			values.insert(i);
			result.push_back(i);
		}
	}

	return result;
}
}
