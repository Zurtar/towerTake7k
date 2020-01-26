#include "main.h"

#include "kari/control/chassis.h"
#include "kari/control/rack.h"
#include "kari/control/arm.h"

#include "kari/util/odometry.h"
#include "kari/util/misc.h"
#include "kari/util/vision.h"

static Chassis chassis;
static Rack rack;
static Arm arm;
static Odometry odom;

using namespace io;

/*===========================================
  DICTIONARY
===========================================*/
// IDLE = 0
// DRIVING_POINT = 1
// DRIVING_DIST = 2
// TURNING = 3
// STRAFING = 4

void tester() {
  odom.reset(0);
  chassis.lock();
  chassis.tareGyro();
arm.move(ARM_LOW_TOWER, 127).withTol(0.5).waitUntilSettled();
  arm.zero();
  delay(200);
roller(127);
    chassis.drive(1000, 50,1).withGyro(0).withTol(70).waitUntilSettled();
    arm.move(0.25, 127).withTol(0);
    delay(400);
    chassis.drive(400, 50,3).withGyro(0).withTol(30).waitUntilSettled();
    delay(200);
    arm.zero();
    delay(200);
    chassis.drive(500, 45,3).withGyro(45).withTol(30).waitUntilSettled();
    rack.move(1000, 127);
    chassis.turn(100, 80).withoutOdom().withTol(10).waitUntilSettled();
    chassis.smartstrafe(90,  180, 60,100,5,3);
    delay(2000);
    chassis.setMode(IDLE);
    chassis.drive(1100, 55,3).withGyro(180).withTol(30).waitUntilSettled();
    chassis.turn(135, 50,3).withoutOdom().withTol(10).waitUntilSettled();
    chassis.left(60);
    chassis.right(60);
    rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
    roller(-0.2,80);
    delay(500);

    chassis.left(60);
    chassis.right(50);
    delay(400);
    chassis.left(30);
    chassis.right(20);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(35);

    roller(-70);
    chassis.lock();
    chassis.drive(-350,127,2).withConst(0.2).withTol(50).waitUntilSettled();

    delay(10000);

    delay(200);
  io::master.rumble(" .");
}

/*===========================================
  PREMADE FUNCTIONS
===========================================*/
void deploy() {
  arm.move(ARM_LOW_TOWER, 127).withTol(0.3).waitUntilSettled();
  arm.zero();
}

/*===========================================
  RED MATCH AUTONOMOUSES
===========================================*/
void redsmallzone9() {
  odom.reset(0);
  chassis.tareGyro();
arm.move(ARM_LOW_TOWER, 127).withTol(0.5).waitUntilSettled();
  arm.zero();

    chassis.drive({1220,0}, 68,1).withTol(70);
    delay(200);
    roller(127);
    chassis.waitUntilSettled();
chassis.withPoint({1450, 0}, 50, 4).withPoint({1798, 90}, 40, 2).withTol(25).drive().waitUntilSettled();
chassis.smartstrafe(270, 180,70,100,1,5);
delay(2500);
chassis.setMode(IDLE);
chassis.drive(500,80,6).withGyro(180).withConst(0.9, 0.3, 1.5,0.3).withTol(10).waitUntilSettled();
chassis.drive(1000,80,6).withGyro(100).withConst(0.9, 0.3, 1.5,0.3).withTol(10).waitUntilSettled();

    chassis.smartstrafe(180,  90, 60,60,1,5);
    delay(400);
    rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
    delay(300);
    chassis.setMode(IDLE);;

    chassis.left(60);
    chassis.right(50);
    roller(-0.4,80);
    delay(400);
    chassis.left(30);
    chassis.right(20);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(35);

    roller(-70);
    chassis.lock();
    chassis.drive(-350,127,2).withConst(0.2).withTol(50).waitUntilSettled();


}

