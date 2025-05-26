#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"



void embraceTheDarkness()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);

	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(8.00f, 8.00f);
	style.FramePadding = ImVec2(5.00f, 2.00f);

	style.ItemSpacing = ImVec2(6.00f, 6.00f);
	style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.FrameBorderSize = 1;
	style.TabBorderSize = 1;
	style.WindowRounding = 7;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;

	style.TabRounding = 4;
}

void Themetwo()
{
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	// Personalize as cores da interface
	colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.14f, 0.17f, 1.00f); // Cor de fundo da janela
	colors[ImGuiCol_Header] = ImVec4(0.20f, 0.24f, 0.29f, 1.00f); // Cor dos headers
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.30f, 0.35f, 1.00f); // Cor ao passar o mouse
	colors[ImGuiCol_Button] = ImVec4(0.20f, 0.22f, 0.25f, 1.00f); // Cor dos botões
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.32f, 0.38f, 1.00f); // Cor ao passar o mouse sobre o botão
	colors[ImGuiCol_ButtonActive] = ImVec4(0.10f, 0.25f, 0.30f, 1.00f); // Cor ao clicar no botão
	colors[ImGuiCol_FrameBg] = ImVec4(0.18f, 0.20f, 0.23f, 1.00f); // Fundo dos frames
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.30f, 0.33f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.30f, 0.35f, 0.39f, 1.00f);

	style.WindowRounding = 5.0f;     // Arredondamento das janelas
	style.FrameRounding = 4.0f;     // Arredondamento dos frames
	style.ScrollbarRounding = 12.0f; // Arredondamento da scrollbar
	style.GrabRounding = 4.0f;     // Arredondamento do slider/controle de input
}



void activateImGuiStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowRounding = 5.3f;
	style.FrameRounding = 2.3f;
	style.ScrollbarRounding = 0;

	style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.15f, 1.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.70f, 0.70f, 0.70f, 0.65f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.01f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.90f, 0.80f, 0.80f, 0.40f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.90f, 0.65f, 0.65f, 0.45f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.87f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.91f);

	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.83f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.70f, 0.70f, 0.62f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.30f, 0.30f, 0.84f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.48f, 0.72f, 0.89f, 0.49f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.30f, 0.69f, 1.00f, 0.53f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.44f, 0.61f, 0.86f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.38f, 0.62f, 0.83f, 1.00f);

	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);

	style.Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);

}



//imgui themes by CHAT GPT

void SetCartoonTheme() {
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	// Cores vibrantes e contrastantes
	colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);             // Preto para texto
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);      // Cinza para texto desabilitado
	colors[ImGuiCol_WindowBg] = ImVec4(0.95f, 0.91f, 0.73f, 1.00f);          // Fundo de janela amarelo pastel
	colors[ImGuiCol_ChildBg] = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);           // Fundo de child window cinza claro
	colors[ImGuiCol_PopupBg] = ImVec4(0.98f, 0.94f, 0.89f, 0.98f);           // Fundo de popups bege claro
	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);            // Preto para bordas
	colors[ImGuiCol_FrameBg] = ImVec4(0.98f, 0.78f, 0.18f, 1.00f);           // Amarelo vibrante para caixas de entrada
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.98f, 0.85f, 0.40f, 1.00f);    // Amarelo mais claro ao passar o mouse
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.98f, 0.68f, 0.10f, 1.00f);     // Amarelo forte para ativo
	colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.22f, 0.37f, 1.00f);           // Fundo do título azul escuro
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.18f, 0.28f, 0.45f, 1.00f);     // Fundo do título azul ativo
	colors[ImGuiCol_Button] = ImVec4(0.20f, 0.72f, 0.72f, 1.00f);            // Verde água para botões
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.85f, 0.85f, 1.00f);     // Verde água claro quando hover
	colors[ImGuiCol_ButtonActive] = ImVec4(0.17f, 0.55f, 0.55f, 1.00f);      // Verde água escuro quando ativo
	colors[ImGuiCol_CheckMark] = ImVec4(0.20f, 0.70f, 0.30f, 1.00f);         // Verde para checkmarks
	colors[ImGuiCol_SliderGrab] = ImVec4(0.20f, 0.60f, 0.80f, 1.00f);        // Azul para sliders
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.75f, 0.90f, 1.00f);  // Azul mais claro para slider ativo

	// Estilização de bordas e espaçamentos
	style.FrameBorderSize = 2.0f;          // Aumenta a espessura da borda de elementos
	style.WindowBorderSize = 2.0f;         // Borda mais visível nas janelas
	style.FrameRounding = 10.0f;           // Arredondamento de bordas para um visual mais cartunesco
	style.GrabRounding = 8.0f;             // Arredondamento nos sliders e grabs
	style.WindowRounding = 12.0f;          // Arredondamento das janelas
	style.PopupRounding = 10.0f;           // Arredondamento dos popups
	style.ChildRounding = 8.0f;            // Arredondamento dos child windows

	// Ajustes de espaçamento para um estilo mais espaçado e amigável
	style.ItemSpacing = ImVec2(10.0f, 8.0f);      // Espaçamento entre elementos
	style.WindowPadding = ImVec2(12.0f, 10.0f);   // Padding das janelas
	style.FramePadding = ImVec2(8.0f, 5.0f);      // Padding dos frames
}


