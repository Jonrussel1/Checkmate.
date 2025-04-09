
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#pragma once

// Headers
#include <SFML/Window/Export.hpp>

namespace sf
{
    class String;

    namespace Keyboard
    {

        enum class Key
        {
            Unknown = -1,
            A = 0,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            Num0,
            Num1,
            Num2,
            Num3,
            Num4,
            Num5,
            Num6,
            Num7,
            Num8,
            Num9,
            Escape,
            LControl,
            LShift,
            LAlt,
            LSystem,
            RControl,
            RShift,
            RAlt,
            RSystem,
            Menu,
            LBracket,
            RBracket,
            Semicolon,
            Comma,
            Period,
            Apostrophe,
            Slash,
            Backslash,
            Grave,
            Equal,
            Hyphen,
            Space,
            Enter,
            Backspace,
            Tab,
            PageUp,
            PageDown,
            End,
            Home,
            Insert,
            Delete,
            Add,
            Subtract,
            Multiply,
            Divide,
            Left,
            Right,
            Up,
            Down,
            Numpad0,
            Numpad1,
            Numpad2,
            Numpad3,
            Numpad4,
            Numpad5,
            Numpad6,
            Numpad7,
            Numpad8,
            Numpad9,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            Pause,
        };

        // NOLINTNEXTLINE(readability-identifier-naming)
        static constexpr unsigned int KeyCount{ static_cast<unsigned int>(Key::Pause) + 1 };

        enum class Scan
        {
            Unknown = -1,
            A = 0,
            B,
            C,
            D,
            E,
            F,
            G,
            H,
            I,
            J,
            K,
            L,
            M,
            N,
            O,
            P,
            Q,
            R,
            S,
            T,
            U,
            V,
            W,
            X,
            Y,
            Z,
            Num1,
            Num2,
            Num3,
            Num4,
            Num5,
            Num6,
            Num7,
            Num8,
            Num9,
            Num0,
            Enter,
            Escape,
            Backspace,
            Tab,
            Space,
            Hyphen,
            Equal,
            LBracket,
            RBracket,
            // For US keyboards mapped to key 29 (Microsoft Keyboard Scan Code Specification)
            // For Non-US keyboards mapped to key 42 (Microsoft Keyboard Scan Code Specification)
            // Typical language mappings: Belg:£µ` FrCa:<>} Dan:*' Dutch:`´ Fren:µ* Ger:'# Ital:§ù LatAm:[}` Nor:*@ Span:ç} Swed:*' Swiss:$£} UK:~# Brazil:}]
            Backslash,
            Semicolon,
            Apostrophe,
            Grave,
            Comma,
            Period,
            Slash,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            F16,
            F17,
            F18,
            F19,
            F20,
            F21,
            F22,
            F23,
            F24,
            CapsLock,
            PrintScreen,
            ScrollLock,
            Pause,
            Insert,
            Home,
            PageUp,
            Delete,
            End,
            PageDown,
            Right,
            Left,
            Down,
            Up,
            NumLock,
            NumpadDivide,
            NumpadMultiply,
            NumpadMinus,
            NumpadPlus,
            NumpadEqual,
            NumpadEnter,
            NumpadDecimal,
            Numpad1,
            Numpad2,
            Numpad3,
            Numpad4,
            Numpad5,
            Numpad6,
            Numpad7,
            Numpad8,
            Numpad9,
            Numpad0,
            // For US keyboards doesn't exist
            // For Non-US keyboards mapped to key 45 (Microsoft Keyboard Scan Code Specification)
            // Typical language mappings: Belg:<> FrCa:«°» Dan:<> Dutch:]|[ Fren:<> Ger:<|> Ital:<> LatAm:<> Nor:<> Span:<> Swed:<|> Swiss:<> UK:\| Brazil: \|.
            NonUsBackslash,
            Application,
            Execute,
            ModeChange,
            Help,
            Menu,
            Select,
            Redo,
            Undo,
            Cut,
            Copy,
            Paste,
            VolumeMute,
            VolumeUp,
            VolumeDown,
            MediaPlayPause,
            MediaStop,
            MediaNextTrack,
            MediaPreviousTrack,
            LControl,
            LShift,
            LAlt,
            LSystem,
            RControl,
            RShift,
            RAlt,
            RSystem,
            Back,
            Forward,
            Refresh,
            Stop,
            Search,
            Favorites,
            HomePage,
            LaunchApplication1,
            LaunchApplication2,
            LaunchMail,
            LaunchMediaSelect,
        };

        using Scancode = Scan;

        // NOLINTNEXTLINE(readability-identifier-naming)
        static constexpr unsigned int ScancodeCount{ static_cast<unsigned int>(Scan::LaunchMediaSelect) + 1 };

        [[nodiscard]] SFML_WINDOW_API bool isKeyPressed(Key key);

        [[nodiscard]] SFML_WINDOW_API bool isKeyPressed(Scancode code);

        [[nodiscard]] SFML_WINDOW_API Key localize(Scancode code);

        [[nodiscard]] SFML_WINDOW_API Scancode delocalize(Key key);

        [[nodiscard]] SFML_WINDOW_API String getDescription(Scancode code);

        SFML_WINDOW_API void setVirtualKeyboardVisible(bool visible);
    } // namespace Keyboard

} // namespace sf