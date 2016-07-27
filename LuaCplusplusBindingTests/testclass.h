#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <ngl/NGLInit.h>
#include <ngl/Vec3.h>

class TestClass
{
public:
    TestClass(int _attribute,  double x, double y, double z);


    int attribute;
    int getAttribute();

    ngl::Vec3 attributeVector;
    ngl::Vec3 getAttributeVector();
    float * getArray();

};

#endif // TESTCLASS_H
