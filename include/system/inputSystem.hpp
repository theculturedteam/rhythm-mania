#pragma once
#include "MessageBus.hpp"
#include "System.hpp"
#include "framework/input.hpp"

class InputSystem : public System {
	private:
		Input& inputInstance = Input::getInstance();
	
	public:
		InputSystem(MessageBus* msgBus);
		void handleMessage() {};
		~InputSystem() {};
		void update();
};
