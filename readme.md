# lua-stdregex
```lua
local regex = require"regex"

--regex.ismatch(str, rgx)
print(regex.ismatch("abcd", "(a|b).[^j]\\D")) --true

--regex.find(str, rgx)
for k,v in pairs(regex.find("abd acd afd", "(?:a(?:b|c|f)d\\s?)+")) do
    print(k,v) --1       abd acd afd
end

--regex.replace(str, rgx, replaceOn)
print(regex.replace("test0 test1 test2","\\s",", ")) --test0, test1, test2

```
