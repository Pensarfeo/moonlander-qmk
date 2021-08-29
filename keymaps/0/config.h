/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 99

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 10

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 12

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 20

#define AUTO_SHIFT_TIMEOUT 99
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 10
#define COMBO_TERM 150
