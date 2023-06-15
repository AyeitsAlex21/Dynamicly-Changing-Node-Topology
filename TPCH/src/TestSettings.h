#ifndef TESTSETTINGS_H
#define TESTSETTINGS_H

// To use this comment the tests wanted

// GLOBAL_TEST should be defined when you want to test with the clients sending messages
// if undefined using a single server setting for a baseline

// POWER_TEST should be defined when wanting to do a power test can use in combination with
// global_test turning it off or on

// THROUGHPUT_TEST should be defined when wanting to conduct a throughput test can be used in combination
// with global test only when its defined, and NUM_STREAMS to determine the amount of streams for the test.

// MULTI CLIENT ORIG and NEW should be defined one or the other when swtiching between the old topolgies and the new ones

#define GLOBAL_TEST


//#define POWER_TEST

//#define THROUGHPUT_TEST
#define NUM_STREAMS 4

//#define MULTI_CLIENT_ORIG
#define MULTI_CLIENT_NEW

//#define MULTI_SERVER



#endif
