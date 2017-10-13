#!julia

println("const char ascii2str[][2] = {")
i = 1
for c in ' ':'~'
	if i % 10 ==0
		println("\t")
	end
	print("\"", c, "\", ")
	i += 1
end
println("}")