void redsmallzone8() {
  odom.reset(0);
  chassis.lock();
  chassis.tareGyro();
arm.move(ARM_LOW_TOWER, 127).withTol(0.5).waitUntilSettled();
  arm.zero();
  delay(200);
roller(127);
    chassis.drive(1000, 50,1).withGyro(0).withTol(70).waitUntilSettled();
    arm.move(0.25, 127).withTol(0);
    delay(400);
    chassis.drive(400, 60,3).withGyro(0).withTol(30).waitUntilSettled();
    delay(200);
    arm.zero();
    delay(200);
    roller(127);
    chassis.waitUntilSettled();

    chassis.drive({300,-1000}, 127,4,true).withConst(1.1).withTol(100).waitUntilSettled();
    roller(127);
    chassis.turn({1300,-1000}, 127,8).withTol(10).waitUntilSettled();
    chassis.drive({1500,-1000}, 45,6).withTol(200).waitUntilSettled();

    chassis.drive({150,-900}, 127,6,true).withConst(0.3).withTol(150).waitUntilSettled();
    chassis.left(0);
    chassis.right(0);
    chassis.turn(90, 127,8).withoutOdom().withTol(15).waitUntilSettled();
        LF.move(127);
        LB.move(-127);
        RF.move(127);
        RB.move(-127);
        delay(200);
        rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
        delay(500);

        chassis.smartstrafe(100, 90,70,0,5);
        chassis.right(60);
        roller(-0.4,20);
        delay(600);
         chassis.setMode(IDLE);
        chassis.left(30);
        chassis.right(30);
        rack.waitUntilSettled();
        rack.move(RACK_DOWN,127,8).withTol(30);

        roller(-70);
        chassis.lock();
        chassis.drive(-350,127,2).withConst(0.2).withTol(50).waitUntilSettled();
}

void redsmallzone5() {
  chassis.lock();
  deploy();
  delay(200);
    chassis.drive({1420,0}, 60,4).withTol(70);
    delay(400);
    roller(127);
    chassis.waitUntilSettled();

    chassis.drive({300,100}, 100,4,true).withConst(0.1).withTol(100).waitUntilSettled();
    chassis.turn(270, 85,4).withTol(30).waitUntilSettled();
    LF.move(100);
    LB.move(-100);
    RF.move(100);
    RB.move(-100);
    delay(1200);

    chassis.left(50);
    chassis.right(50);
    rack.move(RACK_UP,127,5).withTol(20);
    roller(-0.4,50);


    delay(800);
    chassis.left(30);
    chassis.right(30);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(20);

    roller(-70);
    chassis.lock();
    chassis.drive(-500, 60, 10).withTol(60).waitUntilSettled();

}

void redbigzone() {
  chassis.lock();
  arm.move(ARM_LOW_TOWER, 127).waitUntilSettled();
  arm.zero().waitUntilSettled();
    roller(127);
    chassis.withPoint({206,0}, 60,4).
    withPoint({450,-327}, 60,4).
    withPoint({1400,-900}, 60,4).
    withPoint({1600,900}, 60,4).withTol(60).drive().waitUntilSettled();

}

void redbigzonescore() {
  chassis.lock();
  arm.move(ARM_LOW_TOWER, 127).waitUntilSettled();
  arm.zero().waitUntilSettled();
    roller(127);
    chassis.withPoint({206,0}, 100,4).
    withPoint({450,-327}, 70,4).
    withPoint({1400,-900}, 60,4).
    withPoint({1600,900}, 80,4).withTol(60).drive().waitUntilSettled();
    chassis.drive({120,300}, 127,4,true).withTol(150).waitUntilSettled();
    chassis.turn(90, 127,4).withTol(15).waitUntilSettled();
    LF.move(-127);
    LB.move(127);
    RF.move(-127);
    RB.move(127);
    delay(700);
    chassis.drive(400,127,8).withTol(70).withConst(2);
    delay(100);
    rack.move(RACK_UP,127,8).withTol(20);
    delay(300);
    chassis.waitUntilSettled();
    chassis.left(40);
    chassis.right(40);
    roller(-0.6,50);



    delay(1000);
    chassis.left(10);
    chassis.right(10);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(20);

    roller(-70);
    chassis.lock();
    chassis.drive(-500, 60, 10).withTol(60).waitUntilSettled();



}

