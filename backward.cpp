// Pick your poison.
//
// On GNU/Linux, you have few choices to get the most out of your stack trace.
//
// By default you get:
//	- object filename
//	- function name
//
// In order to add:
//	- source filename
//	- line and column numbers
//	- source code snippet (assuming the file is accessible)

// Install one of the following libraries then uncomment one of the macro (or
// better, add the detection of the lib and the macro definition in your build
// system)

// - apt-get install libdw-dev ...
// - g++/clang++ -ldw ...
// #define BACKWARD_HAS_DW 1

// - apt-get install binutils-dev ...
// - g++/clang++ -lbfd ...
// #define BACKWARD_HAS_BFD 1

// - apt-get install libdwarf-dev ...
// - g++/clang++ -ldwarf ...
// #define BACKWARD_HAS_DWARF 1

// Regardless of the library you choose to read the debug information,
// for potentially more detailed stack traces you can use libunwind
// - apt-get install libunwind-dev
// - g++/clang++ -lunwind
// #define BACKWARD_HAS_LIBUNWIND 1

#include "backward.hpp"

#if defined(BACKWARD_SYSTEM_WINDOWS)
#include "color-console/color.hpp"
#endif // ndef BACKWARD_SYSTEM_WINDOWS

namespace backward {

backward::SignalHandling sh;

#if defined(BACKWARD_SYSTEM_WINDOWS)

void Colorize::set_color(Color::type ccode) {
  if (!_enabled)
    return;
  if (ccode == Color::yellow)
    _os << hue::yellow;
  else if (ccode == Color::purple)
    _os << hue::purple;
  else
    _os << hue::reset;
  _reset = ccode != Color::reset;
}

#endif // ndef BACKWARD_SYSTEM_WINDOWS

} // namespace backward
