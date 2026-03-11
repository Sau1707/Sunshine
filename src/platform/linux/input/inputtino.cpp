/**
 * @file src/platform/linux/input/inputtino.cpp
 * @brief Definitions for the inputtino Linux input handling.
 */
// lib includes
#include <inputtino/input.hpp>
#include <libevdev/libevdev.h>
#include <string_view>

// local includes
#include "inputtino_common.h"
#include "inputtino_keyboard.h"
#include "inputtino_mouse.h"
#include "inputtino_pen.h"
#include "inputtino_touch.h"
#include "src/config.h"
#include "src/platform/common.h"
#include "src/utility.h"

using namespace std::literals;

namespace platf {
  namespace {
    std::vector<supported_gamepad_t> &disabled_gamepads() {
      static std::vector<supported_gamepad_t> gamepads {
        supported_gamepad_t {"disabled", false, "Controller support has been removed from this build"}
      };
      return gamepads;
    }

    void log_gamepad_disabled(std::string_view operation) {
      BOOST_LOG(debug) << operation << " ignored because controller support is disabled";
    }
  }  // namespace

  input_t input() {
    return {new input_raw_t()};
  }

  std::unique_ptr<client_input_t> allocate_client_input_context(input_t &input) {
    return std::make_unique<client_input_raw_t>(input);
  }

  void freeInput(void *p) {
    auto *input = (input_raw_t *) p;
    delete input;
  }

  void move_mouse(input_t &input, int deltaX, int deltaY) {
    auto raw = (input_raw_t *) input.get();
    platf::mouse::move(raw, deltaX, deltaY);
  }

  void abs_mouse(input_t &input, const touch_port_t &touch_port, float x, float y) {
    auto raw = (input_raw_t *) input.get();
    platf::mouse::move_abs(raw, touch_port, x, y);
  }

  void button_mouse(input_t &input, int button, bool release) {
    auto raw = (input_raw_t *) input.get();
    platf::mouse::button(raw, button, release);
  }

  void scroll(input_t &input, int high_res_distance) {
    auto raw = (input_raw_t *) input.get();
    platf::mouse::scroll(raw, high_res_distance);
  }

  void hscroll(input_t &input, int high_res_distance) {
    auto raw = (input_raw_t *) input.get();
    platf::mouse::hscroll(raw, high_res_distance);
  }

  void keyboard_update(input_t &input, uint16_t modcode, bool release, uint8_t flags) {
    auto raw = (input_raw_t *) input.get();
    platf::keyboard::update(raw, modcode, release, flags);
  }

  void unicode(input_t &input, char *utf8, int size) {
    auto raw = (input_raw_t *) input.get();
    platf::keyboard::unicode(raw, utf8, size);
  }

  void touch_update(client_input_t *input, const touch_port_t &touch_port, const touch_input_t &touch) {
    auto raw = (client_input_raw_t *) input;
    platf::touch::update(raw, touch_port, touch);
  }

  void pen_update(client_input_t *input, const touch_port_t &touch_port, const pen_input_t &pen) {
    auto raw = (client_input_raw_t *) input;
    platf::pen::update(raw, touch_port, pen);
  }

  int alloc_gamepad(input_t &input, const gamepad_id_t &id, const gamepad_arrival_t &metadata, feedback_queue_t feedback_queue) {
    (void) input;
    (void) id;
    (void) metadata;
    (void) feedback_queue;
    log_gamepad_disabled("alloc_gamepad"sv);
    return -1;
  }

  void free_gamepad(input_t &input, int nr) {
    (void) input;
    (void) nr;
    log_gamepad_disabled("free_gamepad"sv);
  }

  void gamepad_update(input_t &input, int nr, const gamepad_state_t &gamepad_state) {
    (void) input;
    (void) nr;
    (void) gamepad_state;
    log_gamepad_disabled("gamepad_update"sv);
  }

  void gamepad_touch(input_t &input, const gamepad_touch_t &touch) {
    (void) input;
    (void) touch;
    log_gamepad_disabled("gamepad_touch"sv);
  }

  void gamepad_motion(input_t &input, const gamepad_motion_t &motion) {
    (void) input;
    (void) motion;
    log_gamepad_disabled("gamepad_motion"sv);
  }

  void gamepad_battery(input_t &input, const gamepad_battery_t &battery) {
    (void) input;
    (void) battery;
    log_gamepad_disabled("gamepad_battery"sv);
  }

  platform_caps::caps_t get_capabilities() {
    platform_caps::caps_t caps = 0;
    // TODO: if has_uinput
    caps |= platform_caps::pen_touch;

    return caps;
  }

  util::point_t get_mouse_loc(input_t &input) {
    auto raw = (input_raw_t *) input.get();
    return platf::mouse::get_location(raw);
  }

  std::vector<supported_gamepad_t> &supported_gamepads(input_t *input) {
    (void) input;
    return disabled_gamepads();
  }
}  // namespace platf