void SetElegantTheme() {
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	// Cores suaves, vibrantes e bem contrastadas
	colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);              // Quase branco para texto
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);      // Cinza suave para texto desabilitado
	colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.14f, 0.24f, 1.00f);          // Fundo escuro azul-cinza
	colors[ImGuiCol_ChildBg] = ImVec4(0.14f, 0.16f, 0.26f, 1.00f);           // Fundo de child windows, tom mais escuro
	colors[ImGuiCol_PopupBg] = ImVec4(0.10f, 0.12f, 0.20f, 0.92f);           // Fundo de popups com transparência
	colors[ImGuiCol_Border] = ImVec4(0.25f, 0.25f, 0.45f, 0.60f);            // Azul-escuro suave para bordas
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);      // Sem sombra nas bordas
	colors[ImGuiCol_FrameBg] = ImVec4(0.18f, 0.20f, 0.30f, 1.00f);           // Fundo de frames (caixas de entrada)
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.28f, 0.30f, 0.40f, 1.00f);    // Fundo de frames ao passar o mouse
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.36f, 0.38f, 0.48f, 1.00f);     // Fundo de frames quando ativo
	colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.12f, 0.20f, 1.00f);           // Fundo do título da janela
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.20f, 0.22f, 0.40f, 1.00f);     // Fundo do título quando ativo
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.08f, 0.08f, 0.16f, 0.75f);  // Fundo do título quando colapsado
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.28f, 1.00f);         // Fundo da barra de menu
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.08f, 0.10f, 0.15f, 0.75f);       // Fundo do scrollbar
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.20f, 0.25f, 0.35f, 0.75f);     // Cor do grab do scrollbar
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.30f, 0.35f, 0.45f, 0.80f); // Grab do scrollbar ao passar o mouse
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.40f, 0.45f, 0.55f, 0.80f); // Grab do scrollbar quando ativo
	colors[ImGuiCol_CheckMark] = ImVec4(0.22f, 0.90f, 0.62f, 1.00f);         // Verde vibrante para checkboxes
	colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.80f, 0.70f, 1.00f);        // Verde suave para sliders
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.90f, 0.80f, 1.00f);  // Verde claro para slider ativo
	colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.38f, 1.00f);            // Azul-escuro para botões
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.35f, 0.50f, 1.00f);     // Botão ao passar o mouse
	colors[ImGuiCol_ButtonActive] = ImVec4(0.16f, 0.20f, 0.34f, 1.00f);      // Botão quando clicado
	colors[ImGuiCol_Header] = ImVec4(0.18f, 0.24f, 0.38f, 1.00f);            // Fundo do header
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.28f, 0.34f, 0.48f, 1.00f);     // Header ao passar o mouse
	colors[ImGuiCol_HeaderActive] = ImVec4(0.22f, 0.30f, 0.45f, 1.00f);      // Header quando ativo
	colors[ImGuiCol_Separator] = ImVec4(0.25f, 0.25f, 0.45f, 1.00f);         // Separadores
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.40f, 0.40f, 0.60f, 1.00f);  // Separadores quando hover
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.45f, 0.45f, 0.65f, 1.00f);   // Separadores quando ativo
	colors[ImGuiCol_Tab] = ImVec4(0.15f, 0.18f, 0.28f, 1.00f);               // Tabs
	colors[ImGuiCol_TabHovered] = ImVec4(0.25f, 0.30f, 0.45f, 1.00f);        // Tabs ao passar o mouse
	colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.25f, 0.38f, 1.00f);         // Tabs quando ativo
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.15f, 0.15f, 0.20f, 1.00f);      // Tabs desfocadas
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.20f, 0.22f, 0.28f, 1.00f); // Tabs ativas mas desfocadas

	// Estilo geral
	style.FrameRounding = 8.0f;         // Arredondamento nos frames
	style.GrabRounding = 8.0f;          // Arredondamento nos sliders
	style.WindowRounding = 12.0f;       // Arredondamento das janelas
	style.PopupRounding = 10.0f;        // Arredondamento dos popups
	style.ChildRounding = 8.0f;         // Arredondamento dos child windows
	style.ScrollbarRounding = 12.0f;    // Arredondamento do scrollbar
	style.TabRounding = 8.0f;           // Arredondamento das abas

	// Ajustes de espaçamento
	style.ItemSpacing = ImVec2(10.0f, 8.0f);      // Espaçamento entre elementos
	style.WindowPadding = ImVec2(12.0f, 10.0f);   // Padding das janelas
	style.FramePadding = ImVec2(8.0f, 6.0f);      // Padding dos frames
	style.ScrollbarSize = 16.0f;                  // Tamanho do scrollbar
}


