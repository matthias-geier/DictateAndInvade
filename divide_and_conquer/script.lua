-- script.lua
-- Receives a table, returns the sum of its components.
require("global");

io.write("The table the script received has:\n");
x = 0
for i = 1, #foo do
  print(i, foo[i])
  x = x + foo[i]
end
io.write("Returning data back to C " .. x .. "\n");
global.lfw.set_test_num(x);
return x