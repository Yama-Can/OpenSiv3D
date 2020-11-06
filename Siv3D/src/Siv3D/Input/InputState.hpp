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

# pragma once
# include <Siv3D/Common.hpp>
# include <Siv3D/Stopwatch.hpp>

namespace s3d
{
	struct InputState
	{
		static constexpr size_t KeyCount = 256;

		Duration pressedDuration{ 0 };

		Stopwatch stopwatch;

		bool up = false;

		bool pressed = false;

		bool down = false;

		void update(bool currentPressed);

		void clear();
	};
}
