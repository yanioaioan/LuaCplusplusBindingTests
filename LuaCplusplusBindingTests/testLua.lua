print(string.format("Create a TestClass Object through Lua and\n I am going to print MEMBER VARIABLES by calling a MEMBER FUNCTIONS attribute\n"))

instance = TestClass.new(43, 1.8, 2.3 ,3.2)


function printAttribute(instance)
    local myattribute = instance:getAttribute()
    print(string.format("1st passed, attribute is: %d\n", myattribute))
end

printAttribute(instance)


function printAttributeVector(instance)
    local myattributeVector = instance:getAttributeVector()

    --a = {}    -- new array
    --for i=1, 1000 do
    --  a[i] = 0
    --end

    for i=1,3 do    --as ngl vec3 has 3 elements
        print(string.format("vector attribute is: %f", myattributeVector[i] ) )
    end

end

printAttributeVector(instance)

