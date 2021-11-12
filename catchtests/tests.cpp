#include<catch.h>
#include<params_cpp.h>

using namespace params_cpp;

TEST_CASE("basic parser") {
    char *argv[] = {"program","param1","param2","param3"};
    Parser parser(4, argv);
    CHECK(parser.program == "program");
    CHECK(parser.get(0) == "param1");
    CHECK(parser.get(1) == "param2");
    CHECK(parser.get(2) == "param3");
}

TEST_CASE("basic keys") {
    char *argv[] = {"program", "-c", "param1", "-d", "param3"};
    Parser parser(5, argv);
    CHECK(parser.program == "program");
    CHECK(parser.get({"-c"}) == "param1");
    CHECK(parser.get({"-d"}) == "param3");
}


TEST_CASE("basic alias") {
    char *argv[] = {"program", "--command", "param1", "--DESTINATION", "param3"};
    Parser parser(5, argv);
    CHECK(parser.program == "program");
    CHECK(parser.get({"-c","--command"}) == "param1");
    CHECK(parser.get({"-d","--destination", "-D", "--DESTINATION"}) == "param3");
}



TEST_CASE("basic anon") {
    char *argv[] = {"program", "--command", "param1", "--DESTINATION", "param3", "anon"};
    Parser parser(6, argv);
    CHECK(parser.program == "program");
    CHECK(parser.get({"-c","--command"}) == "param1");
    CHECK(parser.get({"-d","--destination", "-D", "--DESTINATION"}) == "param3");
    CHECK(parser.get(0) == "anon");
}

