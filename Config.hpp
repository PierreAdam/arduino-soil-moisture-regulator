// Hardware settings
#define PROBE_GPIO          4
#define MOTOR_GPIO          2
#define LED_RED_GPIO        27
#define LED_GREEN_GPIO      26
#define LED_BLUE_GPIO       25
#define BUTTON_GPIO         22

// Capacitive soil moisture sensor
#define SENSOR_MAX_VALUE    3200
#define SENSOR_MIN_VALUE    1400
#define SENSOR_ERROR_VALUE  1100
#define SENSOR_READ_REPEAT  10

// Behavior settings
#define MOTOR_START         30 // Motor start at 30% of the sensor capacitive value
#define MOTOR_STOP          40 // Motor stop at 40% of the sensor capacitive value
