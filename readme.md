Basically it's a transpiler from goosescript to c++.

Goosescript has only one rule: you cannot use characters from a-zA-Z. Any such characters must be replaced by an H followed by a number of S's corresponding to what character you want (or h and s's for lower case). So for example, if you wanted to write "Abc" it'd be "HShsshsss".

Following running it through the transpiler you'll have a c++ file which you can compile with whatever you want.

In theory you could use it for other languages too, but I didn't realize that it didn't have anything specific to c++ until after I made the file it outputs end in ".cc" and this being terriblehack I'm not going to change it because it just makes it all the terrible-er.