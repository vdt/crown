/*
 * Copyright (c) 2012-2016 Daniele Bartolini and individual contributors.
 * License: https://github.com/taylor001/crown/blob/master/LICENSE
 */

#pragma once

#include "types.h"
#include "config.h"

#if CROWN_PLATFORM_ANDROID
 	#include <sys/types.h> // off_t
	#include <android/asset_manager.h>
#endif // CROWN_PLATFORM_ANDROID

namespace crown
{

/// Holds device options.
///
/// @ingroup Device
class DeviceOptions
{
	int _argc;
	char** _argv;
	const char* _source_dir;
	const char* _bundle_dir;
	const char* _boot_dir;
	const char* _platform;
	bool _wait_console;
	bool _do_compile;
	bool _do_continue;
	uint32_t _parent_window;
	uint16_t _console_port;
	uint16_t _window_x;
	uint16_t _window_y;
	uint16_t _window_width;
	uint16_t _window_height;

#if CROWN_PLATFORM_ANDROID
	AAssetManager* _asset_manager;
#endif // CROWN_PLATFORM_ANDROID

public:

	DeviceOptions(int argc, char** argv);

	/// Parses the command line and returns
	/// EXIT_SUCCESS if no error is found.
	int parse();

	int argc() const { return _argc; }
	const char** argv() const { return (const char**)_argv; }
	const char* source_dir() const { return _source_dir; }
	const char* bundle_dir() const { return _bundle_dir; }
	const char* boot_dir() const { return _boot_dir; }
	const char* platform() const { return _platform; }
	bool wait_console() const { return _wait_console; }
	bool do_compile() const { return _do_compile; }
	bool do_continue() const { return _do_continue; }
	uint32_t parent_window() const { return _parent_window; }
	uint16_t console_port() const { return _console_port; }
	uint16_t window_x() const { return _window_x; }
	uint16_t window_y() const { return _window_y; }
	uint16_t window_width() const { return _window_width; }
	uint16_t window_height() const { return _window_height; }

#if CROWN_PLATFORM_ANDROID
	void set_asset_manager(AAssetManager* am) { _asset_manager = am; }
	const AAssetManager* asset_manager() const { return _asset_manager; }
#endif // CROWN_PLATFORM_ANDROID
};

} // namespace crown