/*===========================================
  BLUE MATCH AUTONOMOUSES
===========================================*/
void bluesmallzone9() {
  odom.reset(0);
  chassis.tareGyro();
arm.move(ARM_LOW_TOWER, 127).withTol(0.5).waitUntilSettled();
  arm.zero();

    chassis.drive({1220,0}, 68,1).withTol(70);
    delay(200);
    roller(127);
    chassis.waitUntilSettled();

    chassis.drive({150,1000}, 127,4,true).withConst(1.1).withTol(100).waitUntilSettled();
    roller(127);
    chassis.turn({1300,1000}, 127,8).withTol(10).waitUntilSettled();
    chassis.drive({1200,1000}, 50,6).withPoint({1980,700}, 50,4).withTol(200).drive().waitUntilSettled();

    chassis.drive({130,900}, 127,6,true).withConst(0.3).withTol(150).waitUntilSettled();
    chassis.left(0);
    chassis.right(0);
    chassis.turn(270, 80,8).withoutOdom().withTol(15).waitUntilSettled();
    LF.move(-127);
    LB.move(127);
    RF.move(-127);
    RB.move(127);
    rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
    delay(700);

    chassis.left(50);
    chassis.right(60);
    roller(-0.4,80);
    delay(400);
    chassis.left(20);
    chassis.right(30);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(35);

    roller(-70);
    chassis.lock();
    chassis.drive(-350,127,2).withConst(0.2).withTol(50).waitUntilSettled();


}

void bluesmallzone8() {
  odom.reset(0);
  chassis.tareGyro();
arm.move(ARM_LOW_TOWER, 127).withTol(0.5).waitUntilSettled();
  arm.zero();

    chassis.drive({1220,0}, 65,1).withTol(70);
    delay(200);
    roller(127);
    chassis.waitUntilSettled();

    chassis.drive({150,1000}, 127,4,true).withConst(1.1).withTol(100).waitUntilSettled();
    roller(127);
    chassis.turn({1300,1000}, 127,8).withTol(10).waitUntilSettled();
    chassis.drive({1300,1000}, 45,6).withTol(200).waitUntilSettled();

    chassis.drive({130,900}, 127,6,true).withConst(0.3).withTol(150).waitUntilSettled();
    chassis.left(0);
    chassis.right(0);
    chassis.turn(270, 127,8).withoutOdom().withTol(15).waitUntilSettled();
    LF.move(-127);
    LB.move(127);
    RF.move(-127);
    RB.move(127);
    delay(100);
    rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
    delay(500);

    chassis.left(50);
    chassis.right(50);
    roller(-0.4,20);
    delay(400);
    chassis.left(30);
    chassis.right(30);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(30);

    roller(-70);
    chassis.lock();
    chassis.drive(-350,127,2).withConst(0.2).withTol(50).waitUntilSettled();
}

void bluesmallzone5() {

  odom.reset(0);
  chassis.tareGyro();
arm.move(ARM_LOW_TOWER, 127).withTol(0.5).waitUntilSettled();
  arm.zero();

    chassis.drive({1420,0}, 55,1).withTol(70);
    delay(200);
    roller(127);

    chassis.waitUntilSettled();

    chassis.drive({150,-100}, 100,4,true).withConst(0.1).withTol(100).waitUntilSettled();
    chassis.turn(90, 85,4).withTol(30).waitUntilSettled();
    LF.move(-100);
    LB.move(100);
    RF.move(-100);
    RB.move(100);
    delay(700);

    chassis.left(50);
    chassis.right(50);
    rack.move(RACK_UP,127,5).withTol(20);
    roller(-0.4,50);


    delay(800);
    chassis.left(30);
    chassis.right(30);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(20);

    roller(-70);
    chassis.lock();
    chassis.drive(-500, 60, 10).withTol(60).waitUntilSettled();

}

void bluebigzone() {
  chassis.lock();
  arm.move(ARM_LOW_TOWER, 127).waitUntilSettled();
  arm.zero().waitUntilSettled();
    roller(127);
    chassis.withPoint({206,0}, 60,4).
    withPoint({450,327}, 60,4).
    withPoint({1400,900}, 60,4).
    withPoint({1600,-900}, 60,4).withTol(60).drive().waitUntilSettled();

}

