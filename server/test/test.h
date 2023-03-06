#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "test/CTestObjectMovable.h"
#include "test/CTestObjectRotable.h"

#include "Move/CLinearMove.h"
#include "Rotate/CRotate.h"

#include "CExceptions.h"
#include <math.h>

class testMove : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(testMove);
    CPPUNIT_TEST(testMoveLinearVelocity);
    CPPUNIT_TEST(testMoveObjectWithInvalidPosition);
    CPPUNIT_TEST(testMoveObjectWithInvalidVelocity);
    CPPUNIT_TEST(testImpossibleChangePosition);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {
    }

    void tearDown() {
    }

private:

protected:

    void testMoveLinearVelocity(void) {
        //Для объекта, находящегося в точке (12, 5) и движущегося со скоростью (-7, 3) движение меняет положение объекта на (5, 8)
        CTestMovable obj = CTestMovable(CoordsVelocity(-7, 3));
        obj.setPosition(Coords(12,5));

        CLinearMove move = CLinearMove(obj);
        move.exec();

        CPPUNIT_ASSERT(obj.getPosition() == Coords(5, 8));
    }

    void testMoveObjectWithInvalidPosition(void) {
        //Попытка сдвинуть объект, у которого невозможно прочитать положение в пространстве, приводит к ошибке

        CTestMovable obj = CTestMovable(CoordsVelocity(-7, 3));
        CPPUNIT_ASSERT_THROW(obj.setPosition(Coords(CConfig::min_coord() - 1, 5)), position_coord_invalid);//положение вне рамок поля

        //код на проверку получения валидной позиции есть, но т.к. установить невалидную позицию нельзя, то она никогда и не считается
        //CPPUNIT_ASSERT_THROW(obj.getPosition(), position_coord_invalid);

        // соответственно, сдвинуть такой объект тоже не получится
        CLinearMove move = CLinearMove(obj);
        CPPUNIT_ASSERT_THROW(move.exec(), position_coord_invalid);//< min
    }

    void testMoveObjectWithInvalidVelocity(void){
        // Попытка сдвинуть объект, у которого невозможно прочитать значение мгновенной скорости, приводит к ошибке

        CTestMovable obj = CTestMovable(CoordsVelocity(CConfig::min_velocity() - 1, 3));//какая-то странная скорость
        obj.setPosition(Coords(12, 5));
        CLinearMove move = CLinearMove(obj);
        CPPUNIT_ASSERT_THROW(move.exec(), velocity_is_invalid);

        //OR
        obj = CTestMovable(CoordsVelocity(NULL, CConfig::max_velocity() + 1));
        obj.setPosition(Coords(12, 5));
        CPPUNIT_ASSERT_THROW(move.exec(), velocity_is_invalid);
    }

    void testImpossibleChangePosition(void){
        //Попытка сдвинуть объект, у которого невозможно изменить положение в пространстве, приводит к ошибке

        // если новая позиция выходит за рамки поля - позицию изменить невозможно - здесь будет итог координаты х ниже разрешенного значения (0)
        CTestMovable obj = CTestMovable(CoordsVelocity(-10, 3));
        obj.setPosition(Coords(7,5));

        CLinearMove move = CLinearMove(obj);

        CPPUNIT_ASSERT_THROW(move.exec(), position_coord_invalid);
    }
};

class testRotate : public CPPUNIT_NS::TestCase {
    CPPUNIT_TEST_SUITE(testRotate);
    CPPUNIT_TEST(testRotateNormal);
    CPPUNIT_TEST(testRotateWithZeroAngularSpeed);
    CPPUNIT_TEST(testRotateWithBigAngularSpeed);
    CPPUNIT_TEST(testRotateWithBigAngular);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {
    }

    void tearDown() {
    }

private:

protected:

    void testRotateNormal(void) {
        //Для объекта, находящегося в направлении (2) и движущегося с угловой скоростью (-7) поворот меняет направление объекта на (355) при direction_count=360
        CTestRotable obj = CTestRotable(-7);
        obj.setAngular(2);

        CRotate rotate = CRotate(obj);
        rotate.exec();

        CPPUNIT_ASSERT(obj.getAngular() == 355);
    }

    void testRotateWithZeroAngularSpeed(void) {
        //Для объекта, находящегося в направлении (2) и движущегося с угловой скоростью (0) поворот не меняет направление объекта
        CTestRotable obj = CTestRotable(0);
        obj.setAngular(2);

        CRotate rotate = CRotate(obj);
        rotate.exec();

        CPPUNIT_ASSERT(obj.getAngular() == 2);
    }

    void testRotateWithBigAngularSpeed(void) {
        //Для объекта, находящегося в направлении (2) и движущегося с угловой скоростью (500) поворот меняет направление объекта на (142) при direction_count=360
        CTestRotable obj = CTestRotable(500);
        obj.setAngular(2);

        CRotate rotate = CRotate(obj);
        rotate.exec();

        CPPUNIT_ASSERT(obj.getAngular() == 142);
    }

    void testRotateWithBigAngular(void) {
        //Для объекта, находящегося в направлении (500) и движущегося с угловой скоростью (-7) будет ошибка при задании поворота
        CTestRotable obj = CTestRotable(-7);

        CPPUNIT_ASSERT_THROW(obj.setAngular(500), angular_value_is_invalid);
    }
};
