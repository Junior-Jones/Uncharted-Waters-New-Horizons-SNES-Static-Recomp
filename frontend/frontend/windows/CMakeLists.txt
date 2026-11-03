cmake_minimum_required(VERSION 3.20)
project(NewHorizonsWindowsFrontend LANGUAGES C CXX)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

get_filename_component(NEW_HORIZONS_FRONTEND_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
get_filename_component(NEW_HORIZONS_SOURCE_ROOT "${NEW_HORIZONS_FRONTEND_ROOT}/.." ABSOLUTE)
set(NEW_HORIZONS_GAMEPAD_ADAPTER_DIR "${NEW_HORIZONS_FRONTEND_ROOT}/third_party/new_horizons-gamepad")

if(NOT TARGET uncharted_waters_static_core)
  add_subdirectory("${NEW_HORIZONS_SOURCE_ROOT}" "${CMAKE_BINARY_DIR}/static-core" EXCLUDE_FROM_ALL)
endif()

set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
set(NEW_HORIZONS_SDL_SOURCE_DIR "" CACHE PATH
  "Local SDL 3 source tree; this build never downloads dependencies")
if(NOT EXISTS "${NEW_HORIZONS_SDL_SOURCE_DIR}/CMakeLists.txt")
  message(FATAL_ERROR
    "Set NEW_HORIZONS_SDL_SOURCE_DIR to an existing local SDL 3 source tree")
endif()
add_subdirectory("${NEW_HORIZONS_SDL_SOURCE_DIR}"
                 "${CMAKE_BINARY_DIR}/sdl" EXCLUDE_FROM_ALL)

add_executable(new-horizons-launcher WIN32
  new_horizons_launcher_win32.c
  new_horizons_app_core.c
  launcher_version.rc
  new_horizons_audio_output_dsound_win32.c
  new_horizons_audio_resampler.c
  new_horizons_frontend_settings_win32.c
  ../common/new_horizons_input_latch.c
  "${NEW_HORIZONS_GAMEPAD_ADAPTER_DIR}/new_horizons_gamepad_input_win32.c"
)

option(NH_FRONTEND_BUILD_CONTRACT_TESTS
  "Build the copied frontend contract executables" OFF)
if(NH_FRONTEND_BUILD_CONTRACT_TESTS)
add_executable(new-horizons-frontend-core-test
  new_horizons_frontend_core_test.c
  new_horizons_app_core.c
)
target_include_directories(new-horizons-frontend-core-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${NEW_HORIZONS_SOURCE_ROOT}/static-core/include"
)
target_link_libraries(new-horizons-frontend-core-test PRIVATE uncharted_waters_static_core)
target_compile_definitions(new-horizons-frontend-core-test PRIVATE
  _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(new-horizons-frontend-core-test PRIVATE /W4 /WX)
else()
  target_compile_options(new-horizons-frontend-core-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
enable_testing()
add_test(NAME new_horizons_frontend_core_reset COMMAND new-horizons-frontend-core-test)

add_executable(new-horizons-input-contract-test
  ../common/new_horizons_input_contract_test.c
  ../common/new_horizons_input_latch.c
)
target_include_directories(new-horizons-input-contract-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${NEW_HORIZONS_SOURCE_ROOT}/static-core/include"
)
target_link_libraries(new-horizons-input-contract-test PRIVATE uncharted_waters_static_core)
if(MSVC)
  target_compile_options(new-horizons-input-contract-test PRIVATE /W4 /WX)
else()
  target_compile_options(new-horizons-input-contract-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME new_horizons_input_contract COMMAND new-horizons-input-contract-test)

add_executable(new-horizons-settings-input-contract-test
  new_horizons_settings_input_contract_test.c
  new_horizons_frontend_settings_win32.c
  "${NEW_HORIZONS_GAMEPAD_ADAPTER_DIR}/new_horizons_gamepad_input_win32.c"
)
target_include_directories(new-horizons-settings-input-contract-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${NEW_HORIZONS_SOURCE_ROOT}/static-core/include"
  "${NEW_HORIZONS_GAMEPAD_ADAPTER_DIR}"
)
target_link_libraries(new-horizons-settings-input-contract-test PRIVATE
  uncharted_waters_static_core SDL3::SDL3-static user32 comctl32
)
target_compile_definitions(new-horizons-settings-input-contract-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(new-horizons-settings-input-contract-test PRIVATE /W4 /WX)
else()
  target_compile_options(new-horizons-settings-input-contract-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME new_horizons_settings_input_contract
  COMMAND new-horizons-settings-input-contract-test)

add_executable(new-horizons-audio-resampler-test
  new_horizons_audio_resampler_test.c
  new_horizons_audio_resampler.c
)
target_include_directories(new-horizons-audio-resampler-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
)
if(MSVC)
  target_compile_options(new-horizons-audio-resampler-test PRIVATE /W4 /WX)
else()
  target_compile_options(new-horizons-audio-resampler-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME new_horizons_audio_resampler COMMAND new-horizons-audio-resampler-test)

add_executable(new-horizons-audio-settings-contract-test
  new_horizons_audio_settings_contract_test.c
  new_horizons_audio_output_dsound_win32.c
  new_horizons_audio_resampler.c
  new_horizons_app_core.c
)
target_include_directories(new-horizons-audio-settings-contract-test PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${NEW_HORIZONS_SOURCE_ROOT}/static-core/include"
)
target_link_libraries(new-horizons-audio-settings-contract-test PRIVATE
  uncharted_waters_static_core user32 dsound dxguid winmm
)
target_compile_definitions(new-horizons-audio-settings-contract-test PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(new-horizons-audio-settings-contract-test PRIVATE /W4 /WX)
else()
  target_compile_options(new-horizons-audio-settings-contract-test PRIVATE
    -Wall -Wextra -Wpedantic
  )
endif()
add_test(NAME new_horizons_audio_settings_contract
  COMMAND new-horizons-audio-settings-contract-test)
endif()
target_include_directories(new-horizons-launcher PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}"
  "${CMAKE_CURRENT_LIST_DIR}/../common"
  "${NEW_HORIZONS_SOURCE_ROOT}/static-core/include"
  "${NEW_HORIZONS_GAMEPAD_ADAPTER_DIR}"
)
target_link_libraries(new-horizons-launcher PRIVATE
  uncharted_waters_static_core SDL3::SDL3-static
  user32 gdi32 comdlg32 comctl32 shell32 dsound dxguid winmm
)
target_compile_definitions(new-horizons-launcher PRIVATE
  UNICODE _UNICODE WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS
)
if(MSVC)
  target_compile_options(new-horizons-launcher PRIVATE
    /W4 /WX /experimental:deterministic
  )
  target_link_options(new-horizons-launcher PRIVATE
    $<$<CONFIG:Release>:/Brepro>
  )
else()
  target_compile_options(new-horizons-launcher PRIVATE
    -Wall -Wextra -Wpedantic
  )
  target_link_options(new-horizons-launcher PRIVATE -municode -static -static-libgcc -static-libstdc++)
endif()
set_target_properties(new-horizons-launcher PROPERTIES
  OUTPUT_NAME "Launcher"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/release"
)
add_custom_command(TARGET new-horizons-launcher POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:new-horizons-launcher>/Rom"
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:new-horizons-launcher>/Saves"
  COMMAND "${CMAKE_COMMAND}" -E make_directory
    "$<TARGET_FILE_DIR:new-horizons-launcher>/Screenshots"
  COMMAND "${CMAKE_COMMAND}" -E copy_if_different
    "${NEW_HORIZONS_FRONTEND_ROOT}/licenses/SDL-LICENSE.txt"
    "$<TARGET_FILE_DIR:new-horizons-launcher>/SDL-LICENSE.txt"
  VERBATIM
)
