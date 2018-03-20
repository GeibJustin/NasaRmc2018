/**
 * test_tfr_control.cpp
 * 
 * This is the main test class for the tfr_control package.
 */
#include <gtest/gtest.h>
#include "drivebase_publisher.h"

using tfr_control::DrivebasePublisher;

TEST(Control, Drivebase)
{
    // Google tests provide no handlers for exceptions
    try
    {
        const double WHEEL_RADIUS = 0.14605;
        const double WHEEL_SPAN = 0.9906;
        const double ABS_ERROR = 0.00005;
        double left_tread = 0;
        double right_tread = 0;

        DrivebasePublisher::twistToDifferential(0, 0, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_EQ(0, left_tread);
        EXPECT_EQ(0, right_tread);

        DrivebasePublisher::twistToDifferential(10, 0, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(68.46970216, left_tread, ABS_ERROR);
        EXPECT_NEAR(68.46970216, right_tread, ABS_ERROR);
        EXPECT_EQ(left_tread, right_tread);

        DrivebasePublisher::twistToDifferential(10, 3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(57.81591955, left_tread, ABS_ERROR);
        EXPECT_NEAR(79.12348477, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(2, 3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(3.040157823, left_tread, ABS_ERROR);
        EXPECT_NEAR(24.34772304, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(1.819346, 5.10293874, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(-4.848610462, left_tread, ABS_ERROR);
        EXPECT_NEAR(29.76262621, right_tread, ABS_ERROR);




        DrivebasePublisher::twistToDifferential(10, -3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(79.12348477, left_tread, ABS_ERROR);
        EXPECT_NEAR(57.81591955, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(2, -3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(24.3477230, left_tread, ABS_ERROR);
        EXPECT_NEAR(3.0401578234, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(1.819346, -5.10293874, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(29.76262621, left_tread, ABS_ERROR);
        EXPECT_NEAR(-4.848610462, right_tread, ABS_ERROR);



        DrivebasePublisher::twistToDifferential(-10, 3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(-79.12348477, left_tread, ABS_ERROR);
        EXPECT_NEAR(-57.81591955, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(-2, 3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(-24.3477230, left_tread, ABS_ERROR);
        EXPECT_NEAR(-3.0401578234, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(-1.819346, 5.10293874, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(-29.76262621, left_tread, ABS_ERROR);
        EXPECT_NEAR(4.848610462, right_tread, ABS_ERROR);


        DrivebasePublisher::twistToDifferential(-10, -3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(-57.81591955, left_tread, ABS_ERROR);
        EXPECT_NEAR(-79.12348477, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(-2, -3.1415, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(-3.0401578234, left_tread, ABS_ERROR);
        EXPECT_NEAR(-24.3477230, right_tread, ABS_ERROR);

        DrivebasePublisher::twistToDifferential(-1.819346, -5.10293874, WHEEL_RADIUS, 
                              WHEEL_SPAN, left_tread, right_tread);
        EXPECT_NEAR(4.848610462, left_tread, ABS_ERROR);
        EXPECT_NEAR(-29.76262621, right_tread, ABS_ERROR);

    }
    catch (std::exception e)
    {
        // An unhandled exception was thrown; fail the test
        ASSERT_TRUE(false);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
