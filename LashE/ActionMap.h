#pragma once
#include <unordered_map>
#include "Action.h"
namespace lshe
{
	template<typename T = int>
	class ActionMap
	{
	public:
		ActionMap(const ActionMap<T>&) = delete;
		ActionMap<T>& operator=(const ActionMap<T>&) = delete;
		ActionMap() = default;
		
		void map(const T& key, const Action& action)
		{
			m_map.emplace(key, action);
		}

		const Action& get(const T& key) const { return m_map.at(key); }

	private:
		std::unordered_map<T, Action> m_map;
	};
}



