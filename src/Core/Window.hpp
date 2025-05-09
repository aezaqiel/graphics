#pragma once

#include <string>
#include <functional>

#include "Types.hpp"
#include "Events/Event.hpp"

struct GLFWwindow;

namespace Graphics {

    class Window
    {
    public:
        struct Config
        {
            i32 Width;
            i32 Height;
            std::string Title;

            Config(i32 width = 400, i32 height = 300, const std::string& title = "Window")
                : Width(width), Height(height), Title(title) {}
        };

        using EventCallbackFn = std::function<void(Event&)>;

    public:
        Window(const Config& config = Config());
        ~Window();

        inline i32 Width() const { return m_Data.Width; }
        inline i32 Height() const { return m_Data.Height; }
        inline std::string Title() const { return m_Data.Title; }
        inline void* GetNative() const { return m_Window; }

        void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

        void PollEvents();
    
    private:
        struct WindowData
        {
            i32 Width { 0 };
            i32 Height { 0 };
            std::string Title;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

        GLFWwindow* m_Window { nullptr };
    };

}