void SetRetro2010Theme() {
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	// Cores sólidas e sóbrias, inspiradas em temas antigos
	colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);              // Cinza claro para o texto
	colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);      // Cinza escuro para texto desabilitado
	colors[ImGuiCol_WindowBg] = ImVec4(0.17f, 0.17f, 0.17f, 1.00f);          // Fundo da janela em cinza escuro
	colors[ImGuiCol_ChildBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);           // Fundo de child window em cinza médio
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.95f);           // Fundo dos popups
	colors[ImGuiCol_Border] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);            // Cinza médio para bordas
	colors[ImGuiCol_FrameBg] = ImVec4(0.28f, 0.28f, 0.28f, 1.00f);           // Fundo de caixas de entrada
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);    // Fundo de caixas de entrada ao passar o mouse
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);     // Fundo ativo de caixas de entrada
	colors[ImGuiCol_TitleBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);           // Fundo do título da janela
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);     // Fundo do título quando ativo
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.13f, 0.13f, 0.13f, 0.75f);  // Fundo do título quando colapsado
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);         // Fundo da barra de menu
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.60f);       // Fundo do scrollbar
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);     // Grab do scrollbar em cinza
	colors[ImGuiCol_SliderGrab] = ImVec4(0.25f, 0.50f, 0.80f, 1.00f);        // Azul claro para sliders
	colors[ImGuiCol_Button] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);            // Botões em cinza sólido
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);     // Botão ao passar o mouse
	colors[ImGuiCol_ButtonActive] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);      // Botão quando clicado
	colors[ImGuiCol_Header] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);            // Fundo do header
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);     // Header ao passar o mouse
	colors[ImGuiCol_HeaderActive] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);      // Header quando ativo
	colors[ImGuiCol_Separator] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);         // Separadores em cinza médio
	colors[ImGuiCol_Tab] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);               // Tabs em cinza escuro
	colors[ImGuiCol_TabHovered] = ImVec4(0.28f, 0.28f, 0.28f, 1.00f);        // Tabs ao passar o mouse
	colors[ImGuiCol_TabActive] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);         // Tabs quando ativo
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);      // Tabs desfocadas
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.28f, 0.28f, 0.28f, 1.00f); // Tabs ativas mas desfocadas

	// Estilo geral
	style.FrameRounding = 0.0f;         // Sem arredondamento nas bordas
	style.GrabRounding = 0.0f;          // Sem arredondamento nos sliders
	style.WindowRounding = 0.0f;        // Sem arredondamento nas janelas
	style.PopupRounding = 0.0f;         // Sem arredondamento nos popups
	style.ChildRounding = 0.0f;         // Sem arredondamento nos child windows
	style.ScrollbarRounding = 0.0f;     // Sem arredondamento no scrollbar
	style.TabRounding = 0.0f;           // Sem arredondamento nas abas

	// Ajustes de espaçamento
	style.ItemSpacing = ImVec2(8.0f, 4.0f);      // Espaçamento compacto entre elementos
	style.WindowPadding = ImVec2(10.0f, 10.0f);  // Padding das janelas
	style.FramePadding = ImVec2(4.0f, 3.0f);     // Padding dos frames
	style.ScrollbarSize = 14.0f;                 // Tamanho do scrollbar
}
