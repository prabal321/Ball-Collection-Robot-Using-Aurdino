Ball Collection Robot

Project Description
This project demonstrates an autonomous Ball Collection Robot capable of detecting, approaching, and collecting a ball using an IR sensor, ultrasonic sensor, DC motors, and a gripper mechanism. The robot is programmed using Arduino IDE, with the L298D motor driver controlling the wheels and a servo motor operating the gripper. The robot rotates to search for a ball, measures the distance using ultrasonic sensors, moves towards the ball, and finally grips it.

Code Explanation
Working Principle
1. IR Sensor Detection: The robot rotates until the IR sensor detects a ball.
2. Ultrasonic Distance Measurement: Once detected, the ultrasonic sensor measures the distance to the ball.
3. Approaching the Ball: Based on the distance, the robot moves forward until it reaches the ball.
4. Gripping the Ball: The gripper mechanism, controlled by a servo motor, grips the ball securely.

Features:
- Rotation: The robot rotates using DC motors to detect the ball.
- Distance Calculation: Uses the ultrasonic sensor for precise ball location.
- Control: L298D motor driver handles the motors.
- Gripper Mechanism: A servo motor controls the opening and closing of the gripper.

Execution Steps
Hardware Requirements
1. Arduino Uno Board
2. L298D Motor Driver
3. DC Motors (4)
4. Servo Motor (for Gripper)
5. IR Sensor
6. Ultrasonic Sensor (HC-SR04)
7. Power Supply:
   - 7.4V or 9V battery for motors (connected to the motor driver’s VIN pin).
   - Arduino powered via USB or external 5V supply.
8. Connections:
   - IR Sensor: D2
   - Ultrasonic Sensor: Trig (D6), Echo (D7)
   - Motor Driver:
     - IN1 (D3), IN2 (D4) for Left Motor
     - IN3 (D5), IN4 (D8) for Right Motor
     - ENA (D10), ENB (D11) for motor speed
   - Servo Motor: Signal pin to D9, power and ground to Arduino.

Software Requirements
1. Install Arduino IDE on your computer.
2. Import the Servo.h library (included by default in Arduino IDE).
3. Load the provided Arduino code into the IDE.
4. Compile and upload the code to the Arduino Uno board.

How to Execute
1. Prepare the Hardware:
   - Ensure proper wiring of all components as per the connections specified above.
   - Attach a power source to the motor driver and Arduino.
2. Load the Code:
   - Open the Arduino IDE, paste the code, and upload it to the Arduino.
3. Run the Robot:
   - Place a ball within the detection range of the IR sensor.
   - Power the robot, and it will start rotating to find the ball.
   - Once detected, it will approach and collect the ball using the gripper.

Notes
- Ensure the batteries are fully charged for optimal performance.
- Test each component individually to ensure proper functioning before full integration.
- Use a smooth surface for better movement and ball collection.