void bluebigzonescore() {
  chassis.lock();
  arm.move(ARM_LOW_TOWER, 127).waitUntilSettled();
  arm.zero().waitUntilSettled();
    roller(127);
    chassis.withPoint({206,0}, 100,4).
    withPoint({450,327}, 70,4).
    withPoint({1400,900}, 60,4).
    withPoint({1600,-900}, 80,4).withTol(60).drive().waitUntilSettled();
    chassis.drive({120,-300}, 127,4,true).withTol(150).waitUntilSettled();
    chassis.turn(270, 127,4).withTol(15).waitUntilSettled();
    LF.move(127);
    LB.move(-127);
    RF.move(127);
    RB.move(-127);
    delay(700);
    chassis.drive(400,127,8).withTol(70).withConst(2);
    delay(100);
    rack.move(RACK_UP,127,8).withTol(20);
    delay(300);
    chassis.waitUntilSettled();
    chassis.left(40);
    chassis.right(40);
    roller(-0.6,50);



    delay(1000);
    chassis.left(10);
    chassis.right(10);
    rack.waitUntilSettled();
    rack.move(RACK_DOWN,127,8).withTol(20);

    roller(-70);
    chassis.lock();
    chassis.drive(-500, 60, 10).withTol(60).waitUntilSettled();


}

/*===========================================
  SKILLS AUTONOMOUSES
===========================================*/
void skills1() {

  arm.move(1.05, 127);
  chassis.lock();
  chassis.withPoint({50, 0}, 30, 5)
          .withPoint({700, -535}, 60, 5)
          .withConst(2).withTol(100).drive().waitUntilSettled();
  //deploy, drive to tower

  arm.waitUntilSettled();
  roller(-60);
  delay(600);
  //score red tower

  roller(127);
  chassis.drive({100, 0}, 80, 6, true).withTol(60);
  delay(200);
  arm.zero().waitUntilSettled();
  chassis.waitUntilSettled();
  delay(300);
  chassis.unlock();
  chassis.waitUntilSettled();
  chassis.turn({1671, -185},70,5).withTol(20).waitUntilSettled();
  chassis.withPoint({1500, -185}, 70, 12)
          .withPoint({2965, -195}, 70, 12)
          .withPoint({4900, -175}, 70, 12)
          .withConst(2).withTol(200).drive().waitUntilSettled();


          //score nine cube down

roller(0);
          LF.move(0);
          LB.move(127);
          RF.move(0);
          RB.move(127);
          delay(1100);
          LF.move(-100);
          LB.move(100);
          RF.move(-100);
          RB.move(100);
          delay(1200);

          chassis.left(50);
          chassis.right(50);
          rack.move(RACK_UP,127,5).withTol(20);
          roller(-0.4,50);


          delay(800);
          chassis.left(30);
          chassis.right(30);
          rack.waitUntilSettled();
          rack.move(RACK_DOWN,127,8).withTol(20);

          roller(-70);
          chassis.lock();
          chassis.drive(-500, 60, 10).withTol(60).waitUntilSettled();
          chassis.strafe(1800, 50).withSlop(-580).withTol(20).waitUntilSettled();

          chassis.left(-70);
          chassis.right(-70);
          delay(1100);
          roller(127);
          chassis.drive(4500, 70, 10).withTol(60).waitUntilSettled();
          chassis.strafe(-2000, 127).withSlop(0).withTol(20).waitUntilSettled();
          chassis.turn(270,50,4).withTol(8).waitUntilSettled();
          chassis.strafe(1000, 127).withSlop(0).withTol(20).waitUntilSettled();

          LF.move(127);
          LB.move(-127);
          RF.move(127);
          RB.move(-127);
          delay(1000);

          chassis.left(50);
          chassis.right(50);
          roller(-0.5,50);
          rack.move(RACK_UP,127,5).withTol(20);



          delay(400);
          chassis.left(30);
          chassis.right(30);
          rack.waitUntilSettled();
          rack.move(RACK_DOWN,127,8).withTol(20);

          roller(-70);
          chassis.lock();
          chassis.drive(-4150,127,2).withConst(0.2).withTol(50).waitUntilSettled();
          roller(127);
          LF.move(100);
          LB.move(-100);
          RF.move(100);
          RB.move(-100);
          delay(400);
          odom.reset(0);
          chassis.strafe(-1500,60,2).withTol(20).waitUntilSettled();
          roller(127);
          chassis.drive(1050,70,2).withConst(0.25).withTol(50).waitUntilSettled();
          delay(1000);
          arm.tower(2);
          delay(800);
          arm.move(1.5, 110);
          delay(500);
          chassis.drive(350,30,2).withConst(0.25).withTol(50).waitUntilSettled();
          roller(-80);
          delay(200);
          chassis.drive(-450,70,2).withConst(0.25).withTol(50).waitUntilSettled();
          delay(300);
          arm.zero();
          roller(127);
          chassis.turn(90,60,4).withConst(0.2).withTol(8).waitUntilSettled();
          chassis.left(-70);
          chassis.right(-70);
          delay(800);
          odom.reset(0);
          roller(127);
          chassis.drive(1900,70,4).withConst(0.2).withTol(50).waitUntilSettled();
          chassis.drive(-200,70,4).withConst(0.2).withTol(50).waitUntilSettled();

          arm.tower(1).waitUntilSettled();
          chassis.turn(25,60,4).withConst(0.2).withTol(8).waitUntilSettled();
          chassis.drive(100,70,4).withConst(0.8).withTol(50).waitUntilSettled();
          roller(-80);

            LF.move(0);
            LB.move(0);
            RF.move(0);
            RB.move(0);




}

