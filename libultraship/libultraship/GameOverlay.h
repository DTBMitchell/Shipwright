#pragma once
#include <string>
#include <vector>

#include "Lib/ImGui/imgui.h"
#include <unordered_map>

namespace Ship {

	enum class OverlayType {
		TEXT, IMAGE, NOTIFICATION
	};

	struct Overlay {
		OverlayType type;
		const char* value;
		float fadeTime;
		float duration;
	};

	class GameOverlay {
	public:
		std::unordered_map<std::string, Overlay*> RegisteredOverlays;
		std::unordered_map<std::string, ImFont*> Fonts;
		std::string CurrentFont = "Default";
		void Init();
		void Draw();
		void DrawSettings();
		static float GetScreenWidth();
		static float GetScreenHeight();
		static float GetStringWidth(const char* text);
		static ImVec2 CalculateTextSize(const char* text, const char* text_end = NULL, bool hide_text_after_double_hash = false, float wrap_width = -1.0f);
		void TextDraw(float x, float y, bool shadow, ImVec4 color, const char* text, ...);
		void TextDrawNotification(float duration, bool shadow, const char* fmt, ...);
	private:
		bool NeedsCleanup = false;
		void CleanupNotifications();
		void LoadFont(const std::string& name, const std::string& path, float fontSize);
	};
}
