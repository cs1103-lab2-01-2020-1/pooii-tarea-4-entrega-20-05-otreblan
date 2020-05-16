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
#include <tuple>
#include <iostream>
#include <vector>
#include <cstdarg>

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

template <typename T, typename... Ts>
struct unpack: unpack<Ts...>
{
	using parent = unpack<Ts...>;
	T& value;

	constexpr
	unpack(T& value, Ts&... values):
		parent(values...),
		value(value)
	{};

	template<typename... T2s>
	constexpr void operator=(const std::tuple<T2s...>& pack)
	{
		constexpr int index = sizeof...(T2s)-sizeof...(Ts)-1;
		value = std::get<index>(pack);
		parent::operator=(pack);
	}
};


template <typename T>
struct unpack<T>
{
	T& value;

	constexpr
	unpack(T& value):
		value(value)
	{};

	template<typename... T2s>
	constexpr void operator=(const std::tuple<T2s...>& pack)
	{
		constexpr int index = sizeof...(T2s)-1;
		value = std::get<index>(pack);
	}
};

template <typename T, typename T2>
struct unpack_pair
{
	T& value1;
	T2& value2;

	constexpr
	unpack_pair(T& value1, T2& value2):
		value1(value1),
		value2(value2)
	{};

	constexpr void operator=(const std::pair<T, T2>& pair)
	{
		value1 = pair.first;
		value2 = pair.second;
	}
};

template <template <typename> class container = std::vector, typename ...Ts>
container<typename std::tuple_element<0, std::tuple<Ts...>>::type> generar_contenedor(const Ts&... values)
{
	return {values...};
}

}