void skills2() {

  odom.reset(0);
  chassis.tareGyro();
  arm.move(1.05, 127);
  delay(600);
  arm.zero();
  delay(600);
  arm.move(1.05, 127);
  chassis.lock();
  chassis.withPoint({50, 0}, 45, 5)
           .withPoint({700, -600}, 50, 5)
           .withConst(2).withTol(100).drive().waitUntilSettled();
  arm.waitUntilSettled();
   roller(-80);
   delay(600);
   roller(127);
   chassis.drive({100, 0}, 80, 6, true).withTol(60);
   delay(200);
   arm.zero().waitUntilSettled();
   chassis.waitUntilSettled();
   delay(100);
   chassis.lock();
   chassis.waitUntilSettled();
   chassis.turn({1671, -185},80,5).withTol(20).waitUntilSettled();
   chassis.withPoint({1500, -125}, 65, 12)
            .withPoint({2965, -175}, 65, 12)
            .withPoint({4350, -155}, 50, 12)
            .withConst(2).withTol(200).drive().waitUntilSettled();
            delay(600);
            arm.tower(1);
            delay(300);
   chassis.turn(90, 75,4).withoutOdom().withTol(4).waitUntilSettled();
   chassis.drive(150, 45).withGyro(90).withConst(0.6, 0.2).withTol(4).waitUntilSettled();
   roller(-80);
   delay(500);
   roller(80);
   chassis.drive(-150, 45).withGyro(90).withConst(0.6, 0.2).withTol(4).waitUntilSettled();
   arm.zero();
   chassis.unlock();
   chassis.turn(10, 75,4).withoutOdom().withTol(4).waitUntilSettled();
   delay(20);
   chassis.unlock();
   delay(20);
   chassis.drive(200, 127).withGyro(10).withConst(0.8).withTol(60).waitUntilSettled();
   roller(0);
   LF.move(0);
   LB.move(127);
   RF.move(0);
   RB.move(127);
   delay(1000);
   LF.move(-100);
   LB.move(100);
   RF.move(-100);
   RB.move(100);
   delay(500);
   rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
   delay(500);
   chassis.left(50);
   chassis.right(50);
   roller(-0.4,50);
   delay(800);
   chassis.left(30);
   chassis.right(30);
   rack.waitUntilSettled();
   rack.move(RACK_DOWN,127,8).withTol(20);
   roller(-70);
   chassis.lock();
   chassis.drive(-500, 90, 10).withTol(60).waitUntilSettled();
   chassis.strafe(1750, 75).withSlop(-580).withTol(20).waitUntilSettled();
   chassis.left(-70);
   chassis.right(-70);
   chassis.lock();
   delay(400);
   roller(127);
   chassis.drive(1800, 80, 10).withGyro(180).withTol(12).waitUntilSettled();
   delay(100);
   arm.tower(1);
   delay(400);
   chassis.unlock();
   chassis.turn(135, 50,4).withTol(4).withoutOdom().waitUntilSettled();
   chassis.drive(200, 50).withGyro(135).withConst(0.6, 0.2).withTol(4).waitUntilSettled();
   roller(-80);
   delay(500);
   roller(127);
   chassis.drive(-150, 50).withGyro(135).withConst(0.4, 0.2).withTol(5).waitUntilSettled();
   arm.zero();
   delay(200);
   chassis.turn(180, 55,4).withoutOdom().withTol(4).waitUntilSettled();
   chassis.drive(2600, 80, 10).withGyro(180).withTol(6).waitUntilSettled();
   chassis.strafe(-2500, 127).withSlop(0).withTol(20).waitUntilSettled();
   chassis.turn(90,70,4).withTol(8).withoutOdom().waitUntilSettled();
   chassis.strafe(1000, 127).withSlop(0).withTol(20).waitUntilSettled();
   LF.move(127);
   LB.move(-127);
   RF.move(127);
   RB.move(-127);
   delay(1000);
   chassis.left(50);
   chassis.right(50);
   roller(-0.5,50);
   rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
   delay(600);
   chassis.left(30);
   chassis.right(30);
   rack.waitUntilSettled();
   rack.move(RACK_DOWN,127,8).withTol(20);
   roller(-70);
   chassis.lock();
   chassis.drive(-4100,117,3).withConst(0.2).withTol(50).waitUntilSettled();
   roller(127);
   LF.move(100);
   LB.move(-100);
   RF.move(100);
   RB.move(-100);
   delay(400);
   odom.reset(0);
   chassis.strafe(-1350,60,2).withTol(20).waitUntilSettled();
   roller(127);
   chassis.drive(1050,80,2).withConst(0.25).withGyro(90).withTol(50).waitUntilSettled();
   delay(800);
   arm.tower(2);
   delay(700);
   arm.move(1.5, 110);
   delay(400);
   chassis.drive(430,30,2).withConst(0.25).withTol(50).waitUntilSettled();
   roller(-90);
   delay(300);
   chassis.drive(-550,75,2).withConst(0.25).withTol(50).waitUntilSettled();
   delay(300);
   arm.zero();
   roller(127);
   chassis.turn(0,60,4).withoutOdom().withTol(4).waitUntilSettled();
   odom.reset(0);
   roller(127);
   chassis.drive(1350,80,4).withGyro(0).withConst(0.2).withTol(50).waitUntilSettled();
   chassis.drive(-200,70,4).withGyro(0).withConst(0.2).withTol(50).waitUntilSettled();
   arm.tower(1).waitUntilSettled();
   chassis.turn(335,60,4).withoutOdom().withTol(4).waitUntilSettled();
   chassis.drive(200,85,4).withConst(0.8).withTol(50).waitUntilSettled();
   roller(-80);
   delay(400);
   chassis.drive(-300,127,10).withConst(0.8).withTol(50).waitUntilSettled();
   LF.move(0);
   LB.move(0);
   RF.move(0);
   RB.move(0);
}

