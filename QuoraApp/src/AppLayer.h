#pragma once
#include "Walnut/Application.h"
#include "Walnut/Image.h"
#include "Walnut/UI/UI.h"
#include "Walnut/UI/Console.h"

#include <iostream>
#include <fstream>
#include <vector>


class AppLayer : public Walnut::Layer
{
private:
	Walnut::Application* m_app;
	Walnut::UI::Console* m_console;
public:
	void SetupUI(Walnut::Application* app) {
	
		m_app = app;
	    m_console = new	Walnut::UI::Console("Console");

	}

	virtual void OnUIRender() override
	{
		m_console->OnUIRender();
		
		ImGui::Begin("Hello");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();

		DrawAboutModal();
	}

	void DrawAboutModal()
	{
		if (!m_AboutModalOpen)
			return;

		ImGui::OpenPopup("About");
		m_AboutModalOpen = ImGui::BeginPopupModal("About", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
		if (m_AboutModalOpen)
		{
			auto image = Walnut::Application::Get().GetApplicationIcon();
			ImGui::Image(image->GetDescriptorSet(), { 48, 48 });

			ImGui::SameLine();
			Walnut::UI::ShiftCursorX(20.0f);

			ImGui::BeginGroup();
			ImGui::Text("Quora Slicer");
			ImGui::Text("by David Norden.");
			ImGui::EndGroup();

			if (Walnut::UI::ButtonCentered("Close"))
			{
				m_AboutModalOpen = false;
				ImGui::CloseCurrentPopup();
			}

			ImGui::EndPopup();
		}
	}

	void ShowAboutModal()
	{
		m_AboutModalOpen = true;
	}
private:
	bool m_AboutModalOpen = false;
};
