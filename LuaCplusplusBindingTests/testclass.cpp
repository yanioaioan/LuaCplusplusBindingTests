#include "testclass.h"

TestClass::TestClass(int _attribute, double x, double y, double z)
{
    attribute = _attribute;

    //set the ngl::vec3 values from within our program
    attributeVector.set(0.1,0.2,0.3);

    //or

    //set the ngl::vec3 values from our lua script and then back to it again
    attributeVector.set(x,y,z);
}

int TestClass::getAttribute()
{
    return attribute;
}


ngl::Vec3 TestClass::getAttributeVector()
{
    return attributeVector;
}