void skills3() { // only run as a best case scenario auton
  odom.reset(0);
  chassis.tareGyro();
  arm.move(1.05, 127);
  delay(600);
  arm.zero();
  delay(600);
  arm.move(1.05, 127);
  chassis.lock();
  chassis.withPoint({50, 0}, 45, 5)
           .withPoint({700, -600}, 50, 5)
           .withConst(2).withTol(100).drive().waitUntilSettled();
  arm.waitUntilSettled();
   roller(-80);
   delay(600);
   roller(127);
   chassis.drive({100, 0}, 80, 6, true).withTol(60);
   delay(200);
     arm.zero().waitUntilSettled();
     chassis.waitUntilSettled();
     delay(100);
     chassis.unlock();
     chassis.waitUntilSettled();
     chassis.turn({1671, -185},80,5).withTol(20).waitUntilSettled();
     chassis.withPoint({1500, -185}, 70, 12)
              .withPoint({2965, -195}, 70, 12)
              .withPoint({4100, -175}, 50, 12)
              .withConst(2).withTol(220).drive().waitUntilSettled();
    delay(600);
    arm.tower(1);
    chassis.withoutOdom().turn(90, 75, 4).withTol(10).waitUntilSettled();
     chassis.drive(150, 45).withGyro(90).withConst(0.6, 0.2).withTol(4).waitUntilSettled();
     roller(-80);
     delay(500);
     roller(80);
     chassis.drive(-150, 45).withGyro(90).withConst(0.6, 0.2).withTol(4).waitUntilSettled();
     arm.zero();
     chassis.turn(10, 75,4).withoutOdom().withTol(4).waitUntilSettled();
     chassis.drive(200, 127).withGyro(10).withConst(0.6, 0.2).withTol(60).waitUntilSettled();
     roller(0);
     roller(0);
     LF.move(0);
     LB.move(127);
     RF.move(0);
     RB.move(127);
     delay(1000);
     LF.move(-100);
     LB.move(100);
     RF.move(-100);
     RB.move(100);
     delay(1000);
     chassis.left(50);
     chassis.right(50);
     rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
     roller(-0.4,50);
     delay(800);
     chassis.left(30);
     chassis.right(30);
     rack.waitUntilSettled();
     rack.move(RACK_DOWN,127,8).withTol(20);
     roller(-70);
     chassis.lock();
     chassis.drive(-500, 90, 10).withTol(60).waitUntilSettled();
     chassis.strafe(1750, 75).withSlop(-580).withTol(20).waitUntilSettled();
     chassis.left(-70);
     chassis.right(-70);
     delay(400);
     roller(127);
     chassis.drive(1800, 80, 10).withGyro(180).withTol(6).waitUntilSettled();
     delay(100);
     arm.tower(1);
     delay(400);
     chassis.turn(135, 50,4).withTol(4).withoutOdom().waitUntilSettled();
     chassis.drive(200, 50).withGyro(135).withConst(0.6, 0.2).withTol(4).waitUntilSettled();
     roller(-80);
     delay(500);
     roller(127);
     chassis.drive(-200, 50).withGyro(135).withConst(0.4, 0.2).withTol(5).waitUntilSettled();
     arm.zero();
     delay(200);
     chassis.turn(180, 55,4).withoutOdom().withTol(4).waitUntilSettled();
     chassis.drive(2600, 80, 10).withGyro(180).withTol(6).waitUntilSettled();
     chassis.strafe(-2500, 127).withSlop(0).withTol(20).waitUntilSettled();
     chassis.turn(90,70,4).withTol(8).withoutOdom().waitUntilSettled();
     chassis.strafe(1000, 127).withSlop(0).withTol(20).waitUntilSettled();
     LF.move(127);
     LB.move(-127);
     RF.move(127);
     RB.move(-127);
     delay(1000);
     chassis.left(50);
     chassis.right(50);
     roller(-0.5,50);
     rack.move(RACK_UP,127,7).withConst(0.1).withTol(30);
     delay(600);
     chassis.left(30);
     chassis.right(30);
     rack.waitUntilSettled();
     rack.move(RACK_DOWN,127,8).withTol(20);
     roller(-70);
     chassis.lock();
     chassis.drive(-4100,127,3).withConst(0.2).withTol(50).waitUntilSettled();
     roller(127);
     LF.move(100);
     LB.move(-100);
     RF.move(100);
     RB.move(-100);
     delay(400);
     odom.reset(0);
     chassis.strafe(-1350,60,2).withTol(20).waitUntilSettled();
     roller(127);
     chassis.drive(1050,80,2).withConst(0.25).withGyro(90).withTol(50).waitUntilSettled();
     delay(800);
     arm.tower(2);
     delay(700);
     arm.move(1.5, 110);
     delay(400);
     chassis.drive(450,30,2).withConst(0.25).withTol(50).waitUntilSettled();
     roller(-90);
     delay(300);
     chassis.drive(-550,75,2).withConst(0.25).withTol(50).waitUntilSettled();
     delay(300);
     arm.zero();
     roller(127);
     chassis.turn(0,60,4).withoutOdom().withTol(4).waitUntilSettled();

     roller(127);
     chassis.drive(900,80,4).withConst(0.2).withGyro(0).withTol(50).waitUntilSettled();
     chassis.drive(-200,70,4).withConst(0.2).withTol(50).waitUntilSettled();
     arm.tower(1).waitUntilSettled();
     chassis.turn(335,60,4).withoutOdom().withTol(4).waitUntilSettled();
     chassis.drive(300,85,4).withConst(0.8).withTol(50).waitUntilSettled();
     roller(-80);
     delay(400);
     chassis.drive(-400,127,10).withConst(0.8).withTol(50).waitUntilSettled();
     LF.move(0);
     LB.move(0);
     RF.move(0);
     RB.move(0);

}
