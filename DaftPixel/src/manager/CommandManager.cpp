#include "manager/CommandManager.h"

CommandManager::CommandManager(Canvas::RenderContext& renderContext) : renderContext(renderContext) {}

void CommandManager::executeCommand(Action action, InputManager& inputManager) {
	switch (action) {
	case Action::IncreaseScaleFactor:
		renderContext.changeScaleFactor(static_cast<int8_t>(1));
		break;
	case Action::DecreaseScaleFactor:
		renderContext.changeScaleFactor(static_cast<int8_t>(-1));
		break;
	case Action::None:
		// No action to be taken
		break;
		// Future actions
	}

	// Mark the action as handled in the input manager
	inputManager.markActionAsHandled(action);
}
