#include "MiniginPCH.h"
#include "TransformComponent.h"

Helheim::TransformComponent::TransformComponent(Helheim::GameObject* pParentObject, const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale)
							: Component(pParentObject, false)
							, m_Position(position)
							, m_Rotation(rotation)
							, m_Scale(scale)
{}

void Helheim::TransformComponent::Initialize(Scene*) // pParentScene
{}
void Helheim::TransformComponent::PostInitialize(Scene*)//pParentScene
{
}
void Helheim::TransformComponent::Update(const float)
{}
void Helheim::TransformComponent::FixedUpdate(const float)
{}