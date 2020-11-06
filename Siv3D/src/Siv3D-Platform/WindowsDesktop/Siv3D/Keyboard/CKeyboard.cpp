﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2020 Ryo Suzuki
//	Copyright (c) 2016-2020 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/Common.hpp>
# include <Siv3D/EngineLog.hpp>
# include <Siv3D/UserAction.hpp>
# include <Siv3D/Window/IWindow.hpp>
# include <Siv3D/UserAction/IUserAction.hpp>
# include <Siv3D/Common/Siv3DEngine.hpp>
# include "CKeyboard.hpp"

namespace s3d
{
	namespace detail
	{
		[[nodiscard]]
		static String GetKeyName(const uint32 vk)
		{
			uint32 scanCode = ::MapVirtualKeyW(vk, MAPVK_VK_TO_VSC);

			if (scanCode)
			{
				switch (vk)
				{
				case VK_PRIOR:
				case VK_NEXT:
				case VK_END:
				case VK_HOME:
				case VK_LEFT:
				case VK_UP:
				case VK_RIGHT:
				case VK_DOWN:
				case VK_INSERT:
				case VK_DELETE:
				case VK_DIVIDE:
				case VK_NUMLOCK:
					scanCode |= 0x100;
					break;
				}
			}

			wchar_t buffer[128] = {};

			if (const int length = ::GetKeyNameTextW(static_cast<LPARAM>(scanCode << 16), buffer, _countof(buffer)))
			{
				return Unicode::FromWstring(std::wstring_view{ buffer, static_cast<size_t>(length) });
			}
			else
			{
				return U"{:#04x}"_fmt(vk);
			}
		}
	}

	CKeyboard::CKeyboard()
	{

	}

	CKeyboard::~CKeyboard()
	{
		LOG_SCOPED_TRACE(U"CKeyboard::~CKeyboard()");
	}

	void CKeyboard::init()
	{
		LOG_SCOPED_TRACE(U"CKeyboard::init()");

		m_hWnd = static_cast<HWND>(SIV3D_ENGINE(Window)->getHandle());

		for (uint32 vk = 0; vk < m_names.size(); ++vk)
		{
			m_names[vk] = detail::GetKeyName(vk);
		}
	}

	void CKeyboard::update()
	{
		if (not m_inputAttached)
		{
			if (not ::AttachThreadInput(::GetWindowThreadProcessId(m_hWnd, nullptr), ::GetCurrentThreadId(), TRUE))
			{
				LOG_ERROR(U"✖ AttachThreadInput() failed");
			}

			m_inputAttached = true;
		}

		m_allInputs.clear();

		if (uint8 buf[256] = {}; 
			::GetKeyboardState(buf))
		{
			static_assert(InputState::KeyCount == _countof(buf));

			for (size_t i = 0; i < _countof(buf); ++i)
			{
				const bool pressed = ((buf[i] >> 7) & 0x1);

				m_states[i].update(pressed);

				if (pressed && InRange<size_t>(i, VK_BACK, 0xEF))
				{
					m_allInputs.emplace_back(InputDeviceType::Keyboard, static_cast<uint8>(i));
				}
			}
		}

		{
			if (m_states[VK_ESCAPE].down)
			{
				SIV3D_ENGINE(UserAction)->reportUserActions(UserAction::AnyKeyDown | UserAction::EscapeKeyDown);
			}
			else if (m_allInputs)
			{
				SIV3D_ENGINE(UserAction)->reportUserActions(UserAction::AnyKeyDown);
			}

			for (uint32 vk = VK_LBUTTON; vk <= VK_XBUTTON2; ++vk)
			{
				if (m_states[vk].down)
				{
					SIV3D_ENGINE(UserAction)->reportUserActions(UserAction::MouseButtonDown);
					break;
				}
			}
		}
	}

	bool CKeyboard::down(const uint32 index) const
	{
		assert(index < InputState::KeyCount);
		return m_states[index].down;
	}

	bool CKeyboard::pressed(const uint32 index) const
	{
		assert(index < InputState::KeyCount);
		return m_states[index].pressed;
	}

	bool CKeyboard::up(const uint32 index) const
	{
		assert(index < InputState::KeyCount);
		return m_states[index].up;
	}

	Duration CKeyboard::pressedDuration(const uint32 index) const
	{
		assert(index < InputState::KeyCount);
		return m_states[index].pressedDuration;
	}

	const String& CKeyboard::name(const uint32 index) const
	{
		assert(index < InputState::KeyCount);
		return m_names[index];
	}

	const Array<Input>& CKeyboard::getAllInput() const noexcept
	{
		return m_allInputs;
	}
}
