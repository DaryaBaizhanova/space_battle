#include <iostream>
#include "test/CTestObjectMovable.h"
#include "test/CTestObjectRotable.h"
#include "Move/CLinearMove.h"
#include "Rotate/CRotate.h"

#ifdef TEST
    #include <cppunit/TestRunner.h>
    #include <cppunit/TestResult.h>
    #include <cppunit/TestResultCollector.h>
    #include <cppunit/extensions/HelperMacros.h>
    #include <cppunit/BriefTestProgressListener.h>
    #include <cppunit/extensions/TestFactoryRegistry.h>

    #include "test/test.h"

    CPPUNIT_TEST_SUITE_REGISTRATION(test);

#endif

using namespace std;

int main(int argc, char ** argv)
{
#ifdef TEST

    CPPUNIT_NS::TestResult controller;

    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);
    return result.wasSuccessful() ? 0 : 1;


#else
    try {
        CTestRotable obj = CTestRotable(-7);
        obj.setAngular(2);

        CRotate rotate = CRotate(obj);
        rotate.exec();

    } catch (std::logic_error err){
        std::cout << "any exc: " << err.what() << endl;
    }
#endif

    return 0;
}
