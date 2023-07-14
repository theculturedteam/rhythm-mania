#include "system/inputSystem.hpp"
#include "Message.hpp"
#include "data/inputData.hpp"

InputSystem::InputSystem(MessageBus* msgBus) 
	:System(msgBus)
{}

void InputSystem::update() {
	for (InputData* inputData : *inputInstance.getInputs()) {
		Message* msg = new Message("input");
		msg->setData(inputData);
		msgBus->postMessage(msg);
	}
	inputInstance.clearInputs();
}
