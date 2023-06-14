#pragma once
#include "controller/editor/EditorController.h"
#include "model/editor/Context.h"

class Application {
public:
	Application();

	void Start();

private:
	Editor::Context m_editorContext;
	Editor::EditorController m_editorController;
};