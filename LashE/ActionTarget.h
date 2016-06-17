#pragma once

#include <functional>

#include "Action.h"
#include "ActionMap.h"
#include <list>

namespace lshe
{

	template<typename T = int>
	class ActionTarget
	{
	public:
		ActionTarget(const ActionTarget<T>&) = delete;
		ActionTarget<T>& operator=(const ActionTarget<T>&) = delete;

		using FuncType = std::function<void(const sf::Event&)>;

		ActionTarget(const ActionMap<T>& map) : m_actionMap(map) {}
		
		bool processEvent(const sf::Event& event) const
		{
			bool res = false;
			for (auto& pair : m_eventsPoll)
			{
				if (m_actionMap.get(pair.first) == event)
				{
					pair.second(event);
					res = true;
					break;
				}
			}
			return res;
		}

		void processEvents() const
		{
			for (auto& pair : m_eventsRealTime)
			{
				const Action& action = m_actionMap.get(pair.first);
				if (action.test())
					pair.second(action.m_event);
			}
		}

		void bind(const T& key, const FuncType& callback)
		{
			const Action& action = m_actionMap.get(key);
			if (action.m_type & Action::Type::REALTIME)
				m_eventsRealTime.emplace_back(key, callback);
			else
				m_eventsPoll.emplace_back(key, callback);
		}

		void unbind(const T& key)
		{
			auto remove_func = [&key](const std::pair<T, FuncType>& pair) -> bool
			{
				return pair.first == key;
			};

			const Action& action = m_actionMap.get(key);
			if (action.m_type & Action::Type::REALTIME)
				m_eventsRealTime.remove_if(remove_func);
			else
				m_eventsPoll.remove_if(remove_func);
		}

	private:
		std::list<std::pair<T, FuncType>> m_eventsRealTime;
		std::list<std::pair<T, FuncType>> m_eventsPoll;

		const ActionMap<T>& m_actionMap;
	};	
}

