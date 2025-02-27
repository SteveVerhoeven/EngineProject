#pragma once
#include <Windows.h>
#include <XInput.h>
#include <iostream>

#define LOG(x) std::cout << x;
#define LOG_ENDLINE(x) std::cout << x << '\n';

#include "GameObject.h"
//#include "LevelComponent.h"

#include "SceneManager.h"
#include "Scene.h"

#include "Locator.h"
#include "Audio.h"

#include "../MiniGame/QBERT.h"
#include "TextureComponent.h"


namespace Helheim
{	
	class Command
	{
		public:
			virtual ~Command() = default;
			virtual void Execute() = 0;

		protected:

	};

	// During class
	class JumpCommand_Class final : public Command
	{
		public:
			void Execute() override { Jump(); };

		private:
			void Jump() { LOG_ENDLINE("Jump - "); }
	};
	class FireCommand_Class final : public Command
	{
		public:
			void Execute() override { Fire(); };

		private:
			void Fire() { LOG_ENDLINE("Fire - "); }
	};
	class DuckCommand_Class final : public Command
	{
		public:
			void Execute() override { Duck(); };

		private:
			void Duck() { LOG_ENDLINE("Duck - "); }
	};
	class FartCommand_Class final : public Command
	{
		public:
			void Execute() override { Fart(); };
		
		private:
			void Fart() { LOG_ENDLINE("Fart - "); }
	};
	class MoveCommand final : public Command
	{
		struct Direction_Move
		{
			float direction_X;
			float direction_Y;
		};
	public:
		void Execute() override { Move(); };
		void SetDirection(const Direction_Move& dir) { m_Movement = dir; };

	private:
		Direction_Move m_Movement;

		void Move()
		{
			std::string output{ "Move - " };
			if (m_Movement.direction_X > 0)
				output += " RIGHT &";
			else
				output += " LEFT &";
			if (m_Movement.direction_Y > 0)
				output += " FORWARD";
			else
				output += " BACK";

			LOG_ENDLINE(output);
		}
	};
	class AimCommand final : public Command
	{
		struct Direction_Aim
		{
			float direction_X;
			float direction_Y;
		};
	public:
		void Execute() override { Aim(); };
		void SetDirection(const Direction_Aim& dir) { m_Movement = dir; };

	private:
		Direction_Aim m_Movement;

		void Aim()
		{
			std::string output{ "Aim - " };
			if (m_Movement.direction_X > 0)
				output += " RIGHT &";
			else
				output += " LEFT &";
			if (m_Movement.direction_Y > 0)
				output += " UP";
			else
				output += " DOWN";

			LOG_ENDLINE(output);
		}
	};
	class DriveCommand final : public Command
	{
		public:
			DriveCommand(const std::string& dir)
				: m_Direction{ dir }
			{}

			void Execute() override { Drive(); };

		private:
			std::string m_Direction;
			void Drive() 
			{ 
				std::string output{ "Driving " + m_Direction + " - " };
				LOG_ENDLINE(output); 
			}
	};
	class ScopeCommand final : public Command
	{
		public:
			void Execute() override { Scope(); };

		private:
			void Scope() { LOG_ENDLINE("Scope - "); }
	};
	class ShootCommand final : public Command
	{
		public:
			void Execute() override { Shoot(); };

		private:
			void Shoot() { LOG_ENDLINE("Shoot - "); }
	};
	class ScrollInventoryCommand final : public Command
	{
	public:
		ScrollInventoryCommand(const bool scrollLEFT, const bool scrollRIGHT, const bool scrollUP, const bool scrollDOWN)
			: m_ScrollLEFT{ scrollLEFT }
			, m_ScrollRIGHT{ scrollRIGHT }
			, m_ScrollUP{ scrollUP }
			, m_ScrollDOWN{ scrollDOWN }
		{}

		void Execute() override { ScrollInventory(); };

	private:
		bool m_ScrollLEFT,
			m_ScrollRIGHT,
			m_ScrollUP,
			m_ScrollDOWN;
		void ScrollInventory()
		{
			std::string output{ "Scrolling " };
			if (m_ScrollLEFT)
				output += "LEFT \n";
			else if (m_ScrollRIGHT)
				output += "RIGHT \n";
			if (m_ScrollUP)
				output += "UP \n";
			else if (m_ScrollDOWN)
				output += "DOWN \n";

			LOG_ENDLINE(output);
		}
	};
	class ColorChangeCommand final : public Command
	{
		public:
			ColorChangeCommand(const Helheim::Observer::OBSERVER_EVENTS& event)
				: m_Event(event)
			{}
			void Execute() override { ChangeColor(); };

		private:
			Helheim::Observer::OBSERVER_EVENTS m_Event;
			void ChangeColor()
			{
				LOG_ENDLINE("Color changed - ");

				//LoggingAudio* pLoggingAudio{ dynamic_cast<LoggingAudio*>(Helheim::Locator::GetAudioService()) };
				//if (pLoggingAudio)
				//	pLoggingAudio->RequestPlaySound(AudioMessages::SCORE_UP);
				//else
				//	dynamic_cast<ConsoleAudio*>(Helheim::Locator::GetAudioService())->RequestPlaySound(AudioMessages::SCORE_UP);

				////auto scene{ Helheim::SceneManager::GetInstance().GetActiveScene() };
				//auto scene{ Locator::GetSceneService()->GetActiveGameScene() };
				//auto object{ scene->GetObjectByName("LevelCube") };
				//object->GetComponent<Helheim::LevelComponent>()->ColorChange(m_Event);
			}
	};

	// Change buttons commands
	class ChangeButtonsCommand final : public Command
	{
		public:
			void Execute() override { ChangeButtons(); };

		private:
			void ChangeButtons()
			{ 
				LOG_ENDLINE("Changeeee - "); 
				//Locator::GetInputService()->EditKeyInMap();
			}
	};

	// No command
	class NULLCommand final : public Command
	{
		public:
			void Execute() override {};
			
		private:
	};
}