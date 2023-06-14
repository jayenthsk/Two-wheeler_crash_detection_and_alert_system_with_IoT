# Two-wheeler_crash_detection_and_alert_system_with_IoT
An IoT based system to detect two-wheeler accidents and alert the concerned authorities about the the same
The proposed Two-wheeler crash detection and alert system using IoT mainly focuses on detecting a two-wheeler accident and alerts
the rider’s contacts regarding the same. The mercury tilt sensor works in tandem with the accelerometer to detect a crash based on a
threshold defined in the tilt sensor and the impulse in the accelerometer. Once a crash is detected and confirmed, the system waits for
a fixed time interval, waiting for the rider to interrupt the system in case of false detection. If the rider fails to respond, the
latitude and longitude from the GPS module is sent to pre-defined contacts or emergency services. This helps in alerting the contacts of
the crash if he/she is unconscious or not stable to do so.

Architecture Block Diagram:

<img width="7420" alt="IOT_Architecture (4)" src="https://github.com/jayenthsk/Two-wheeler_crash_detection_and_alert_system_with_IoT/assets/115421663/3e6b024a-88bc-4eb9-8ba3-324caa339189">

1) Helmet Module
   Tilt Sensor: Monitors the tilt angle of the helmet.
   Buzzer: Provides an audible warning in case of potential accidents.
   Push Button Switch: Allows users to cancel false alarms.
   RF Transmitter: Sends signals wirelessly to the bike module.
   ![helmet_module](https://github.com/jayenthsk/Two-wheeler_crash_detection_and_alert_system_with_IoT/assets/115421663/ca63eed5-0410-4480-b529-5c86ca183ea2)

   

2) Bike Module
   MPU6050 Gyroscope: Measures the rotational movements of the bike.
   RF Receiver: Receives signals from the helmet module.
   GSM Module: Sends SMS alerts in case of accidents.
   ![bike_module](https://github.com/jayenthsk/Two-wheeler_crash_detection_and_alert_system_with_IoT/assets/115421663/1fddf039-d7a2-42c1-83ab-769d6e4e6c68)


Components Used

1) Arduino Uno: The Arduino Uno is a microcontroller board based on the CH340. It has 20 digital input/output pins (of which 6 can
be used as PWM outputs and 6 can be used as analog inputs), a 16 MHz resonator, a USB connection, a power jack, an in-circuit system
programming (ICSP) header, and a reset button.

2) ESP8266: The ESP8266 is a popular Wi-Fi microcontroller module used for IoT projects. It combines a microcontroller unit with
built-in Wi-Fi connectivity, allowing devices to connect to wireless networks and communicate with other devices or services.
ESP8266 is compact, affordable, and widely supported by various development environments, making it a versatile choice for IoT
applications.

3) Mercury Tilt Sensor: A mercury tilt sensor is a mechanical device used to detect changes in orientation or tilt. It consists of a
small glass tube containing mercury and contacts. When the sensor is tilted, the mercury flows, causing the contacts to close or open,
indicating a change in position.

4) MPU6050 Gyroscope: The MPU6050 is a popular IC that combines a three-axis gyroscope and a three-axis accelerometer in a
single package. The gyroscope component of the MPU6050 measures angular velocity around three axes (X, Y, and Z) and provides
accurate real-time data on rotational movements. The MPU6050's gyroscope offers high precision and sensitivity, allowing it to
detect even subtle rotational movements. It provides raw data in the form of analog signals or digital outputs, which can be further
processed to obtain orientation or motionrelated information.

5) Neo 6M GPS Module: The NEO-6M GPS sensor is a compact and affordable Global Positioning System (GPS) module commonly
used in various applications such as navigation systems, tracking devices, drones, and IoT projects. It utilizes the NEO-6M chipset,
which provides accurate positioning information by receiving signals from multiple satellites. The module communicates with a
microcontroller or a computer through serial communication (UART) and provides precise latitude, longitude, altitude, and time data.
It features a built-in antenna, making it a convenient choice for applications where space is limited. The NEO-6M GPS sensor is widely
popular due to its simplicity, reliability, and costeffectiveness, making it an excellent choice for location-based projects.

5) Rf Transmitter and Receiver: An RF (Radio Frequency) transmitter and receiver pair is a set of electronic components used for wireless
communication. They work together to transmit and receive data or signals over radio waves, allowing information to be transmitted
wirelessly between devices. The RF transmitter is responsible for converting electrical signals into radio waves for transmission.
It typically consists of a modulation circuit, an amplifier, and an antenna. The modulation circuit encodes the data or signals onto a
carrier wave, modifying its properties to represent the information being transmitted. The amplifier boosts the signal's power to ensure it
can reach the desired range, and the antenna broadcasts the modulated radio waves into the surrounding environment. the RF receiver is designed
to capture and demodulate the transmitted radio waves to retrieve the original data or signals. It comprises an antenna for capturing the
incoming radio waves, a demodulation circuit for extracting the encoded information, and a decoding circuit that converts the modulated
signals back into their original format.

5) Buzzer: A buzzer is an electronic component that produces audible sound signals or alerts. It is commonly used in various applications to
generate sound notifications, alarms, or indications.

6) Push Button: A push-button switch, is a simple electromechanical component that is commonly used to control electrical circuits. It is
designed to make or break an electrical connection temporarily when pressed and released. The basic construction of a pushbutton switch
consists of a spring-loaded button and electrical contacts. When the button is pressed, it moves against the force of the spring,
causing the electrical contacts to encounter each other. This closure of contacts allows electrical current to flow through the switch,
completing the circuit. When the button is released, the spring pushes it back to its original position, opening the contacts and breaking
the circuit.
