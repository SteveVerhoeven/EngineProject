#pragma once
#include <string>

namespace Helheim
{
	class Scene;
	class GameObject;
	class TextureComponent;
	class QBERT final
	{
		public:
			QBERT(const std::string& name);
			~QBERT();

			QBERT(const QBERT&) = delete;
			QBERT(QBERT&&) noexcept = delete;
			QBERT& operator=(const QBERT&) = delete;
			QBERT& operator=(QBERT&&) noexcept = delete;

			void Initialize(const glm::vec3& position);

			void AddToScene(Scene* pCurrentScene, const int sceneIdx);

			std::string GetName() const { return m_Name; }
			GameObject* GetGameObject_QBERT_Char() const { return m_pQBERTGO; }
			GameObject* GetGameObject_QBERT_Score() const { return m_pScoreGO; }
			
			void Reset(const glm::vec3& cubeStartPosition);

		protected:

		private:
			glm::vec3 m_StartPosition;
			std::string m_Name;
			
			GameObject* m_pQBERTGO;
			GameObject* m_pHealthGO;
			GameObject* m_pScoreGO;

			void InitializeQBERT(const glm::vec3& position);
			void InitializeHealth();
			void InitializeScore();
			void InitializeInput();
	};
}

