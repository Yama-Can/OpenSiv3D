﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2017 Ryo Suzuki
//	Copyright (c) 2016-2017 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/Platform.hpp>
# if defined(SIV3D_TARGET_WINDOWS)

# include "../Siv3DEngine.hpp"
# include "../Window/IWindow.hpp"
# include "CMouse_Windows.hpp"

namespace s3d
{
	namespace detail
	{
		constexpr size_t buttonIndex[6] = { 1, 2, 4, 5, 6 };
	}

	CMouse_Windows::CMouse_Windows()
	{

	}

	CMouse_Windows::~CMouse_Windows()
	{

	}

	bool CMouse_Windows::init()
	{
		m_hWnd = Siv3DEngine::GetWindow()->getHandle();

		return true;
	}

	void CMouse_Windows::update()
	{
		if (!m_inputAttached)
		{
			::AttachThreadInput(::GetWindowThreadProcessId(m_hWnd, nullptr), ::GetCurrentThreadId(), TRUE);

			m_inputAttached = true;
		}

		uint8 buf[256] = {};

		if (::GetKeyboardState(buf))
		{
			for (size_t i = 0; i < std::size(detail::buttonIndex); ++i)
			{
				const bool pressed = (buf[detail::buttonIndex[i]] >> 7) & 0x1;

				m_states[i].update(pressed);
			}
		}

		{
			std::lock_guard<std::mutex> lock(m_scrollMutex);

			m_scroll = m_scrollInternal;

			m_scrollInternal.set(0.0, 0.0);
		}
	}

	bool CMouse_Windows::down(const uint32 index) const
	{
		return m_states[index].down;
	}

	bool CMouse_Windows::pressed(const uint32 index) const
	{
		return m_states[index].pressed;
	}

	bool CMouse_Windows::up(const uint32 index) const
	{
		return m_states[index].up;
	}

	MillisecondsF CMouse_Windows::pressedDuration(const uint32 index) const
	{
		return m_states[index].pressedDuration;
	}
	
	const Vec2& CMouse_Windows::wheel() const
	{
		return m_scroll;
	}
	
	void CMouse_Windows::onScroll(const double v, const double h)
	{
		std::lock_guard<std::mutex> lock(m_scrollMutex);
		
		m_scrollInternal.moveBy(v, h);
	}
}

# endif
