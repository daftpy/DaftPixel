#include "application.h"

Application::Application() : m_editorController(m_editorContext) {

}

void Application::Start() {
	m_editorController.run();
}