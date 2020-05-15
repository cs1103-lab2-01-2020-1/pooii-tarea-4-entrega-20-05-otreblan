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

template <typename T>
T rotate_range(T container, int rot)
{
	T result;
	int size = container.size();
	int limited_rot = -rot % size;
	limited_rot = limited_rot < 0 ? limited_rot+size: limited_rot;

	if(limited_rot == 0)
		return container;

	auto middle_it = std::begin(container);
	std::advance(middle_it, limited_rot);

	result.insert(std::end(result), middle_it, std::end(container));
	result.insert(std::end(result), std::begin(container), middle_it);

	return result;
}
}
