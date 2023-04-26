#include "XL320.h"
#include <SoftwareSerial.h>
#include <ros.h>
#include "std_msgs/UInt16MultiArray.h"
#include "parameters.h"

XL320 robot;
SoftwareSerial mySerial(RX, TX);

ros::NodeHandle nh;

void messageCb(const std_msgs::UInt16MultiArray& msg) {
    robot.setJointSpeed(left_motor, msg.data[0]);
    delay(10);
    robot.setJointSpeed(right_motor, msg.data[1]);
    delay(10);
    if (msg.data[2] == 1) {
        digitalWrite(magnetPin, HIGH);
    }else{
        digitalWrite(magnetPin, LOW);
    }
}

ros::Subscriber<std_msgs::UInt16MultiArray> sub("speed_array", &messageCb);

void setup() {
    mySerial.begin(baudrate);
    robot.begin(mySerial);
    pinMode(magnetPin, OUTPUT);
    digitalWrite(magnetPin, LOW);
    

    nh.getHardware()->setBaud(baudrate);
    nh.initNode();
    nh.subscribe(sub);
}

void loop() {
    nh.spinOnce();
    delay(1);
}
