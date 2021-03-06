#include "SuplaTemplateBoard.h"
#include "SuplaWebPageRelay.h"
#include <supla/events.h>

void chooseTemplateBoard(uint8_t board) {
  switch (board) {
    case BOARD_ELECTRODRAGON:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(16, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "2");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);
      ConfigESP->setGpio(2, 2, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "2");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(13, 2, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_INCAN3:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(2, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "2");
      ConfigESP->setGpio(14, 1, FUNCTION_BUTTON, Supla::ON_CHANGE);
      ConfigESP->setGpio(12, 2, FUNCTION_BUTTON, Supla::ON_CHANGE);

      ConfigManager->set(KEY_MAX_RELAY, "2");
      ConfigESP->setGpio(5, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(13, 2, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);

      ConfigManager->set(KEY_MAX_LIMIT_SWITCH, "2");
      ConfigESP->setGpio(4, 1, FUNCTION_LIMIT_SWITCH, 0);
      ConfigESP->setGpio(16, 2, FUNCTION_LIMIT_SWITCH, 0);
      break;
    case BOARD_MELINK:
      ConfigESP->setGpio(5, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(12, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(5, 1, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(4, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_NEO_COOLCAM:
      ConfigESP->setGpio(13, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(4, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(13, 1, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SHELLY1:
      ConfigESP->setGpio(5, FUNCTION_CFG_BUTTON);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(5, 1, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(4, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SHELLY2:
      ConfigESP->setGpio(12, FUNCTION_CFG_BUTTON);

      ConfigManager->set(KEY_MAX_BUTTON, "2");
      ConfigESP->setGpio(12, 1, FUNCTION_BUTTON, Supla::ON_PRESS);
      ConfigESP->setGpio(14, 2, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "2");
      ConfigESP->setGpio(4, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(5, 2, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SONOFF_BASIC:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SONOFF_DUAL_R2:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "2");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);
      ConfigESP->setGpio(9, 2, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "2");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(5, 2, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SONOFF_S2X:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);

      ConfigESP->setGpio(14, FUNCTION_SI7021_SONOFF);
      break;
    case BOARD_SONOFF_TH:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);

      ConfigESP->setGpio(14, FUNCTION_SI7021_SONOFF);
      break;
    case BOARD_SONOFF_TOUCH:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SONOFF_TOUCH_2CH:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "2");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);
      ConfigESP->setGpio(9, 2, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "2");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(5, 2, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SONOFF_TOUCH_3CH:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "3");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_PRESS);
      ConfigESP->setGpio(9, 2, FUNCTION_BUTTON, Supla::ON_PRESS);
      ConfigESP->setGpio(10, 3, FUNCTION_BUTTON, Supla::ON_PRESS);

      ConfigManager->set(KEY_MAX_RELAY, "3");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(5, 2, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(4, 3, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;
    case BOARD_SONOFF_4CH:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(13, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "4");
      ConfigESP->setGpio(0, 1, FUNCTION_BUTTON, Supla::ON_CHANGE);
      ConfigESP->setGpio(9, 2, FUNCTION_BUTTON, Supla::ON_CHANGE);
      ConfigESP->setGpio(10, 3, FUNCTION_BUTTON, Supla::ON_CHANGE);
      ConfigESP->setGpio(14, 4, FUNCTION_BUTTON, Supla::ON_CHANGE);

      ConfigManager->set(KEY_MAX_RELAY, "4");
      ConfigESP->setGpio(12, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(5, 2, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(4, 3, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      ConfigESP->setGpio(15, 4, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);

      break;
    case BOARD_YUNSHAN:
      ConfigESP->setGpio(0, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(2, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(3, 1, FUNCTION_BUTTON, Supla::ON_CHANGE);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(4, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;

    case BOARD_YUNTONG_SMART:
      ConfigESP->setGpio(12, FUNCTION_CFG_BUTTON);
      ConfigESP->setGpio(15, FUNCTION_CFG_LED, HIGH);

      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigESP->setGpio(12, 1, FUNCTION_BUTTON, Supla::ON_CHANGE);

      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigESP->setGpio(4, 1, FUNCTION_RELAY, HIGH, MEMORY_RELAY_RESTORE);
      break;

    default:
      ConfigManager->set(KEY_MAX_BUTTON, "1");
      ConfigManager->set(KEY_MAX_RELAY, "1");
      ConfigManager->set(KEY_MAX_LIMIT_SWITCH, "0");
      break;
  }
}
