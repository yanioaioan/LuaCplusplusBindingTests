print(string.format("Create a TestClass Object through Lua & I am going to print a member variable by calling a member function attribute\n"))

instance = TestClass.new(43)

function printAttribute(instance)
    local myattribute = instance:getAttribute()
    print(string.format("attribute is: %d\n", myattribute))
end

printAttribute(instance)
