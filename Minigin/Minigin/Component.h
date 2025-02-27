#pragma once
#include "MiniginPCH.h"


#include "Observer.h"

namespace Helheim
{
	class Scene;
	class GameObject;
	class Component
	{
		public:
			Component(Helheim::GameObject* pParentObject, const bool canRenderComponent);
			virtual ~Component() = default;

			Component(const Component&) = delete;
			Component(Component&&) noexcept = delete;
			Component& operator=(const Component&) = delete;
			Component& operator=(Component&&) noexcept = delete;

			virtual void Initialize(Scene* pParentScene) = 0;
			virtual void PostInitialize(Scene* pParentScene) = 0;
			virtual void Update(const float elapsedSec) = 0;
			virtual void FixedUpdate(const float timeEachUpdate) = 0;
			
			void AddObserver(const std::shared_ptr<Helheim::Observer>& pObserver) 
			{ 
				pObserver->SetOwnerComponent(this);
				m_pObservers.push_back(pObserver); 
			}

			bool CanRenderComponent() const { return m_CanRenderComponent; }
			void SetCanRenderComponent(const bool canRenderComponent) { m_CanRenderComponent = canRenderComponent; }
			void NotifyObservers(Helheim::GameObject* pParentObject, const Observer::OBSERVER_EVENTS& observerEvent);

			Helheim::GameObject* GetParentObject() const { return m_pParentObject; }

		protected:
			//EventQueue<AudioMessages> x;
			//UNREFERENCED_PARAMETER(x);

			Helheim::GameObject* m_pParentObject;
			
			
			std::vector<std::shared_ptr<Helheim::Observer>> m_pObservers;

		private:
			bool m_CanRenderComponent;
	};
}