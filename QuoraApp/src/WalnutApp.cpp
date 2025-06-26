#pragma once

#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"
#include "Walnut/UI/UI.h"

#include "AppLayer.h"

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Quora";
	spec.CustomTitlebar = true;

	Walnut::Application* app = new Walnut::Application(spec);
	std::shared_ptr<AppLayer > exampleLayer = std::make_shared<AppLayer >();

	app->PushLayer(exampleLayer);
	app->SetMenubarCallback([app, exampleLayer]()
	{

		exampleLayer->SetupUI(app);


	});
	return app;
}